#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


//------------------��ͨ����Ϻ�����ʵ��------------------
bool BlueChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageBlueChannel;
	//-------------------��ͨ�������ɫ��������---------------
	//[1]����ͼƬ
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "��ȡlogoImage���� " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "��ȡsrcImage���� " << endl;
		return false;
	}

	//��2�������Ϊ������ͨ��ͼ��
	split(srcImage, channels);
	//��3����ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�����ߵȼ��޸�����һ����һ�����ű�


	imageBlueChannel = channels.at(0);
	//[4]��ԭͼ����ɫͨ���ģ�500��250���������·���һ�������logoImageͼ���м�Ȩ���������õ��Ļ�Ͻ���洢��ImageBlueChannel��
	addWeighted(imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageBlueChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]��������ͨ�����ºϲ�Ϊһ����ͨ��
	merge(channels, srcImage);
	imshow("[1]��Ϸԭ����logo��ɫͨ��", srcImage);
	//waitKey(0);
	return true;
}

//------------------��ͨ����Ϻ�����ʵ��------------------
bool GreenChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageGreenChannel;
	//-------------------��ͨ�������ɫɫ��������---------------
	//[1]����ͼƬ
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "��ȡlogoImage���� " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "��ȡsrcImage���� " << endl;
		return false;
	}

	//��2�������Ϊ������ͨ��ͼ��
	split(srcImage, channels);
	//��3����ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�����ߵȼ��޸�����һ����һ�����ű�


	imageGreenChannel = channels.at(1);
	//[4]��ԭͼ����ɫͨ���ģ�500��250���������·���һ�������logoImageͼ���м�Ȩ���������õ��Ļ�Ͻ���洢��ImageBlueChannel��
	addWeighted(imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageGreenChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]��������ͨ�����ºϲ�Ϊһ����ͨ��
	merge(channels, srcImage);
	imshow("[1]��Ϸԭ����logo��ɫͨ��", srcImage);
	//waitKey(0);
	return true;
}

//------------------��ͨ����Ϻ�����ʵ��------------------
bool RedChannelBleding() {
	Mat srcImage;
	Mat logoImage;
	vector<Mat> channels;
	Mat imageRedChannel;
	//-------------------��ͨ����Ϻ�ɫ��������---------------
	//[1]����ͼƬ
	logoImage = imread("img/dota_logo.jpg", 0);
	srcImage = imread("img/dota_jugg.jpg");
	if (logoImage.empty()) {
		cout << "��ȡlogoImage���� " << endl;
		return false;
	}
	if (srcImage.empty()) {
		cout << "��ȡsrcImage���� " << endl;
		return false;
	}

	//��2�������Ϊ������ͨ��ͼ��
	split(srcImage, channels);
	//��3����ԭͼ����ɫͨ�����÷��ظ�imageBlueChannel,ע�������ã��൱�����ߵȼ��޸�����һ����һ�����ű�


	imageRedChannel = channels.at(2);
	//[4]��ԭͼ����ɫͨ���ģ�500��250���������·���һ�������logoImageͼ���м�Ȩ���������õ��Ļ�Ͻ���洢��ImageBlueChannel��
	addWeighted(imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)),
		1.0,
		logoImage,
		0.5,
		0., 
		imageRedChannel(Rect(500, 250, logoImage.cols, logoImage.rows)));
	//[5]��������ͨ�����ºϲ�Ϊһ����ͨ��
	merge(channels, srcImage);
	imshow("[2]��Ϸԭ����logo��ɫͨ��", srcImage);
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