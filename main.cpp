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
		std::cout << "Processing the No." << currentFrame << "֡ frame" << endl;
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
    Mat framex = imread(".\\ResultFrame\\1.png");
    Size size = Size(cap.get(cv::CAP_PROP_FRAME_WIDTH), cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps=cap.get(cv::CAP_PROP_FPS);
	VideoWriter writer;
    writer.open(".\\Result\\out.mp4", CAP_OPENCV_MJPEG, fps, size, true);
	string filename;
	Mat frame1;
    cout<<frame.size()<<endl;
	for (int i = 0; i <= totalFrameNumber-1; i++)
	{
		filename=".\\ResultFrame\\"+to_string(i)+".png";
		frame1 = imread(filename);
		if (frame1.empty())
			break;
		writer << frame1;
	}
    writer.release();
	std::cout << "write end!" << endl;
    system("pause");
}
