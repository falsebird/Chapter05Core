#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define WINDOS_NAME1 "[ԭʼ����ͼ]"
#define WINDOS_NAME2 "[Ч������ͼ]"

int g_nContrastValue;//�Աȶ�ֵ
int g_nBrightValue;//����ֵ
Mat g_srcImage, g_dstImage;

void ContrastAndBright(int, void*) {

	for (int y = 0; y < g_srcImage.rows; y++) {
		for (int x = 0; x < g_srcImage.cols; x++) {
			for (int c = 0; c < 3; c++)
			{
				//Ӧ����д�кţ���д�к�
				g_dstImage.at<Vec3b>(y, x)[c] = 
					saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
			}
		} 
	}

	imshow(WINDOS_NAME2, g_dstImage);
}


int main() {

	g_srcImage = imread("1.jpg");
	g_dstImage = imread("1.jpg");
	//imshow(WINDOS_NAME1, g_srcImage);
	//waitKey(0);
	if(g_srcImage.empty()) {
		cout << "��ȡͼƬ���� " << endl;
		return false;
	}
	namedWindow(WINDOS_NAME1, 1);
	imshow(WINDOS_NAME1, g_srcImage);
	namedWindow(WINDOS_NAME2, 1);
	createTrackbar("�Աȶȣ�", WINDOS_NAME2, &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("��  �ȣ�", WINDOS_NAME2, &g_nBrightValue, 200, ContrastAndBright);

	ContrastAndBright(g_nBrightValue, 0);
	ContrastAndBright(g_nContrastValue, 0);
	cout << endl << "\t���гɹ���������������۲�ͼ��Ч��\n\n" << "\t����'q'��ʱ�������˳�\n";
	while (char(waitKey(1)) != 'q') {}
	return 0;
}