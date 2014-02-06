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
    double distance;
    Point position;
};

class ScoreAnalyzer:
public Observer<Mat>
{
    public:
        ScoreAnalyzer(){}

        ScoreAnalyzer(ImageObject* object)
        {
            this->object_=object;
        }

        void set_object(ImageObject* object)
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

        void calculate_scores(Mat image);

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
