#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
	VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp"); // open the axis camera
    if(!cap.isOpened()){  // check if we succeeded	
		printf("Unable to get camera.\n");
		return -1;
	}
	
	namedWindow("Camera Feed", CV_WINDOW_AUTOSIZE);

    Mat frame;
	while(true){
		//Instantiating a mat to hold the current frame

        frame.release();
		//Reading in the current frame
		cap.read(frame);
		
		//Settting up quadrantal points for crosshairs
		CvPoint top, bottom, left, right;
		top.y = 0;
		top.x = frame.cols/2;
		bottom.y = frame.rows;
		bottom.x = frame.cols/2;
		left.y = frame.rows/2;
		left.x = 0;
		right.y = frame.rows/2;
		right.x = frame.cols;

		//Adding crosshairs
		line(frame, top, bottom, CV_RGB(255, 0, 0), 2);
		line(frame, left, right, CV_RGB(255, 0, 0), 2);

		//Displaying image + crosshairs
		imshow("Camera Feed", frame);

		if(waitKey(30) >= 0) break;
	}

	return 0;
}
