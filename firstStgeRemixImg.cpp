#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// -----------------------利用感兴趣区域实现图像叠加------------------
bool ROI_Addimage() {
	Mat srcImage1 = imread("img/dota_pa.jpg");
	Mat logoImage1 = imread("img/dota_logo.jpg");
	if (srcImage1.empty()) {
		cout << "读取srcImage错误~！" << endl;
		return false;
	}
	if (logoImage1.empty()) {
		cout << "读取logoImage错误~！" << endl;
		return false;
	}
	
	//两种添加感兴趣区域的方式
	Mat imageROI = srcImage1(Rect(200, 250, logoImage1.cols, logoImage1.rows));
	//Mat imageROI = srcImage1(Range(250, 250 + logoImage1.rows), Range(200, 200 + logoImage1.cols));
	Mat mask = imread("img/data_logo.jpg",0);
	logoImage1.copyTo(imageROI, mask);
	namedWindow("<1>利用ROI实现图像叠加窗口示例窗口");
	imshow("<1>利用ROI实现图像叠加窗口示例窗口",srcImage1);
	

}

//-------------------------线性混合操作---------------------
bool LinerBlening() {
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2 = imread("img/mogu.jpg");
	Mat srcImage3 = imread("img/rain.jpg");
	Mat dstImaga;
	if (srcImage2.empty()) {
		cout << "读取srcImage2错误~！" << endl;
		return false;
	}
	if (srcImage3.empty()) {
		cout << "读取srcImage3错误~！" << endl;
		return false;
	}

	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImaga);
	namedWindow("<2>线性混合示例窗口【原图】", 1);
	imshow("<2>线性混合示例窗口【原图】", srcImage2);
	namedWindow("<3>线性混合示例窗口【效果图】", 1);
	imshow("<3>线性混合示例窗口【效果图】", dstImaga);

}
//
bool ROI_LinearBlendig() {
	Mat srcImage4 = imread("img/dota_pa.jpg");
	Mat logoImage1 = imread("img/dota_logo.jpg");
	if (srcImage4.empty()) {
		cout << "读取srcImage错误~！" << endl;
		return false;
	}
	if (logoImage1.empty()) {
		cout << "读取logoImage错误~！" << endl;
		return false;
	}

	//两种添加感兴趣区域的方式
	Mat imageROI = srcImage4(Rect(150, 200, logoImage1.cols, logoImage1.rows));
	addWeighted(imageROI, 0.5, logoImage1, 0.3, 0., imageROI);
	namedWindow("<4>线性混合示例窗口【效果图】", 1);
	imshow("<4>线性混合示例窗口【效果图】", srcImage4);
}
//int main() {
//	//ROI_Addimage();
//	//LinerBlening();
//	ROI_LinearBlendig();
//	waitKey(0);
//	return 0;
//}