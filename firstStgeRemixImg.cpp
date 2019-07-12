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
int main() {
	ROI_Addimage();
	waitKey(0);
	return 0;
}