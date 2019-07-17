#include<iostream>
#include<opencv2/opencv.hpp>
#include<time.h>

using namespace cv;
using namespace std;

bool writeYAML() {
	//初始化
	FileStorage fs("test.yaml", FileStorage::WRITE);

	//开始文件写入
	fs << "frameCount" << 5;
	time_t rawtime; 
	
	time(&rawtime);
	//定义两个变量存储转换结果
	struct tm timeTmp;
	char stTmp[32];//存储最终的时间结果
	localtime_s(&timeTmp, &rawtime);//获得当前时间
	asctime_s(stTmp, &timeTmp);//将时间格式化
	fs << "calibrationDate" << stTmp;//输入当前时间
	
	//asctime_s(localtime(&rawtime));
	//初始化两个Mat对象
	Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	Mat distCoeffs = (Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0);
	//写入 文件
	fs << "cameraMatrix" << cameraMatrix << "distCoeffs" << distCoeffs;

	fs << "features" << "[";
	for (int i = 0; i < 3; i++)
	{
		int x = rand() % 640;
		int y = rand() % 480;
		uchar lbp = rand() % 256;

		fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
		for (int j = 0; j < 8; j++)
			fs << ((lbp >> j) & 1);
		fs << "]" << "}";
	}
	fs << "]";
	fs.release();

	printf("\n文件读写完毕，请在工程目录下查看生成的文件~");
	getchar();
	return true;
}


int main() {
	writeYAML();
	return 0;
}