#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>   

using namespace std;
using namespace cv;

int main()
{
	string VideoName;
	int FrameInterval;
	std::cout << "Please type the name of the video.";
	cin >> VideoName;
	VideoCapture cap(".\\Video\\"+VideoName);
	std::cout << "Please type How many frames are fetched every frame." << endl;
	cin >> FrameInterval;
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	std::cout << "total frames: " << totalFrameNumber << endl;
	
	Mat frame;
	bool flags = true;
	long currentFrame = 0;
	while (flags) 
	{
		
		cap.read(frame);

		stringstream str;
		str << "raw" << currentFrame << ".jpg";
		std::cout << "正在处理第" << currentFrame << "帧" << endl;
		printf("\n");
		imwrite(".\\Frame.\\" + str.str(), frame);
		if (currentFrame >= totalFrameNumber-1) {
			flags = false;
		}
		currentFrame++;
		
	}
	//char cmd[]="python process.py "+string(totalFrameNumber-1);
	string cmd = "python process.py " + to_string(totalFrameNumber-1);
	system(cmd.data());

	VideoWriter writer(".\\Result\\", CAP_OPENCV_MJPEG, 20, Size(320, 240), true);//Size要和图片尺寸保持一致
	char filename[50];
	Mat frame1;
	for (int i = 1; i <= totalFrameNumber-1; i++)
	{
		sprintf_s(filename, ".\\ResultFrame\\", i);
		frame1 = imread(filename);
		if (frame1.empty())
			break;
		writer << frame1;
	}
	std::cout << "write end!" << endl;
}