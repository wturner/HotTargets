#include "ImageAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;

int main(int argc, char* argv [])
{
    ImageAnalyzer analyzer;
    ImageAnalyzer analyzer2;

    Mat image = imread("./FRC.jpg");
    
    ImageObject* hotTarget = new HorizHotTarget();
    ImageObject* ball = new BlueBall();
    analyzer.set_object(hotTarget);
    analyzer2.set_object(ball);

    namedWindow("Analysis1",WINDOW_NORMAL);
    namedWindow("Analysis2",WINDOW_NORMAL);
    namedWindow("Origin",WINDOW_NORMAL);

    ImageGateway gate;
    gate.add_observer(&analyzer);
    gate.add_observer(&analyzer2);
    gate.set_image(image);
    
    imshow("Origin",image);
    imshow("Analysis1",analyzer.get_image());
    imshow("Analysis2",analyzer2.get_image());
    waitKey(0);

    image = imread(argv[1]);
    gate.set_image(image);

    imshow("Origin",image);
    imshow("Analysis1",analyzer.get_image());
    imshow("Analysis2",analyzer2.get_image());
    waitKey(0);

    destroyWindow("Origin");
    destroyWindow("Analysis1");
    destroyWindow("Analysis2");
}
