#include"ScoreAnalyzer.hpp"
void ScoreAnalyzer::calculate_scores(Mat image)
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