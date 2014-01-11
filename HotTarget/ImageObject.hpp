#include<opencv2/core/core.hpp>
#ifndef IMAGEOBJECT_HPP
#define IMAGEOBJECT_HPP
using namespace cv;
class ImageObject
{
    private:
        Scalar uThresh;
        Scalar lThresh;
        Mat kernel;
    public:
        ImageObject(Scalar uThresh,Scalar lThresh,Mat kernel)
        {
            this->uThresh=uThresh;
            this->lThresh=lThresh;
            this->kernel=kernel;
        }

        virtual double ratio()=0;
        virtual double calculateArea(double width,double height)=0;
        virtual double areaThreshold()=0;
        virtual double ratioThreshold()=0;

        Scalar getUThresh()
        {
            return uThresh;
        }

        Scalar getLThresh()
        {
            return lThresh;
        }

        Mat getKernel()
        {
            return kernel;
        }
};
#endif
