#include "ImageAnalyzer.hpp"
#include<string.h>
#include<opencv2/highgui/highgui.hpp>
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageObject.hpp"
#include "ImageGateway.hpp"
#include<csignal>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include <opencv/cv.h>
#include "NetTable.hpp"

using namespace std;
using namespace cv;

//the NetworkTable (table ID is set by default)
//NetworkTable * table = new NetworkTable();

ImageObject* red_ball = new RedBall();
ImageObject* blue_ball = new BlueBall();
ImageObject* horiz_target = new HorizHotTarget();
ImageObject* vert_target = new VertHotTarget();

bool read_image(Mat container, char* filename);
void report_scores(ScoreAnalyzer analyzer, char* findername);
void init_handlers();
int cameraEnabled(char** argv);
int cameraDisabled(char** argv);
void searchImage(ImageAnalyzer* analyzer, ScoreAnalyzer* scorer, Mat image);

int main(int argc, char** argv)
{
    if(argc>=2)
        return cameraDisabled(argv);
    return cameraEnabled(argv);
}

VideoCapture capture()
{

	VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp"); // open the axis camera
    if(!cap.isOpened()){  // check if we succeeded	
		printf("Unable to get camera.\n");
		return -1;
	}
    exit(0);
}

int cameraEnabled(char** argv)
{
    VideoCapture cap = capture();
    Mat image;
    ImageObject* object;
    ImageAnalyzer analyzer;
    ScoreAnalyzer scorer;
    if(strcmp(argv[1],"redball")==0){
        analyzer.set_object(red_ball);
        scorer.set_object(red_ball);
    }
    else if(strcmp(argv[1],"blueball")==0){
        analyzer.set_object(blue_ball);
        scorer.set_object(blue_ball);
    }
    else if(strcmp(argv[1],"verttarget")==0){
        analyzer.set_object(vert_target);
        scorer.set_object(vert_target);
    }
    else{
        analyzer.set_object(horiz_target);
        scorer.set_object(horiz_target);
    }

    cap.read(image);
    cvtColor(image, image, CV_BGR2HSV);
    analyzer.set_object(object);
    scorer.set_object(object);
    searchImage(&analyzer, &scorer, image);
    report_scores(scorer,argv[1]);
    return 0;
}

int cameraDisabled(char** argv)
{
    ImageAnalyzer analyzer;
    ScoreAnalyzer scorer;

    Mat imageBGR = imread(argv[2]);
    
    if(!imageBGR.data)
    {
        cout<<"Load fail"<<endl;
        return -1;
    }
    Mat image;
    cvtColor(imageBGR, image, CV_BGR2HSV);
    
    if(strcmp(argv[1],"redball")==0){
        analyzer.set_object(red_ball);
        scorer.set_object(red_ball);
    }
    else if(strcmp(argv[1],"blueball")==0){
        analyzer.set_object(blue_ball);
        scorer.set_object(blue_ball);
    }
    else if(strcmp(argv[1],"verttarget")==0){
        analyzer.set_object(vert_target);
        scorer.set_object(vert_target);
    }
    else{
        analyzer.set_object(horiz_target);
        scorer.set_object(horiz_target);
    }
    searchImage(&analyzer, &scorer, image);
    report_scores(scorer,argv[1]);
    return 0;
}

void searchImage(ImageAnalyzer* analyzer, ScoreAnalyzer* scorer, Mat image)
{
    analyzer->run_filter(image);
    scorer->calculate_scores(analyzer->get_image());
}

void report_scores(ScoreAnalyzer scorer,char* findername)
{
    vector<Score> scores=scorer.get_scores();

	if(scores.size() > 0){
    	cout << findername << " found " << scores.size() << " match(es)"<<endl;
	}else{
		cout << findername << " not found."	;
	}

	for(int i =0;i<scores.size();++i)
    {
        cout << "Match at: " << scores[i].position << endl;
    }
}
