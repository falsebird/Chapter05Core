#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


//------------------多通道混合函数的实现------------------
bool BlueChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageBlueChannel;
	//-------------------多通道混合蓝色分量部分---------------
	//[1]读入图片
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "读取logoImage错误！ " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "读取srcImage错误！ " << endl;
		return false;
	}

	//【2】将其分为三个单通道图像
	split(srcImage, channels);
	//【3】将原图的蓝色通道引用返回给imageBlueChannel,注意是引用，相当于两者等价修改其中一个另一个跟着变


	imageBlueChannel = channels.at(0);
	//[4]将原图的蓝色通道的（500，250）坐标右下方的一块区域和logoImage图进行加权操作，将得到的混合结果存储与ImageBlueChannel中
	addWeighted(imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]将三个单通道重新合并为一个三通道
	merge(channels, srcImage);
	imshow("[1]游戏原画加logo蓝色通道", srcImage);
	//waitKey(0);
	return true;
}

//------------------多通道混合函数的实现------------------
bool GreenChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageGreenChannel;
	//-------------------多通道混合绿色色分量部分---------------
	//[1]读入图片
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "读取logoImage错误！ " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "读取srcImage错误！ " << endl;
		return false;
	}

	//【2】将其分为三个单通道图像
	split(srcImage, channels);
	//【3】将原图的蓝色通道引用返回给imageBlueChannel,注意是引用，相当于两者等价修改其中一个另一个跟着变


	imageGreenChannel = channels.at(1);
	//[4]将原图的蓝色通道的（500，250）坐标右下方的一块区域和logoImage图进行加权操作，将得到的混合结果存储与ImageBlueChannel中
	addWeighted(imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]将三个单通道重新合并为一个三通道
	merge(channels, srcImage);
	imshow("[1]游戏原画加logo绿色通道", srcImage);
	//waitKey(0);
	return true;
}

//------------------多通道混合函数的实现------------------
bool RedChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageRedChannel;
	//-------------------多通道混合红色分量部分---------------
	//[1]读入图片
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "读取logoImage错误！ " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "读取srcImage错误！ " << endl;
		return false;
	}

	//【2】将其分为三个单通道图像
	split(srcImage, channels);
	//【3】将原图的蓝色通道引用返回给imageBlueChannel,注意是引用，相当于两者等价修改其中一个另一个跟着变


	imageRedChannel = channels.at(2);
	//[4]将原图的蓝色通道的（500，250）坐标右下方的一块区域和logoImage图进行加权操作，将得到的混合结果存储与ImageBlueChannel中
	addWeighted(imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]将三个单通道重新合并为一个三通道
	merge(channels, srcImage);
	imshow("[2]游戏原画加logo红色通道", srcImage);
	//waitKey(0);
	return true;
}


int main() {
	
	BlueChannelBleding();
	GreenChannelBleding();
	RedChannelBleding();
	waitKey(0);
	return 0;

}