#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, img_gray, img_dst_1, img_dst_2;

int threshold_value = 100;					//阈值
const int MAX_threshold = 255;				//阈值最大值

int threshold_type = 2;						//阈值化类型
const int MAX_THRESHOLD_TYPE = 4;			//阈值化类型选项上限

void threshold_Demo(int, void*);			//回调函数声明

int main()
{
	img = imread("O:\\RM.png");

	cvtColor(img, img_gray, COLOR_BGR2GRAY);			//转换颜色空间为GRAY
	//namedWindow("灰度图");
	//imshow("灰度图", img_gray);						//输出灰度图

	GaussianBlur(img, img_dst_1, Size(3 , 3), 0 , 0);	//添加高斯滤波
	//namedWindow("添加滤波");
	//imshow("添加滤波", dst_1);						//输出添加滤波后的图

	namedWindow("转换图二值化", WINDOW_AUTOSIZE);
	createTrackbar("threshold", "转换图二值化", &threshold_value, MAX_threshold, threshold_Demo);	//创建阈值跟踪栏
	createTrackbar("type: ", "转换图二值化", &threshold_type, MAX_THRESHOLD_TYPE, threshold_Demo);	//创建阈值化类型跟踪栏

	threshold_Demo(0, 0);		//调用回调函数

	waitKey(0);
	return 0;
}

void threshold_Demo(int, void*)
{
	threshold(img_gray, img_dst_2, threshold_value, MAX_threshold, threshold_type);	//更新变量后进行二值化

	imshow("转换图二值化", img_dst_2);
}
