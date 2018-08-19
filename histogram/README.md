# Histogram

### Histogram

- 주어진 이미지에서 각각의 밝기 (grayscale: 0~255)에 해당하는 픽셀이 몇 개인지를 표현하는 방법

- 히스토그램을 통하여 이미지의 contrast & brightness를 시각적으로 확인 가능

- 히스토그램 modification 과정을 통하여 Contrast & Brightness를 조정 가능

![ ](/images/histo_01.png)

### Histogram Modification

- 히스토그램에 따라 영상 대비 및 밝기 향상

- 히스토그램 모양과 범위에 집중

![ ](/images/histo_02.png)

- Histogram stretching / shrinking (normalize 함수)

![ ](/images/histo_03.png)

- Histogram sliding

![ ](/images/histo_04.png)

- Equalization: 입력 영상의 Contrast를 조정하여 좋은 Contrast로 만드는 연산

![ ](/images/histo_05.png)

- Equalization Algorithm (equalizeHist 함수)

  - 입력 영상의 히스토그램의 값을 누적시켜 히스토그램 누적합 계산
  
  - 히스토그램의 누적합을 전체 픽셀의 개수로 나누어 값을 정규화함
  
  - 정규화된 값에 최대gray level값을 곱한 후 반올림을 수행
  
  - 입력 영상의 각gray level에 대해 변환 값으로 대응시킴

![ ](/images/histo_06.png)

  
- 직접 구현한 소스와 OpenCV 함수 결과 비교

  - normalize

```
void normalize(Mat& image, Mat& dst, int range_min = 0, int range_max = 255) {
	image.copyTo(dst);
	double min = 0, max = 255;
	minMaxLoc(dst, &min, &max);
	int row = dst.rows, col = dst.cols;
	uchar* data = dst.ptr<uchar>(0);
	for (int i = 0; i < row * col; i++) {
		*data++ = (uchar)((((float)(range_max - range_min) / (float)(max - min)) * (float)(*data - min)) + range_min);
	}
}
```

  - equalizeHist
  
```
 void equalizeHist(Mat& src, Mat& dst, int nbins = 255) {
	src.copyTo(dst);
	int row = dst.rows, col = dst.cols;
	float* val = (float*)malloc(nbins * sizeof(float));
	memset(val, 0, nbins * sizeof(float));

	MatND hist = getHistogram(dst);
	float sum = 0;
	for (int i = 0; i < nbins; i++) {
		sum += hist.at<float>(i);
		*(val + i) = sum;
	}

	uchar getValue = 0;
	uchar* dst_data = dst.data;
	for (int j = 0; j < row * col; j++) {
		getValue = *(dst_data + j);
		*(dst_data + j) = (uchar)round((*(val + getValue) / sum) * nbins);
	}
	free(val);
}
```

![ ](/images/histo_07.png)
