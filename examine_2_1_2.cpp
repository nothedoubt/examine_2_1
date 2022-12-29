#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture video_1("O:\\preview.mp4");	//初始化视频对象

	Mat frame;					//每一帧的画面
	double fps;					//fps数据
	char fpsarray[10];			//储存fps数据的字符数组
	double t = 0;				//t为每一帧存在的时间，t的倒数即为fps
	namedWindow("视频");

	//循环读取每一帧连成视频			
	while (1)
	{
		t = (double)getTickCount();

		if (waitKey(1) == 27)break;	//停顿1ms，按下ESC键可结束播放
									//手动六十帧，这才是原速度（doge

		//if (waitKey(1000 / video.get(CAP_PROP_FPS) == 27)break;

		video_1 >> frame;			//读取当前画面

		if (frame.empty())break;	//播放完毕即退出循环
		

		t = ((double)getTickCount() - t) / getTickFrequency();
		fps = 1 / t;

		sprintf_s(fpsarray, "%.2f", fps);	//将fps数据保存为字符数组
		string FPS = "FPS:";
		FPS += fpsarray;					//将fps与名称连接

		putText			//将帧率信息打印在每一帧
		(
			frame,					//当前画面
			FPS,					//fps数据
			Point(5, 20),			//显示位置
			FONT_HERSHEY_SIMPLEX,	//文字字体
			0.5,					//文字大小
			Scalar(0, 255, 0)		//文字颜色
		);

		imshow("视频", frame);		//输出
	}
	video_1.release();		//释放对象

	return 0;
}