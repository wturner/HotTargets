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
    private:
        //ImageGateway() {}; for singleton
        //ImageGateway(ImageGateway const&); for singleton
        //void operator=(ImageGateway const&); for singleton
        Mat image;
        vector < Observer<Mat>* > observers;

        static void callback_function()
        {
            cout<<"Done with image"<< endl;
        }

        static void update_observer(Observer<Mat>* obs, Mat image)
        {
            obs->update(image,callback_function);
        }
    public:
        /*static ImageGateway* getGateway()
        {
            static ImageGateway instance;
            return &instance;
        } for singleton*/

        void setImage(Mat image)
        {
            this->image=image;
            notifyObservers();
        }

        void notifyObservers()
        {
            thread processes [observers.size()];
            for(int i=0;i<observers.size();++i)
            {
                Observer<Mat>* o = observers[i];
                processes[i]=thread (&ImageGateway::update_observer,o,image);
            }
            for(int i=0;i<observers.size();++i)
            {
                processes[i].join();
            }
        }

        void addObserver(Observer<Mat>* o)
        {
            observers.push_back(o);
        }

        void removeObserver(Observer<Mat>* o)
        {
            observers.erase(remove(observers.begin(),observers.end(),o));
        }
};
#endif
