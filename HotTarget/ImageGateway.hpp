#include"Observable.hpp"
#include<opencv2/core/core.hpp>
#include<iostream>
#include<thread>
#include"Observer.hpp"
#ifndef IMAGEGATEWAY_HPP
#define IMAGEGATEWAY_HPP

using namespace std;
using namespace cv;

class ImageGateway:
public Observable<Mat>
{
    public:
        void set_image(Mat image)
        {
            this->image_=image;
            notify_observers();
        }

        void notify_observers()
        {
            thread processes [observers_.size()];
            for(int i=0;i<observers_.size();++i)
                processes[i] = thread (&ImageGateway::update_observer,observers_[i],image_);
            for(int i=0;i<observers_.size();++i)
                processes[i].join();
        }

        void add_observer(Observer<Mat>* o)
        {
            observers_.push_back(o);
        }

        void remove_observer(Observer<Mat>* o)
        {
            observers_.erase(remove(observers_.begin(),observers_.end(),o));
        }

        static void update_observer(Observer<Mat>* obs, Mat image)
        {
            obs->update(image,callback_function);
        }

    private:
        Mat image_;

        vector < Observer<Mat>* > observers_;

        static void callback_function()
        {
            cout<<"Done with image"<<endl;
        }
};
#endif
