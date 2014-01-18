#include"ImageAnalyzer.hpp"
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

struct ImageAndContours
{
    Mat image;
    vector< vector<Point> > contours;
};

Mat blur_image(Mat image,int value);
Mat erode_image(Mat image,Mat kern);
Mat dilate_image(Mat image,Mat kern);
Mat threshold_over_range(Mat image,Scalar lower,Scalar upper);
ImageAndContours run_contour_search(Mat image);
Mat erase_contours (ImageAndContours features);

Mat ImageAnalyzer::run_checked_filter(Mat image,ImageObject* obj)
{
    Mat thresh = threshold_over_range(image,obj->get_lower_threshold(),obj->get_upper_threshold());
    #ifdef DEBUG_ON
    namedWindow("debug",WINDOW_AUTOSIZE);
    imshow("debug",thresh);
    waitKey(0);
    #endif
    Mat blur = blur_image(image,30);
    Mat erode = erode_image(thresh, obj->get_kernel());
    #ifdef DEBUG_ON
    imshow("debug",erode);
    waitKey(0);
    #endif
    ImageAndContours contours = run_contour_search(erode);
    Mat erased = erase_contours(contours);
    #ifdef DEBUG_ON
    imshow("debug",erased);
    waitKey(0);
    #endif
    Mat dilated = dilate_image(erased,obj->get_kernel());
    #ifdef DEBUG_ON
    imshow("debug",dilated);
    waitKey(0);
    cout<<"done"<<endl;
    destroyWindow("debug");
    #endif
    return dilated;
}

Mat blur_image(Mat image,int value)
{
    Mat dst;
    for(int i=1;i<value;i+=2)
    {
        blur(image,dst,Size(i,i),Point(-1,-1));
    }
    return dst;
}
Mat threshold_over_range(Mat image,Scalar lower,Scalar upper)
{
    inRange(image,lower,upper,image);
    return image;
}
Mat erode_image(Mat image,Mat kern)
{
    erode(image,image,kern);
    return image;
}
Mat dilate_image(Mat image,Mat kern)
{
    dilate(image,image,kern);
    return image;
}
ImageAndContours pack_image_and_contours(Mat image,vector< vector<Point> > contours)
{
    ImageAndContours features;
    features.image=image;
    features.contours=contours;
    return features;
}

ImageAndContours run_contour_search(Mat image)
{
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(image.clone(),contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);
    return pack_image_and_contours(image,contours);
}

Mat erase_contours_under_area(ImageAndContours features, int area);
int get_max_contour_area(vector< vector<Point> > contours);

Mat erase_contours (ImageAndContours features)
{
    int largest_contour_area = get_max_contour_area(features.contours);
    return erase_contours_under_area(features,largest_contour_area/4);
}

int get_max_contour_area(vector< vector<Point> > contours)
{
    int max_area=0;
    for(int i=0;i<contours.size();++i)
    {
        int area = contourArea(contours[i]);
        max_area = max_area< area ? area : max_area;
    }
    return max_area;
}

bool contour_area_greater_than(vector<Point> contour, int area);
Mat erase_contours_under_area(ImageAndContours features, int area)
{
    Mat dst = Mat::zeros(features.image.rows,features.image.cols,CV_8U);
    for(int i=0;i<features.contours.size();++i)
        if(contour_area_greater_than(features.contours[i],area))
            drawContours(dst,features.contours,i,Scalar(225,225,225,225),CV_FILLED);
    return dst;
}

bool contour_area_greater_than(vector<Point> contour, int area)
{
    return contourArea(contour)>area;
}
