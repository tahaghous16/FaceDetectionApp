#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>
#include <string>

using namespace std;
using namespace cv;


int main() {
	//Face Detetcion App:
	VideoCapture video(0);
	video.set(CAP_PROP_FRAME_HEIGHT, 480);
	video.set(CAP_PROP_FRAME_WIDTH, 640);
	
	CascadeClassifier faceDetect;
	faceDetect.load("C:/Users/DELL/Documents/opencv/build/etc/haarcascades/haarcascade_frontalface_default.xml");
	Mat img;
	while (true) {
		video.read(img);
		flip(img, img, 1);
		vector<Rect> faces;
		faceDetect.detectMultiScale(img, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
		}

		imshow("Frame", img);
		waitKey(1);
	}
}