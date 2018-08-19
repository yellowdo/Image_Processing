#include <opencv2/opencv.hpp>
#include "histo.hpp"

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("ex_2.PNG", IMREAD_GRAYSCALE);

    imshow("Original IMAGE", image);
    imshow("Histo IMAGE", createHistImage(getHistogram(image)));

	// OpenCV 라이브러리
	Mat eq_norm(image.size(), image.type());
	normalize(image, eq_norm, 0, 255, NORM_MINMAX);
	imshow("OpenCV normalize", eq_norm);
	imshow("Histo OpenCV normalize", createHistImage(getHistogram(eq_norm)));

	// 직접구현한 normalize
    Mat eq(image.size(), image.type());
	CustomCV::normalize(image, eq, 0, 255);
    imshow("Custom normalize", eq);
    imshow("Histo Custom normalize", createHistImage(getHistogram(eq)));
		
	// OpenCV 라이브러리
    Mat eqHist(image.size(), image.type());
    equalizeHist(image, eqHist);
    imshow("OpenCV equalizeHist", eqHist);
    imshow("Histo OpenCV equalizeHist", createHistImage(getHistogram(eqHist)));

	// 직접구현한 equalizeHist
    Mat eq_equalization(image.size(), image.type());
	CustomCV::equalizeHist(image, eq_equalization);
    imshow("Custom equalizeHist", eq_equalization);
    imshow("Histo Custom equalizeHist", createHistImage(getHistogram(eq_equalization)));

    waitKey();
    return 0;
}