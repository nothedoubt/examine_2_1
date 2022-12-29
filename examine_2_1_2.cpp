#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture video_1("O:\\preview.mp4");	//��ʼ����Ƶ����

	Mat frame;					//ÿһ֡�Ļ���
	double fps;					//fps����
	char fpsarray[10];			//����fps���ݵ��ַ�����
	double t = 0;				//tΪÿһ֡���ڵ�ʱ�䣬t�ĵ�����Ϊfps
	namedWindow("��Ƶ");

	//ѭ����ȡÿһ֡������Ƶ			
	while (1)
	{
		t = (double)getTickCount();

		if (waitKey(1) == 27)break;	//ͣ��1ms������ESC���ɽ�������
									//�ֶ���ʮ֡�������ԭ�ٶȣ�doge

		//if (waitKey(1000 / video.get(CAP_PROP_FPS) == 27)break;

		video_1 >> frame;			//��ȡ��ǰ����

		if (frame.empty())break;	//������ϼ��˳�ѭ��
		

		t = ((double)getTickCount() - t) / getTickFrequency();
		fps = 1 / t;

		sprintf_s(fpsarray, "%.2f", fps);	//��fps���ݱ���Ϊ�ַ�����
		string FPS = "FPS:";
		FPS += fpsarray;					//��fps����������

		putText			//��֡����Ϣ��ӡ��ÿһ֡
		(
			frame,					//��ǰ����
			FPS,					//fps����
			Point(5, 20),			//��ʾλ��
			FONT_HERSHEY_SIMPLEX,	//��������
			0.5,					//���ִ�С
			Scalar(0, 255, 0)		//������ɫ
		);

		imshow("��Ƶ", frame);		//���
	}
	video_1.release();		//�ͷŶ���

	return 0;
}