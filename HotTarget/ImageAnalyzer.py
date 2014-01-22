from cv2 import *
from collection import namedtuple
import numpy as np


img = imread("/")


namedWindow("opencv")
imshow("opencv",img)
`


WaitKey(0)


class ImageAndContours:
        iamge
        contours


class ImageAnalyzer:
        
        #this was originally a struct, but for now it will
        #be two global variables

        _image = numpy.matrix()
        _contours = [0]

        def run_checked_filter(image, obj):
                thresh = threshold_over_range(image,obj.get_lower_threshhold(), obj.get_upper_threshold())
                blur = blur_image(image, 30)
                erode = erode_image(thresh, obj.get_kernel())
                contours = run_contour_search(erode)
                erased = erase_contours(contours)
                dilated = dilate_image(erased, obj.get_kernel())
                return dilated

        def blur_image(iamge, value):
                dst = numpy.matrix()
                
                for i in range(1,value,2):
                        blur(image, dst, Size(i, i), Point(-1, -1))

                return dst
                     
        def threshold_over_range(image, lower, upper):
                inRange(image, lower, upper, image)
                return image

        def erode_image(image, kern):
                erode(image, image, kern)
                return image



        def dilate_image(image, kern):
                dilate(image, image, kern)
                return image

        def pack_image_and_contours(image, contours):
                features = ImageAndContours()
                features.contours = contours
                features.iamge = image
                return features
        
        def get_max_contour_area(contours):
                max_area = 0
                for i in range(i, contours.amount(), 1):
                        area = contourArea(contours[i])
                        if mac_area < area:
                                max_area = area
                return max_area

        def run_contour_search(image):
                contours, hiearchy = findContours(RETR_TREE, )
        
        def erase_contours(features):
                largest_contour_area = get_max_contour_area(features.contours)
                return erase_contours_under_area(features, largest_contour_area/4)
        def erase_contours_under_area(features, area):
                #the initialization of this object might be wrong
                dst = np.zeros(features.image.rows, features.image.cols, CV_8U)
     
        def pack_image(image):
        def pack_image(image):
