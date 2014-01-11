#include"Observer.hpp"
#include"ImageObject.hpp"
#include<vector>
#include<opencv2/imgproc/imgproc.hpp>
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
        static double calculateAreaScore(ImageObject* obj,Rect bound, vector<Point> contour)
        {
            double virtualArea = obj->calculateArea(bound.width,bound.height);
            double actualArea = contourArea(contour);
            return actualArea/virtualArea;
        }
        static double calculateRatioScore(ImageObject* obj, Rect bound, vector<Point> contour)
        {
            double virtualRatio = obj->ratio();
            double actualRatio = bound.width/bound.height;
            return actualRatio>virtualRatio ? virtualRatio/actualRatio : actualRatio/virtualRatio;
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
        };

        vector<Score> getScores()
        {
            return scores;
        }

        void calculateScores(Mat image)
        {
            vector<Vec4i> hierarchy;
            Mat dst=image.clone();
            findContours(dst,this->contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0,0) );
            for(int i=0;i<contours.size();++i)
            {
                Score score;
                Rect bound = boundingRect(contours[i]);
                double areaScore = calculateAreaScore(object, bound,contours[i]); 
                if(areaScore > object->areaThreshold())
                    score.areaScore = areaScore;
                else
                    continue;
                double ratioScore = calculateRatioScore(object,bound,contours[i]);
                if(ratioScore < object->ratioThreshold())
                    score.ratioScore = ratioScore;
                else
                    continue;
                scores.push_back(score); 
            }
        }

        void update(Mat image, void (*function)())
        {
            calculateScores(image);
            function();
        }
};
#endif
