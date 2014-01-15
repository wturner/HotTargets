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

        double calculate_area(double width, double height)
        {
            int avgRadius = (width/2+height/2)/2;
            return avgRadius*avgRadius*3.14159265;
        }
        double area_threshold()
        {
            return AREA_THRESHOLD+40; 
        }
        double ratio()
        {
            return 1.;
        }
        double ratio_threshold()
        {
            return RATIO_THRESHOLD+40;
        }
};

class RedBall:
public Ball
{
    public:
        RedBall() :
            Ball(Scalar(0,0,70,0),Scalar(100,100,255,255)){}
};

class BlueBall:
public Ball
{
    public:
        BlueBall() :
            Ball(Scalar(60,10,0,0),Scalar(255,170,130,255)){}
};

class HotTarget:
public ImageObject
{
    private:
        double ratio_;
    public:
        HotTarget(double ratio) : ImageObject(Scalar(0,60,0,0),Scalar(255,255,10,255),Mat::ones(5,5,CV_8U))
        {
            this->ratio_=ratio;
        };
        double calculate_area(double width, double height)
        {
            return width*height;
        }
        double area_threshold()
        {
            return AREA_THRESHOLD; 
        }
        double ratio()
        {
            return ratio_;
        }
        double ratio_threshold()
        {
            return RATIO_THRESHOLD;
        }
};

class HorizHotTarget:
public HotTarget
{
    public:
        HorizHotTarget() : HotTarget(23.5/4){};
};

class VertHotTarget:
public HotTarget
{
    public:
        VertHotTarget() : HotTarget(4/32.){};
};
#endif
