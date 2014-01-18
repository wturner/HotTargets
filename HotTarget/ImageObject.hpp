#include<opencv2/core/core.hpp>
#ifndef IMAGEOBJECT_HPP
#define IMAGEOBJECT_HPP
using namespace cv;
class ImageObject
{
    private:
        Scalar upper_threshold_;
        Scalar lower_threshold_;
        Mat kernel_;
    public:
        ImageObject(Scalar lower_threshold,Scalar upper_threshold,Mat kernel)
        {
            this->upper_threshold_=upper_threshold;
            this->lower_threshold_=lower_threshold;
            this->kernel_=kernel;
        }

        virtual double ratio()=0;
        virtual double calculate_area(double width,double height)=0;
        virtual double area_threshold()=0;
        virtual double ratio_threshold()=0;
        virtual double calculate_distance(int width,int height)
        {
            return 0;
        }

        Scalar get_upper_threshold()
        {
            return upper_threshold_;
        }

        Scalar get_lower_threshold()
        {
            return lower_threshold_;
        }

        Mat get_kernel()
        {
            return kernel_;
        }
};
#endif
