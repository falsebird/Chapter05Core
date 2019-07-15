#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define WINDOS_NAME1 "[原始窗口图]"
#define WINDOS_NAME2 "[效果窗口图]"

int g_nContrastValue;//对比度值
int g_nBrightValue;//亮度值
Mat g_srcImage, g_dstImage;

void ContrastAndBright(int, void*) {

	for (int y = 0; y < g_srcImage.rows; y++) {
		for (int x = 0; x < g_srcImage.cols; x++) {
			for (int c = 0; c < 3; c++)
			{
				//应该先写行号，再写列号
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
		cout << "读取图片错误！ " << endl;
		return false;
	}
	namedWindow(WINDOS_NAME1, 1);
	imshow(WINDOS_NAME1, g_srcImage);
	namedWindow(WINDOS_NAME2, 1);
	createTrackbar("对比度：", WINDOS_NAME2, &g_nContrastValue, 300, ContrastAndBright);
	createTrackbar("亮  度：", WINDOS_NAME2, &g_nBrightValue, 200, ContrastAndBright);

	ContrastAndBright(g_nBrightValue, 0);
	ContrastAndBright(g_nContrastValue, 0);
	cout << endl << "\t运行成功，请调整滚动条观察图像效果\n\n" << "\t按下'q'键时，程序退出\n";
	while (char(waitKey(1)) != 'q') {}
	return 0;
}