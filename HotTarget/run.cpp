#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>

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
void report_scores(ScoreAnalyzer analyzer,string findername);
void init_handlers();

int main(int argc, char* argv [])
{
    for(int i=1;i<argc;++i)
    {
        namedWindow("initial image",WINDOW_AUTOSIZE);
        init_handlers();
        Mat image = imread(argv[i],CV_LOAD_IMAGE_COLOR);
        imshow("initial image",image);
        image_handler.set_image(image); 
        waitKey(0);
        blue_ball_scorer.calculate_scores(blue_ball_finder.get_image());
        red_ball_scorer.calculate_scores(red_ball_finder.get_image());
        horiz_target_scorer.calculate_scores(horiz_target_finder.get_image());
        vert_target_scorer.calculate_scores(vert_target_finder.get_image());
        cout << "Report out for image " << argv[i] <<endl;
        report_scores(blue_ball_scorer, "Blue ball finder");
        report_scores(horiz_target_scorer,"Horizontal target finder");
        report_scores(vert_target_scorer, "Vertical target finder");
        report_scores(red_ball_scorer, "Red ball finder");
    }
}

void report_scores(ScoreAnalyzer score,string findername)
{
    vector<Score> scores=score.get_scores();
    cout << findername << " found " << scores.size() << " matches"<<endl;
}

void init_handlers()
{
    image_handler.add_observer(&red_ball_finder);
    image_handler.add_observer(&blue_ball_finder);
    image_handler.add_observer(&horiz_target_finder);
    image_handler.add_observer(&vert_target_finder);
}
