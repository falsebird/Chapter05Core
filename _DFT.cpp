#include<iostream>
#include<opencv2/opencv.hpp>

using	 namespace cv;
using	 namespace std;

bool _Dft() {
	//【1】读取图像
	Mat srcImage = imread("11.jpg", 0);//以灰度模式读取原始图像并显示
	if (srcImage.empty()) {
		cout << "读取图片错误！！~~" << endl;
		return false;
	}
	//【2】延展图像便于进行傅里叶变换，2 3 5 的倍数 边界用0补充
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	//将添加的像素初始化为0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, );



}

int  main() {
	
	
	return 0;
}