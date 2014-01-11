#include "ImageAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;

int main(void)
{
    ImageAnalyzer analyzer;
    ImageAnalyzer analyzer2;
    ImageAnalyzer analyzer3;

    Mat image = imread("./FRC.jpg");
    
    ImageObject* hotTarget = new HorizHotTarget();
    ImageObject* ball = new Ball();
    analyzer.setObject(hotTarget);
    analyzer2.setObject(ball);

    namedWindow("Analysis1",WINDOW_NORMAL);
    namedWindow("Analysis2",WINDOW_NORMAL);
    namedWindow("Origin",WINDOW_NORMAL);

    ImageGateway gate;
    gate.addObserver(&analyzer);
    gate.addObserver(&analyzer2);
    gate.setImage(image);
    
    imshow("Origin",image);
    imshow("Analysis1",analyzer.getImage());
    imshow("Analysis2",analyzer2.getImage());
    waitKey(0);

    image = imread("./balls.jpg");
    gate.setImage(image);

    imshow("Origin",image);
    imshow("Analysis1",analyzer.getImage());
    imshow("Analysis2",analyzer2.getImage());
    waitKey(0);

    destroyWindow("Origin");
    destroyWindow("Analysis1");
    destroyWindow("Analysis2");
}
