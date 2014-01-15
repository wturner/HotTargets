#include"Observer.hpp"
#include"ImageObject.hpp"
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<opencv2/core/core.hpp>
#ifndef SCOREANALYZER_HPP
#define SCOREANALYZER_HPP

using namespace cv;
using namespace std;

struct Score
{
    double area_score;
    double ratio_score;
    Point position;
};

class ScoreAnalyzer:
public Observer<Mat>
{
    public:
        ScoreAnalyzer(ImageObject* object)
        {
            this->object_=object;
        }


        vector<Score> get_scores()
        {
            return scores_;
        }

        bool verify_area_score(Score container, Rect bounds,vector<Point> contour)
        {
            container.area_score=calculate_area_score(this->object_,bounds,contourArea(contour));
            return container.area_score>object_->area_threshold();
        }

        bool verify_ratio_score(Score container, Rect bounds)
        {
            container.ratio_score=calculate_ratio_score(this->object_,bounds);
            return container.ratio_score>object_->ratio_threshold();
        }

        Point get_center_point(Rect rect)
        {
            return Point (rect.width/2+rect.x,rect.height/2+rect.y);
        }

        void calculate_scores(Mat image)
        {
            scores_.clear();
            vector<Vec4i> hierarchy;
            vector< vector<Point> > contours;
            findContours(image,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0,0) );

            for(int i=0;i<contours.size();++i)
            {
                Score current_contour_score;
                bool valid_area, valid_ratio;
                Rect score_info= boundingRect(contours[i]);
                valid_area = verify_area_score(current_contour_score,score_info,contours[i]);
                valid_ratio = verify_ratio_score(current_contour_score,score_info);
                current_contour_score.position= get_center_point(score_info);

                if(valid_area && valid_ratio)
                    scores_.push_back(current_contour_score);
            }

        }

        void update(Mat image, void (*function)())
        {
            calculate_scores(image);
            function();
        }

    private:
        vector<Score> scores_;
        ImageObject* object_;

        static double calculate_area_score(ImageObject* obj,Rect bound, int area)
        {
            double virtual_area = obj->calculate_area(bound.width,bound.height);
            return area>virtual_area ? (virtual_area/area)*100 : (area/virtual_area)*100;
        }

        static double calculate_ratio_score(ImageObject* obj, Rect bound)
        {
            double virtualRatio = obj->ratio();
            double actualRatio = (double)bound.width/(double)bound.height;
            return actualRatio>virtualRatio ? (virtualRatio/actualRatio) *100 : (actualRatio/virtualRatio) * 100;
        }
};
#endif
