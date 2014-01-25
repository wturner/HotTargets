import observer
class ScoreAnalyzer(observer.Observer):

    def __init__(self,obj):
        self.image_object=obj
        self.score_struct=namedTuple("area score","ratio_score","distance","position")

    def calculate_scores(self,image):
        scores , hierarchy, contours=[]
        cv2.findContours(image,contours,hierarchy,cv2.CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE, Point(0,0))
        for i in xrange(len(contours)):
            contour = contours[i]
            bounds = cv2.boundingRect(contour)
            score = self.score_struct._asdict()
            valid_area = verify_area_score(score,contour)
            valid_ratio = verify_ratio_score(score,contour)
            score["position"] = get_center_point(bounds)
            score["distance"] = self.image_object.calculate_distance(bounds.width,bounds.height)
            if valid_area and valid_ratio:
                scores.add(score)
        return scores

    def _verify_area_score(self, score, bounds, contour):
        score = self.score_struct._asdict()
        score["area score"] = _calculate_area_score(self.image_object, 
                                                    bounds, cv2.contourArea(contour))
        return (score.area_score > self.image_object.area_threshold)
    
    def _verify_ratio_score(score, bounds, contour):
        score = self.score_struct._asdict()
        score["ratio score"] = _calculate_ratio_score(self.image_object, bounds)
         
    def _get_center_point(self,rect):
        return cv2.Point(rect.width/2+rect.x,rect.height/2+rect.y)

    def update(self,image, callback):
        calculate_scores(image)
        callback()

    @staticmethod
    def calculate_ratio_score(obj, bounds):
        virtual_ratio,actual_ratio = obj.ratio(),bounds.width/float(bounds.height)
        return as_ratio(virtual_ratio,actual_ratio)

    @staticmethod
    def calculate_area_score(obj,bounds):
        virtual_area = obj.calculate_area(bounds.width,bounds.height)
        
    @staticmethod
    def as_ratio(score1,score2):
        if score1>score2: return score2/score1
        return score1/score2
