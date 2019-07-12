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
int main() {
	ROI_Addimage();
	waitKey(0);
	return 0;
}