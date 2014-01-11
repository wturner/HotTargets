#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#define KERNEL_SIZE 5
#define VERTICAL_RATIO 5.875
#define HORIZONTAL_RATIO .125

using namespace cv;

struct contour_report
{
    int width;
    int height;
    int area;
};
typedef struct contour_report * ContourReport;

struct score
{
    ContourReport report;
    float rectangularity;
    float vertical_ratio;
    float horizontal_ratio;
};
typedef struct score * Score;

void score_rectangularity(Score score)
{
    ContourReport report = score->report;
    int w = report->width,h=report->height;
    int area = report->area;
    if(w*h)
        score->rectangularity = (w*h)/area;
}

void score_vertical_ratio(Score score)
{
    ContourReport report = score->report;
    int virtualRatio = report->width/report->height;
}

void score_horizontal_ratio(Score score)
{

}

int main(void)
{
    Mat FRC_image = imread("./FRC.jpg");
    Mat kernel=Mat::ones(KERNEL_SIZE,KERNEL_SIZE,CV_8U);

    inRange(FRC_image,Scalar(0,80,0),Scalar(255,255,255),FRC_image);
    erode(FRC_image,FRC_image,kernel);
    dilate(FRC_image,FRC_image,kernel);

    namedWindow("test",WINDOW_AUTOSIZE);
    imshow("test",FRC_image);

    waitKey(0);
}
