#include"ImageObject.hpp"
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#ifndef IMAGEOBJECTS_HPP
#define IMAGEOBJECTS_HPP
#define AREA_THRESHOLD 45
#define RATIO_THRESHOLD 45

class Ball:
public ImageObject
{
    public:
        Ball(Scalar low, Scalar high) : 
            ImageObject(low,high,
            getStructuringElement(MORPH_ELLIPSE,Size(15,15), 
            Point(0,0))){}

        double calculateArea(double width, double height)
        {
            int avgRadius = (width/2+height/2)/2;
            return avgRadius*avgRadius*3.14159265*.8;
        }
        double areaThreshold()
        {
            return AREA_THRESHOLD+40; 
        }
        double ratio()
        {
            return 1.;
        }
        double ratioThreshold()
        {
            return RATIO_THRESHOLD+40;
        }
};
class RedBall:
public Ball
{
    public:
        RedBall() :
            Ball(Scalar(0,0,60,0),Scalar(140,80,255,255)){}
};


class BlueBall:
public Ball
{
    public:
        BlueBall() :
            Ball(Scalar(60,20,0,0),Scalar(255,100,140,255)){}
};

class HorizHotTarget:
public ImageObject
{
    private:
        const double RATIO = 23.5/4;
    public:
        HorizHotTarget() : ImageObject(Scalar(0,60,0,0),Scalar(255,255,10,255),Mat::ones(5,5,CV_8U)){};
        double calculateArea(double width, double height)
        {
            return width*height;
        }
        double areaThreshold()
        {
            return AREA_THRESHOLD; 
        }
        double ratio()
        {
            return RATIO;
        }
        double ratioThreshold()
        {
            return RATIO_THRESHOLD;
        }
};

#endif
