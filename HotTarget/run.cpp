#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageObject.hpp"
#include "ImageGateway.hpp"
#include<csignal>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include <opencv/cv.h>
using namespace std;
using namespace cv;

bool read_image(Mat container, char* filename);
void report_scores(ScoreAnalyzer analyzer, char* findername);
void init_handlers();
int cameraEnabled(char** argv);
int cameraDisabled(char** argv);
void constructObject(char* name,ImageObject* object);
void searchImage(ImageAnalyzer analyzer, ScoreAnalyzer scorer, Mat image);

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
    ImageAnalyzer analyzer(object);
    ScoreAnalyzer scorer(object);
    
    cap.read(image);
    constructObject(argv[1],object);
    searchImage(analyzer, scorer, image);
    delete object;
    report_scores(scorer,argv[1]);
    return 0;
}

int cameraDisabled(char** argv)
{
    Mat image;
    ImageObject* object;
    ImageAnalyzer analyzer(object);
    ScoreAnalyzer scorer(object);
    
    image = imread(argv[2],CV_LOAD_IMAGE_COLOR);
    constructObject(argv[1],object);
    searchImage(analyzer, scorer, image);
    cout<<"Here"<<endl;
    delete object;
    report_scores(scorer,argv[1]);
    return 0;
}

void constructObject(char* name,ImageObject* object)
{
    if(name=="redball")
        object = new RedBall();
    else if(name=="blueball")
        object = new BlueBall();
    else if(name=="verttarget")
        object = new VertHotTarget();
    else
        object = new HorizHotTarget();
}

void searchImage(ImageAnalyzer analyzer, ScoreAnalyzer scorer, Mat image)
{
    analyzer.run_filter(image);
    scorer.calculate_scores(analyzer.get_image());
}

void report_scores(ScoreAnalyzer scorer,char* findername)
{
    vector<Score> scores=scorer.get_scores();
    cout << findername << " found " << scores.size() << " match(es)"<<endl;
    for(int i =0;i<scores.size();++i)
    {
        cout << "Match at: " << scores[i].position << endl;
    }
}
