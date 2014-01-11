#include<opencv2/core/core.hpp>
#include"ImageObject.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include"Observer.hpp"
#include<thread>
#ifndef IMAGEANALYZER_HPP
#define IMAGEANALYZER_HPP
using namespace cv;
using namespace std;

class ImageAnalyzer:
public Observer<Mat>
{
    private:
        Mat kernel;
        Mat image;
        Scalar lowerThreshold;
        Scalar upperThreshold;
        Mat get_sync()
        {
            while(updating){}
            return image;
        }
    protected:
        bool updating;
        void setImage(Mat image)
        {
            this->image=image;
        }
    public:

        void update(Mat arg, void (*function)())
        {
            Mat image = arg;
            runFilter(image);
            function();
        }
       
        void runFilter(Mat image);

        Mat getImage()
        {
            if(!updating)
                return image;
            else
                thread(get_sync);

        }

        void setObject(ImageObject* obj)
        {
            setKernel(obj->getKernel());
            setLowerThreshold(obj->getUThresh());
            setUpperThreshold(obj->getLThresh());
        }

        void setKernel(Mat kernel)
        {
            this->kernel = kernel;
        }

        Mat getKernel()
        {
            return kernel;
        }

        void setUpperThreshold(Scalar uThresh)
        {
            upperThreshold=uThresh;
        }

        Scalar getUpperThreshold()
        {
            return upperThreshold;
        }

        void setLowerThreshold(Scalar lThresh)
        {
            lowerThreshold=lThresh;
        }

        Scalar getLowerThreshhold()
        {
            return lowerThreshold;
        }


};
#endif
