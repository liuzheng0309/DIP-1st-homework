#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void DFT(Mat img)
{
	int M = getOptimalDFTSize(img.rows);
	int N = getOptimalDFTSize(img.cols);
	Mat padded;
	copyMakeBorder(img, padded, 0, M - img.rows, 0, N - img.cols, BORDER_CONSTANT, Scalar::all(0));

	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexImg;
	merge(planes, 2, complexImg);

	dft(complexImg, complexImg);
}