#include "ImageAnalyzer.hpp"
#include "ScoreAnalyzer.hpp"
#include "ImageObjects.hpp"
#include "ImageGateway.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace std;

int main(int argc,char* argv[])
{
    ImageAnalyzer analyzer;
    ImageAnalyzer analyzer2;

    Mat image = imread(argv[1]);
    Mat image2 = imread(argv[2]);
    
    ImageObject* horiz= new HorizHotTarget();
    ImageObject* ball = new Ball();
    analyzer.set_object(horiz);
    analyzer2.set_object(ball);
    ScoreAnalyzer sAnalyzer(horiz);
    ScoreAnalyzer sAnalyzer2(ball);

    namedWindow("Analysis1",WINDOW_NORMAL);
    namedWindow("Origin",WINDOW_NORMAL);

    ImageGateway imageGate;
    imageGate.add_observer(&analyzer);
    imageGate.add_observer(&analyzer2);
    imageGate.set_image(image);

    ImageGateway scoreGate;
    scoreGate.add_observer(&sAnalyzer);
    scoreGate.add_observer(&sAnalyzer2);
    scoreGate.set_image(analyzer.getImage());
    
    imshow("Origin",image);
    imshow("Analysis2",sAnalyzer.getImage());
    waitKey(0);

    for(int i=0;i<sAnalyzer.getScores().size(); ++i)
    {
        cout<<sAnalyzer.getScores()[i].areaScore<<endl;
    }

    namedWindow("Analysis2",WINDOW_NORMAL);
    imageGate.set_image(image2);
    scoreGate.set_image(analyzer2.getImage());
    imshow("Origin",image2);
    imshow("Analysis2",sAnalyzer2.getImage());
    waitKey(0);

    for(int i=0;i<sAnalyzer2.getScores().size(); ++i)
    {
        cout<<sAnalyzer2.getScores()[i].areaScore<<endl;
    }

    destroyWindow("Origin");
    destroyWindow("Analysis1");
    destroyWindow("Analysis2");
}
