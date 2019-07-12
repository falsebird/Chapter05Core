#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//ͨ�����ֱ������صķ�ʽ������ɫ�ʿռ�

//--------------------ʹ��ָ��---------------------------
void colorReduce1(Mat& inputImage, Mat& outputImage,int div ) {
	//����׼��
	outputImage = inputImage.clone();//����ʵ�ε���ʱ����
	int rowNumber = outputImage.rows;//����
	int colNumber = outputImage.cols * outputImage.channels(); //���� x =ͨ����*ÿһ��Ԫ�صĸ���
	//˫��ѭ�����������е�����ֵ
	for (int i = 0; i < rowNumber; i++){//��ѭ��
		uchar* data = outputImage.ptr<uchar>(i); //��ȡ��i�е��׵�ַ
		for (int j = 0; j < colNumber; j++) { //��ѭ��
			// ---------����ʼ����ÿ�����ء�-------------   
			data[j] = data[j] / div * div + div / 2;
			// ----------�����������---------------------
		}	//�д������
	}
}
//--------------------ʹ�õ�����---------------------------
void colorReduce2(Mat& inputImage, Mat& outputImage,int div ) {
	outputImage = inputImage.clone();//����ʵ�ε���ʱ����
	//��ȡ������
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//��ʼλ�õĵ�����
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//��ֹλ�õĵ�����
	//��ȡ��ɫͼ������
	for( ; it != itend; it++)
	{
		// ------------------------����ʼ����ÿ�����ء�--------------------
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
		// ------------------------�����������----------------------------
	}

}
//--------------------ʹ�ö�̬��ַ����---------------------------
void colorReduce3(Mat& inputImage, Mat& outputImage,int div ) {
	//����׼��
	outputImage = inputImage.clone();  //����ʵ�ε���ʱ����
	int rowNumber = outputImage.rows;  //����
	int colNumber = outputImage.cols;  //����

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			// ------------------------����ʼ����ÿ�����ء�--------------------
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;//��ɫͨ��
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;//��ɫͨ��
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;//����ͨ��
			// -------------------------�����������----------------------------
		}

	}
}
void testReudeceColor() {
	//��1������ԭʼͼ����ʾ
	Mat srcImage = imread("img/1.jpg");
	imshow("ԭʼͼ��", srcImage);
	//��2����ԭʼͼ�Ĳ����������������Ч��ͼ
	Mat dstImage1;
	dstImage1.create(srcImage.rows, srcImage.cols, srcImage.type());//Ч��ͼ�Ĵ�С��������ԭͼƬ��ͬ 
	Mat dstImage2;
	dstImage2.create(srcImage.rows, srcImage.cols, srcImage.type());
	Mat dstImage3;
	dstImage3.create(srcImage.rows, srcImage.cols, srcImage.type());
	//��3����¼��ʼʱ��
	double time0 = static_cast<double>(getTickCount());
	//��4��������ɫ�ռ���������
	colorReduce1(srcImage, dstImage1, 32);
	//��5����������ʱ�䲢���
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "��һ�ַ�������ʱ��Ϊ��" << time0 << "��" << endl;

	double time1 = static_cast<double>(getTickCount());

	colorReduce2(srcImage, dstImage2, 32);

	time1 = ((double)getTickCount() - time1) / getTickFrequency();
	cout << "�ڶ��ַ�������ʱ��Ϊ��" << time1 << "��" << endl;
	double time2 = static_cast<double>(getTickCount());

	colorReduce3(srcImage, dstImage3, 32);

	time2 = ((double)getTickCount() - time2) / getTickFrequency();
	cout << "�����ַ�������ʱ��Ϊ��" << time2 << "��" << endl;

	imshow("Ч��ͼ1", dstImage1);
	imshow("Ч��ͼ2", dstImage2);
	imshow("Ч��ͼ3", dstImage3);
	waitKey(0);
}

//int main() {
//	testReudeceColor();
//	return 0;
//}
