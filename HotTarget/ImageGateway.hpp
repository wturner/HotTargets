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
            thread processes [observers.size()];
            for(int i=0;i<observers.size();++i)
                processes[i] = thread (&ImageGateway::update_observer,observers[i],image_);
            for(int i=0;i<observers.size();++i)
                processes[i].join();
        }

        void add_observer(Observer<Mat>* o)
        {
            observers.push_back(o);
        }

        void remove_observer(Observer<Mat>* o)
        {
            observers.erase(remove(observers.begin(),observers.end(),o));
        }

        static void update_observer(Observer<Mat>* obs, Mat image)
        {
            obs->update(image,callback_function);
        }

    private:
        Mat image_;

        vector < Observer<Mat>* > observers;

        static void callback_function()
        {
            cout<<"Done with image"<<endl;
        }
};
#endif
