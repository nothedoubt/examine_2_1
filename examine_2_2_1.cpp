#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int h_max_value = 0, h_min_value = 0;
int s_max_value = 0, s_min_value = 0;
int v_max_value = 0, v_min_value = 0;

int main()
{
	Mat test_01 = imread("O:\\RM.png");

	namedWindow("hsv调节", WINDOW_AUTOSIZE);
	namedWindow("原图", WINDOW_AUTOSIZE);

	//创建跟踪栏
	createTrackbar("h-max", "hsv调节", &h_max_value, 180,0);
	createTrackbar("h-min", "hsv调节", &h_max_value, 180,0);
	createTrackbar("s-max", "hsv调节", &h_max_value, 255,0);
	createTrackbar("s-min", "hsv调节", &h_max_value, 255,0);
	createTrackbar("v-max", "hsv调节", &h_max_value, 255,0);
	createTrackbar("v-min", "hsv调节", &h_max_value, 255,0);

	imshow("原图", test_01);
	imshow("hsv调节", test_01);

	waitKey(0);
	return 0;
}