#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>
#include<boost/scoped_ptr.hpp>
using namespace std;
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

int main(int argc, char* argv [])
{
    init_handlers();
	VideoCapture cap("rtsp://192.168.0.100/axis-media/media.amp"); // open the axis camera
    if(!cap.isOpened()){  // check if we succeeded	
		printf("Unable to get camera.\n");
		return -1;
	}
	
	namedWindow("Camera Feed", CV_WINDOW_AUTOSIZE);

    Mat image;
    image.release();
	cap.read(image);
		
		//Settting up quadrantal points for crosshairs
		CvPoint top, bottom, left, right;
		top.y = 0;
		top.x = image.cols/2;
		bottom.y = image.rows;
		bottom.x = image.cols/2;
		left.y = image.rows/2;
		left.x = 0;
		right.y = image.rows/2;
		right.x = image.cols;

		//Adding crosshairs
		line(image, top, bottom, CV_RGB(255, 0, 0), 2);
		line(image, left, right, CV_RGB(255, 0, 0), 2);
    image_handler.set_image(image); 
    blue_ball_scorer.calculate_scores(blue_ball_finder.get_image());
    red_ball_scorer.calculate_scores(red_ball_finder.get_image());
    horiz_target_scorer.calculate_scores(horiz_target_finder.get_image());
    vert_target_scorer.calculate_scores(vert_target_finder.get_image());

    cout << "Report out for image " << 1 <<endl;

    report_scores(blue_ball_scorer, "Blue ball finder",image);
    report_scores(horiz_target_scorer,"Horizontal target finder",image);
    report_scores(vert_target_scorer, "Vertical target finder",image);
    report_scores(red_ball_scorer, "Red ball finder",image);
    imshow("Camera Feed",image);
    waitKey(0);
}

void report_scores(ScoreAnalyzer scorer,string findername,Mat image)
{
    vector<Score> scores=scorer.get_scores();
    cout << findername << " found " << scores.size() << " match(es)"<<endl;
    for(int i =0;i<scores.size();++i)
    {
        cout << "Match at: " << scores[i].position << endl;
        circle(image,scores[i].position,10,Scalar(255,0,255),2);
    }
}

void init_handlers()
{
    image_handler.add_observer(&red_ball_finder);
    image_handler.add_observer(&blue_ball_finder);
    image_handler.add_observer(&horiz_target_finder);
    image_handler.add_observer(&vert_target_finder);
}
