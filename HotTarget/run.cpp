#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageObject.hpp"
#include "ImageGateway.hpp"
#include<signal.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include <opencv/cv.h>
using namespace std;
using namespace cv;
ImageObject* red_ball = new RedBall();
ImageObject* blue_ball = new BlueBall();
ImageObject* horiz_target = new HorizHotTarget();
ImageObject* vert_target = new VertHotTarget();

ImageAnalyzer red_ball_finder(red_ball);
ImageAnalyzer blue_ball_finder(blue_ball);
ImageAnalyzer horiz_target_finder(horiz_target);
ImageAnalyzer vert_target_finder(vert_target);

ScoreAnalyzer red_ball_scorer(red_ball);
ScoreAnalyzer blue_ball_scorer(blue_ball);
ScoreAnalyzer horiz_target_scorer(horiz_target);
ScoreAnalyzer vert_target_scorer(vert_target);

ImageGateway image_handler;

bool read_image(Mat container, string filename);
void report_scores(ScoreAnalyzer analyzer,string findername,Mat image);
void init_handlers();

void handle(sig_t sig)
{
    delete red_ball;
    delete blue_ball;
    delete horiz_target;
    delete vert_target;
}

#ifndef NO_CAMERA
int main(int argc, char* argv [])
{
    init_handlers();
	VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp"); // open the axis camera
    if(!cap.isOpened()){  // check if we succeeded	
		printf("Unable to get camera.\n");
		return -1;
	}
	
    Mat imageBGR;
    #ifndef DEBUG_ON
    for(;;){
    #endif
    imageBGR.release();
	cap.read(imageBGR);
    #ifdef DEBUG_ON
    imwrite("DEBUG.jpg",imageBGR);
    #endif
    Mat image;
    cvtColor(imageBGR,image,CV_BGR2HSV);
		
    image_handler.set_image(image); 
    blue_ball_scorer.calculate_scores(blue_ball_finder.get_image());
    red_ball_scorer.calculate_scores(red_ball_finder.get_image());
    horiz_target_scorer.calculate_scores(horiz_target_finder.get_image());
    vert_target_scorer.calculate_scores(vert_target_finder.get_image());

    report_scores(blue_ball_scorer, "Blue ball finder",imageBGR);
    report_scores(horiz_target_scorer,"Horizontal target finder",imageBGR);
    report_scores(vert_target_scorer, "Vertical target finder",imageBGR);
    report_scores(red_ball_scorer, "Red ball finder",imageBGR);

    #ifdef DEBUG_ON
    namedWindow("ex",WINDOW_AUTOSIZE);
    imshow("ex",imageBGR);
    waitKey(0);
    #endif

    #ifndef DEBUG_ON
    }
    #endif

    delete red_ball;
    delete blue_ball;
    delete horiz_target;
    delete vert_target;
    
}
#endif
#ifdef NO_CAMERA
int main(int argc,char*argv[])
{
    Mat image;
    image =imread(argv[1],CV_LOAD_IMAGE_COLOR);
    cvtColor(image,image,CV_BGR2HSV);
    horiz_target_finder.run_filter(image);
    vert_target_finder.run_filter(image);
    horiz_target_scorer.calculate_scores(horiz_target_finder.get_image());
    vert_target_scorer.calculate_scores(vert_target_finder.get_image());
    report_scores(horiz_target_scorer,"horiz target finder",image);
    report_scores(vert_target_scorer,"vert target finder",image);
    cvtColor(image,image,CV_HSV2BGR);
    delete red_ball;
    delete blue_ball;
    delete horiz_target;
    delete vert_target;
}
#endif

void report_scores(ScoreAnalyzer scorer,string findername,Mat image)
{
    vector<Score> scores=scorer.get_scores();
    cout << findername << " found " << scores.size() << " match(es)"<<endl;
    for(int i =0;i<scores.size();++i)
    {
        cout << "Match at: " << scores[i].position << endl;
        cout << "Distance: " << scores[i].distance << endl;
        circle(image,scores[i].position,10,Scalar(255,100,100),2);
    }
}

void init_handlers()
{
    image_handler.add_observer(&red_ball_finder);
    image_handler.add_observer(&blue_ball_finder);
    image_handler.add_observer(&horiz_target_finder);
    image_handler.add_observer(&vert_target_finder);
}
