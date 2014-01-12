#include"Observer.hpp"
#include"ImageObject.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<opencv2/core/core.hpp>
#ifndef SCOREANALYZER_HPP
#define SCOREANALYZER_HPP

using namespace cv;
using namespace std;

class ScoreAnalyzer:
public Observer<Mat>
{
    public:
        struct Score;
    private:
        vector<Score> scores;
        vector< vector<Point> > contours;
        ImageObject* object;
        Mat image;

        static double calculateAreaScore(ImageObject* obj,Rect bound, vector<Point> contour)
        {
            double virtualArea = obj->calculateArea(bound.width,bound.height);
            double actualArea = contourArea(contour);
            return actualArea>virtualArea ? (virtualArea/actualArea)*100 : (actualArea/virtualArea)*100;
        }

        static double calculateRatioScore(ImageObject* obj, Rect bound, vector<Point> contour)
        {
            double virtualRatio = obj->ratio();
            double actualRatio = (double)bound.width/(double)bound.height;
            return actualRatio>virtualRatio ? (virtualRatio/actualRatio) *100 : (actualRatio/virtualRatio) * 100;
        }

    public:

        ScoreAnalyzer(ImageObject* object)
        {
            this->object=object;
        }

        struct Score
        {
            double areaScore;
            double ratioScore;
            Point position;
        };

        vector<Score> getScores()
        {
            return scores;
        }

        Mat getImage()
        {
            return image;
        }

        void calculateScores(Mat image)
        {
            vector<Vec4i> hierarchy;
            Mat dst=image.clone();
            findContours(dst,this->contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE, Point(0,0) );
            for(int i=0;i<contours.size();++i)
            {
                Score score;
                drawContours(dst,contours,i,Scalar(255,255,255),CV_FILLED);
                Rect bound = boundingRect(contours[i]);
                double areaScore = calculateAreaScore(object,bound,contours[i]);
                if(areaScore > object->areaThreshold())
                    score.areaScore = areaScore;
                else
                    continue;
                double ratioScore = calculateRatioScore(object,bound,contours[i]);
                if(ratioScore > object->ratioThreshold())
                    score.ratioScore = ratioScore;
                else
                    continue;
                score.position = contours[i][0];
                cout<<score.position.x<<","<<score.position.y<<endl;
                scores.push_back(score); 
            }
            this->image = dst;
        }

        void update(Mat image, void (*function)())
        {
            calculateScores(image);
            function();
        }
};
#endif
