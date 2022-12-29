#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img, img_gray, img_dst_1, img_dst_2;

int threshold_value = 100;					//��ֵ
const int MAX_threshold = 255;				//��ֵ���ֵ

int threshold_type = 2;						//��ֵ������
const int MAX_THRESHOLD_TYPE = 4;			//��ֵ������ѡ������

void threshold_Demo(int, void*);			//�ص���������

int main()
{
	img = imread("O:\\RM.png");

	cvtColor(img, img_gray, COLOR_BGR2GRAY);			//ת����ɫ�ռ�ΪGRAY
	//namedWindow("�Ҷ�ͼ");
	//imshow("�Ҷ�ͼ", img_gray);						//����Ҷ�ͼ

	GaussianBlur(img, img_dst_1, Size(3 , 3), 0 , 0);	//��Ӹ�˹�˲�
	//namedWindow("����˲�");
	//imshow("����˲�", dst_1);						//�������˲����ͼ

	namedWindow("ת��ͼ��ֵ��", WINDOW_AUTOSIZE);
	createTrackbar("threshold", "ת��ͼ��ֵ��", &threshold_value, MAX_threshold, threshold_Demo);	//������ֵ������
	createTrackbar("type: ", "ת��ͼ��ֵ��", &threshold_type, MAX_THRESHOLD_TYPE, threshold_Demo);	//������ֵ�����͸�����

	threshold_Demo(0, 0);		//���ûص�����

	waitKey(0);
	return 0;
}

void threshold_Demo(int, void*)
{
	threshold(img_gray, img_dst_2, threshold_value, MAX_threshold, threshold_type);	//���±�������ж�ֵ��

	imshow("ת��ͼ��ֵ��", img_dst_2);
}
