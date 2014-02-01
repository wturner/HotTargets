#include<opencv2/core/core.hpp>
#ifndef IMAGEOBJECT_HPP
#define IMAGEOBJECT_HPP
#define IMAGE_HEIGHT 600
using namespace cv;
class ImageObject
{
    private:
        Scalar upper_threshold_;
        Scalar lower_threshold_;
        Mat kernel_;
        bool filterTwice_ = false;
    public:
        int alt1_=0;
        int alt2_=0;
        ImageObject(Scalar lower_threshold,Scalar upper_threshold,Mat kernel)
        {
            this->upper_threshold_=upper_threshold;
            this->lower_threshold_=lower_threshold;
            this->kernel_=kernel;
        }
        ImageObject(Scalar lower_threshold,Scalar upper_threshold,Mat kernel,int alt1, int alt2)
        {
            this->upper_threshold_=upper_threshold;
            this->lower_threshold_=lower_threshold;
            this->kernel_=kernel;
            alt1_=alt1;
            alt2_=alt2;
            this->filterTwice_=true;
        }
        static int getImageHeight(){
            return IMAGE_HEIGHT;
        }
        bool filterTwice()
        {
            return this->filterTwice_;
        }
        virtual double ratio()=0;
        virtual double calculate_area(double width,double height)=0;
        virtual double area_threshold()=0;
        virtual double ratio_threshold()=0;
        virtual double calculate_distance(int width,int height)
        {
            return -1;
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
