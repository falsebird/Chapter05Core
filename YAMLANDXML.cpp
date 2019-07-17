#include<iostream>
#include<opencv2/opencv.hpp>
#include<time.h>

using namespace cv;
using namespace std;

bool writeYAML() {
	//��ʼ��
	FileStorage fs("test.yaml", FileStorage::WRITE);

	//��ʼ�ļ�д��
	fs << "frameCount" << 5;
	time_t rawtime; 
	
	time(&rawtime);
	//�������������洢ת�����
	struct tm timeTmp;
	char stTmp[32];//�洢���յ�ʱ����
	localtime_s(&timeTmp, &rawtime);//��õ�ǰʱ��
	asctime_s(stTmp, &timeTmp);//��ʱ���ʽ��
	fs << "calibrationDate" << stTmp;//���뵱ǰʱ��
	
	//asctime_s(localtime(&rawtime));
	//��ʼ������Mat����
	Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	Mat distCoeffs = (Mat_<double>(5, 1) << 0.1, 0.01, -0.001, 0, 0);
	//д�� �ļ�
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

	printf("\n�ļ���д��ϣ����ڹ���Ŀ¼�²鿴���ɵ��ļ�~");
	getchar();
	return true;
}


int main() {
	writeYAML();
	return 0;
}