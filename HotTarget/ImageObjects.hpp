#include"ImageObject.hpp"
#ifndef IMAGEOBJECTS_HPP
#define IMAGEOBJECTS_HPP
#define AREA_THRESHOLD 45
#define RATIO_THRESHOLD 45
class Ball:
public ImageObject
{
    public:
        Ball() : ImageObject(Scalar(0,0,45,0),Scalar(50,65,255,255),Mat::ones(15,15,CV_8U)){};
        double calculateArea(double width, double height)
        {
            int avgRadius = (width+height)/2;
            return avgRadius*avgRadius * 3.14159265;
        }
        double areaThreshold()
        {
            return AREA_THRESHOLD; 
        }
        double ratio()
        {
            return 1;
        }
        double ratioThreshold()
        {
            return RATIO_THRESHOLD;
        }
};

class HorizHotTarget:
public ImageObject
{
    private:
        const double RATIO = 23.5/4;
    public:
        HorizHotTarget() : ImageObject(Scalar(0,100,0,0),Scalar(255,255,255,255),Mat::ones(5,5,CV_8U)){};
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
