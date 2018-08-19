#include <Windows.h>
#include "median.hpp"

using namespace cv;
using namespace std;

void startTimeCount(LARGE_INTEGER &Frequency, LARGE_INTEGER &BeginTime) {
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BeginTime);
}

String endTimeCount(LARGE_INTEGER &Frequency, LARGE_INTEGER &BeginTime, LARGE_INTEGER &Endtime) {
	QueryPerformanceCounter(&Endtime);
	return to_string((double)(Endtime.QuadPart - BeginTime.QuadPart) / (double)Frequency.QuadPart);
}

int main() {
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;
	String countTime;

	Mat image = imread("girl.png");
	cvtColor(image, image, COLOR_BGR2GRAY);
	imshow("Original image", image);

	startTimeCount(Frequency, BeginTime);
	Mat median_mat(image.size(), image.type());
	median_filter(image, median_mat);
	countTime = endTimeCount(Frequency, BeginTime, Endtime);
	putText(median_mat, countTime, Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 1, cvScalar(0, 0, 0));
	imshow("median_filter image", median_mat);

	startTimeCount(Frequency, BeginTime);
	Mat median_parallel(image.size(), image.type());
	parallel_for_(Range(1, image.rows - 1), Parallel_Median(image, median_parallel));
	countTime = endTimeCount(Frequency, BeginTime, Endtime);
	putText(median_parallel, countTime, Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 1, cvScalar(0, 0, 0));
	imshow("median_filter parallel image", median_parallel);
	
	startTimeCount(Frequency, BeginTime);
	Mat median_sse(image.size(), image.type());
	parallel_for_(Range(1, image.rows - 1), Parallel_Median_SSE(image, median_sse));
	countTime = endTimeCount(Frequency, BeginTime, Endtime);
	putText(median_sse, countTime, Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 1, cvScalar(0, 0, 0));
	imshow("median_filter parallel SSE image", median_sse);

	startTimeCount(Frequency, BeginTime);
	Mat median_blur(image.size(), image.type());
	medianBlur(image, median_blur, 3);
	countTime = endTimeCount(Frequency, BeginTime, Endtime);
	putText(median_blur, countTime, Point(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 1, cvScalar(0, 0, 0));
	imshow("medianBlur image", median_blur);
	waitKey();

	return 0;
}