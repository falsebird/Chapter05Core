#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// -----------------------���ø���Ȥ����ʵ��ͼ�����------------------
bool ROI_Addimage() {
	Mat srcImage1 = imread("img/dota_pa.jpg");
	Mat logoImage1 = imread("img/dota_logo.jpg");
	if (srcImage1.empty()) {
		cout << "��ȡsrcImage����~��" << endl;
		return false;
	}
	if (logoImage1.empty()) {
		cout << "��ȡlogoImage����~��" << endl;
		return false;
	}
	
	//������Ӹ���Ȥ����ķ�ʽ
	Mat imageROI = srcImage1(Rect(200, 250, logoImage1.cols, logoImage1.rows));
	//Mat imageROI = srcImage1(Range(250, 250 + logoImage1.rows), Range(200, 200 + logoImage1.cols));
	Mat mask = imread("img/data_logo.jpg",0);
	logoImage1.copyTo(imageROI, mask);
	namedWindow("<1>����ROIʵ��ͼ����Ӵ���ʾ������");
	imshow("<1>����ROIʵ��ͼ����Ӵ���ʾ������",srcImage1);
	

}

//-------------------------���Ի�ϲ���---------------------
bool LinerBlening() {
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2 = imread("img/mogu.jpg");
	Mat srcImage3 = imread("img/rain.jpg");
	Mat dstImaga;
	if (srcImage2.empty()) {
		cout << "��ȡsrcImage2����~��" << endl;
		return false;
	}
	if (srcImage3.empty()) {
		cout << "��ȡsrcImage3����~��" << endl;
		return false;
	}

	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImaga);
	namedWindow("<2>���Ի��ʾ�����ڡ�ԭͼ��", 1);
	imshow("<2>���Ի��ʾ�����ڡ�ԭͼ��", srcImage2);
	namedWindow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��", 1);
	imshow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��", dstImaga);

}
//
bool ROI_LinearBlendig() {
	Mat srcImage4 = imread("img/dota_pa.jpg");
	Mat logoImage1 = imread("img/dota_logo.jpg");
	if (srcImage4.empty()) {
		cout << "��ȡsrcImage����~��" << endl;
		return false;
	}
	if (logoImage1.empty()) {
		cout << "��ȡlogoImage����~��" << endl;
		return false;
	}

	//������Ӹ���Ȥ����ķ�ʽ
	Mat imageROI = srcImage4(Rect(150, 200, logoImage1.cols, logoImage1.rows));
	addWeighted(imageROI, 0.5, logoImage1, 0.3, 0., imageROI);
	namedWindow("<4>���Ի��ʾ�����ڡ�Ч��ͼ��", 1);
	imshow("<4>���Ի��ʾ�����ڡ�Ч��ͼ��", srcImage4);
}
//int main() {
//	//ROI_Addimage();
//	//LinerBlening();
//	ROI_LinearBlendig();
//	waitKey(0);
//	return 0;
//}