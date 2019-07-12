#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//通过三种遍历像素的方式来减少色彩空间

//--------------------使用指针---------------------------
void colorReduce1(Mat& inputImage, Mat& outputImage,int div ) {
	//参数准备
	outputImage = inputImage.clone();//拷贝实参到临时变量
	int rowNumber = outputImage.rows;//行数
	int colNumber = outputImage.cols * outputImage.channels(); //列数 x =通道数*每一行元素的个数
	//双重循环，遍历所有的像素值
	for (int i = 0; i < rowNumber; i++){//行循环
		uchar* data = outputImage.ptr<uchar>(i); //获取第i行的首地址
		for (int j = 0; j < colNumber; j++) { //列循环
			// ---------【开始处理每个像素】-------------   
			data[j] = data[j] / div * div + div / 2;
			// ----------【处理结束】---------------------
		}	//行处理结束
	}
}
//--------------------使用迭代器---------------------------
void colorReduce2(Mat& inputImage, Mat& outputImage,int div ) {
	outputImage = inputImage.clone();//拷贝实参到临时变量
	//获取迭代器
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//初始位置的迭代器
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//终止位置的迭代器
	//存取彩色图像像素
	for( ; it != itend; it++)
	{
		// ------------------------【开始处理每个像素】--------------------
		(*it)[0] = (*it)[0] / div * div + div / 2;
		(*it)[1] = (*it)[1] / div * div + div / 2;
		(*it)[2] = (*it)[2] / div * div + div / 2;
		// ------------------------【处理结束】----------------------------
	}

}
//--------------------使用动态地址计算---------------------------
void colorReduce3(Mat& inputImage, Mat& outputImage,int div ) {
	//参数准备
	outputImage = inputImage.clone();  //拷贝实参到临时变量
	int rowNumber = outputImage.rows;  //行数
	int colNumber = outputImage.cols;  //列数

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			// ------------------------【开始处理每个像素】--------------------
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;//蓝色通道
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;//绿色通道
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;//红是通道
			// -------------------------【处理结束】----------------------------
		}

	}
}
void testReudeceColor() {
	//【1】创建原始图并显示
	Mat srcImage = imread("img/1.jpg");
	imshow("原始图像", srcImage);
	//【2】按原始图的参数规格来创建创建效果图
	Mat dstImage1;
	dstImage1.create(srcImage.rows, srcImage.cols, srcImage.type());//效果图的大小、类型与原图片相同 
	Mat dstImage2;
	dstImage2.create(srcImage.rows, srcImage.cols, srcImage.type());
	Mat dstImage3;
	dstImage3.create(srcImage.rows, srcImage.cols, srcImage.type());
	//【3】记录起始时间
	double time0 = static_cast<double>(getTickCount());
	//【4】调用颜色空间缩减函数
	colorReduce1(srcImage, dstImage1, 32);
	//【5】计算运行时间并输出
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "第一种方法运行时间为：" << time0 << "秒" << endl;

	double time1 = static_cast<double>(getTickCount());

	colorReduce2(srcImage, dstImage2, 32);

	time1 = ((double)getTickCount() - time1) / getTickFrequency();
	cout << "第二种方法运行时间为：" << time1 << "秒" << endl;
	double time2 = static_cast<double>(getTickCount());

	colorReduce3(srcImage, dstImage3, 32);

	time2 = ((double)getTickCount() - time2) / getTickFrequency();
	cout << "第三种方法运行时间为：" << time2 << "秒" << endl;

	imshow("效果图1", dstImage1);
	imshow("效果图2", dstImage2);
	imshow("效果图3", dstImage3);
	waitKey(0);
}

//int main() {
//	testReudeceColor();
//	return 0;
//}
