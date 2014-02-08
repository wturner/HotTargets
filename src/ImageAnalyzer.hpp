#include<opencv2/core/core.hpp>
#include"ImageObject.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include"Observer.hpp"
#ifndef IMAGEANALYZER_HPP
#define IMAGEANALYZER_HPP
using namespace cv;
using namespace std;

class ImageAnalyzer:
public Observer<Mat>
{
    private:
        ImageAnalyzer(const ImageAnalyzer&);
        void operator=(const ImageAnalyzer&);

        Mat image_;
        ImageObject* object_;

        Mat run_checked_filter(Mat image,ImageObject* obj);

        void set_image(const Mat image)
        {
            this->image_=image;
        }

    public:
        ImageAnalyzer(){}
        ImageAnalyzer(ImageObject* object)
        {
            this->object_=object;
        }

        void update(Mat arg, void (*function)())
        {
            #ifdef DEBUG_ON
            cout<<"updating"<<endl;
            #endif
            run_filter(arg);
            #ifdef DEBUG_ON
            cout<<"Ran filter"<<endl;
            #endif
            function();
            #ifdef DEBUG_ON
            cout<<"Called back"<<endl;
            #endif
        }
       
        void run_filter(const Mat image)
        {
            set_image(run_checked_filter(image,this->object_));
        }

        Mat get_image()
        {
            return image_;
        }

        void set_object(ImageObject* obj)
        {
            this->object_=obj;
        }
};
#endif
