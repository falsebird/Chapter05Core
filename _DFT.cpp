#include<iostream>
#include<opencv2/opencv.hpp>

using	 namespace cv;
using	 namespace std;

bool _Dft() {
	//��1����ȡͼ��
	Mat srcImage = imread("11.jpg", 0);//�ԻҶ�ģʽ��ȡԭʼͼ����ʾ
	if (srcImage.empty()) {
		cout << "��ȡͼƬ���󣡣�~~" << endl;
		return false;
	}
	//��2����չͼ����ڽ��и���Ҷ�任��2 3 5 �ı��� �߽���0����
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	//����ӵ����س�ʼ��Ϊ0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, );



}

int  main() {
	
	
	return 0;
}