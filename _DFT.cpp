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
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));

	//【3】为傅里叶变换的结果（实部和虚部）分配存储空间。
	//将planes数组组合合并成一个多通道的数组complexI
	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	//【4】就地进行傅里叶变换
	dft(complexI, complexI);

	//【5】将复数转化为幅值，即=> log(sqrt(Re(DFT(I)^2 + Im(DFT(1))^2))
	split(complexI, planes);//将多通道数组comloexI分离成多个单通道数组 planes[0] =Re(DFT(1), planes[1]=Im(DFT(I))
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];

	//【6】进行尺度logarithmic scale 缩放
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);//求自然对数

	//【7】剪切和重新分布幅度图象限
	//若有奇数行或者奇数列，进行频谱裁剪
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols & -2, magnitudeImage.rows & -2));
	//重新排列傅里叶图像中的象限，使得原点位于图像中心
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;
	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));//ROI区域的左上
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));//ROI区域的右上
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));//ROI区域的左上
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy));//ROI区域的右下
	//交换象限（左上与右下进行交换）
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);
	//交换象限（右上与左下进行交换）
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);
	//【8】归一化，用0到1之间的浮点值矩阵变换为可视的图像格式
	normalize(magnitudeImage, magnitudeImage, 0, 1, NORM_MINMAX);

	imshow("频谱幅值", magnitudeImage);
	waitKey();
	return true;

}

int  main() {
	_Dft();
	
	return 0;
}