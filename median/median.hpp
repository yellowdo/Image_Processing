#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// 내림차순 버블 정렬
static inline void bubble_asc(uchar *a, int size) {
	uchar temp;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (*(a + j) < *(a + j + 1)) {
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
			}
		}
	}
}



static inline void median_filter_col (uchar* ptr, uchar* ptr_dst, uchar* val, int col, int channel) {
	for (int i = 1; i < col - 1; i++) {
		for (int j = 0; j < channel; j++) {
			*val = *(ptr - (col * channel) - channel + j);
			*(val + 1) = *(ptr - (col * channel) + j);
			*(val + 2) = *(ptr - (col * channel) + channel + j);
			*(val + 3) = *(ptr - channel + j);
			*(val + 4) = *(ptr + j);
			*(val + 5) = *(ptr + channel + j);
			*(val + 6) = *(ptr + (col * channel) - channel + j);
			*(val + 7) = *(ptr + (col * channel) + j);
			*(val + 8) = *(ptr + (col * channel) + channel + j);
			bubble_asc(val, 9);
			*(ptr_dst + j) = *(val + 4);
		}
		ptr += channel;
		ptr_dst += channel;
	}
}

static inline void median_filter(Mat &src, Mat &dst) {
	int row = src.rows;
	int col = src.cols;
	int step = (int)src.step1();
	int channel = src.channels();
	int size = 9 * (row - 2);
	uchar* ptr = src.ptr<uchar>(0, 0);
	uchar* ptr_dst = dst.ptr<uchar>(0, 0);
	uchar* val = (uchar*)malloc(size * sizeof(uchar));
	memset(val, 0, size * sizeof(uchar));
	for (int i = 1; i < row - 1; i++) {
		median_filter_col(
			ptr + (step * i),
			ptr_dst + (step * i),
			val + (9 * (i - 1)), col, channel);
	}
	free(val);
}

// 병렬 처리를 위한 클래스
class Parallel_Median : public ParallelLoopBody {
private:
	Mat & src, &dst;
public:
	Parallel_Median(Mat &_src, Mat& _dst) : src(_src), dst(_dst) {}
	virtual void operator()(const Range &r) const {
		// 속도를 위해 포인터 주소로 데이터 접근
		int row = src.rows;
		int col = src.cols;
		int step = (int)src.step1();
		int channel = src.channels();
		int size = 9 * (row - 2);
		uchar* ptr = src.ptr<uchar>(0, 0);
		uchar* ptr_dst = dst.ptr<uchar>(0, 0);
		uchar* val = (uchar*)malloc(size * sizeof(uchar));
		memset(val, 0, size * sizeof(uchar));
		for (int i = r.start; i < r.end; i++) {
			median_filter_col(
				ptr + (step * i),
				ptr_dst + (step * i),
				val + (9 * (i - 1)), col, channel);
		}
		free(val);
	}
};

class Parallel_Median_SSE : public ParallelLoopBody {
private:
	Mat & src, &dst;
public:
	Parallel_Median_SSE(Mat &_src, Mat& _dst) : src(_src), dst(_dst) {}

	static inline void Sort(__m128i& a, __m128i& b) {
		__m128i t = a;
		a = _mm_min_epu8(t, b);
		b = _mm_max_epu8(t, b);
	}
	static inline void Sort(__m128i a[9]) {
		Sort(a[1], a[2]); Sort(a[4], a[5]); Sort(a[7], a[8]);
		Sort(a[0], a[1]); Sort(a[3], a[4]); Sort(a[6], a[7]);
		Sort(a[1], a[2]); Sort(a[4], a[5]); Sort(a[7], a[8]);
		Sort(a[0], a[3]); Sort(a[5], a[8]); Sort(a[4], a[7]);
		Sort(a[3], a[6]); Sort(a[1], a[4]); Sort(a[2], a[5]);
		Sort(a[4], a[7]); Sort(a[4], a[2]); Sort(a[6], a[4]);
		Sort(a[4], a[2]);
	}
	virtual void operator()(const Range &r) const {
		int row = src.rows, col = src.cols, channel = src.channels();
		size_t step = src.step1();
		uchar* ptr = src.ptr<uchar>(0, 0);
		uchar* ptr_dst = dst.ptr<uchar>(0, 0);
		for (int i = r.start; i < r.end; i++) {
			__m128i a[9];
			for (size_t x = 0; x < (col - 1) - sizeof(__m128i); x += sizeof(__m128i)) {
				a[0] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) - step - 1 + x));
				a[1] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) - step + x));
				a[2] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) - step + 1 + x));
				a[3] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) - 1 + x));
				a[4] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) + x));
				a[5] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) + 1 + x));
				a[6] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) + step - 1 + x));
				a[7] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) + step + x));
				a[8] = _mm_loadu_si128((const __m128i*)(ptr + (step * i) + step + 1 + x));
				Sort(a);
				_mm_storeu_si128((__m128i*)(ptr_dst + (step * i) + x), a[4]);
			}
		}
	}
};