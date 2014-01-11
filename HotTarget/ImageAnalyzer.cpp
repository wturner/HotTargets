#include"ImageAnalyzer.hpp"
#include<iostream>
void ImageAnalyzer::runFilter(Mat image)
{
    updating=true;
    Mat dst=image.clone();
    inRange(dst,lowerThreshold,upperThreshold,dst);

    erode(dst,dst,kernel);

    dilate(dst,dst,kernel);
    setImage(dst);
    updating=false;
}
