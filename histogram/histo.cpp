#include <opencv2/opencv.hpp>
#include "histo.hpp"

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("ex_2.PNG", IMREAD_GRAYSCALE);

    imshow("Original IMAGE", image);
    imshow("Histo IMAGE", createHistImage(getHistogram(image)));

	// OpenCV ���̺귯��
	Mat eq_norm(image.size(), image.type());
	normalize(image, eq_norm, 0, 255, NORM_MINMAX);
	imshow("OpenCV normalize", eq_norm);
	imshow("Histo OpenCV normalize", createHistImage(getHistogram(eq_norm)));

	// ���������� normalize
    Mat eq(image.size(), image.type());
	CustomCV::normalize(image, eq, 0, 255);
    imshow("Custom normalize", eq);
    imshow("Histo Custom normalize", createHistImage(getHistogram(eq)));
		
	// OpenCV ���̺귯��
    Mat eqHist(image.size(), image.type());
    equalizeHist(image, eqHist);
    imshow("OpenCV equalizeHist", eqHist);
    imshow("Histo OpenCV equalizeHist", createHistImage(getHistogram(eqHist)));

	// ���������� equalizeHist
    Mat eq_equalization(image.size(), image.type());
	CustomCV::equalizeHist(image, eq_equalization);
    imshow("Custom equalizeHist", eq_equalization);
    imshow("Histo Custom equalizeHist", createHistImage(getHistogram(eq_equalization)));

    waitKey();
    return 0;
}