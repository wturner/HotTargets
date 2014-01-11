#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace std;

int main(void)
{
    ImageAnalyzer analyzer;
    ScoreAnalyzer sAnalyzer;

    Mat image = imread("./FRC.jpg");
    
    ImageObject* hotTarget = new HorizHotTarget();
    analyzer.setObject(hotTarget);
    sAnalyzer.setObject(hotTarget);

    namedWindow("Analysis1",WINDOW_NORMAL);
    namedWindow("Origin",WINDOW_NORMAL);

    ImageGateway imageGate;
    imageGate.addObserver(&analyzer);
    imageGate.setImage(image);

    ImageGateway scoreGate;
    imageGate.addObserver(&analyzer);
    imageGate.setImage(analyzer.getImage());
    
    imshow("Origin",image);
    imshow("Analysis1",analyzer.getImage());
    waitKey(0);

    for(int i=0;i<sAnalyzer.getScores().size(); ++i)
    {
        cout<<sAnalyzer.getScores()[i].areaScore<<endl;
    }

    destroyWindow("Origin");
    destroyWindow("Analysis1");
}
