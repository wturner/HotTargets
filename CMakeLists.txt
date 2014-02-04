cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#Requiring OpenCV
find_package(OpenCV REQUIRED)

#Referencing source directories
add_subdirectory(src)

#Enabling Testing
add_subdirectory(images)
enable_testing()
include(CTest)

#Blue Ball Tests
blue_ball(BlueBall1 ballsOnChair.jpg)
blue_ball(BlueBall2 balls.jpg)
blue_ball(BlueBall3 blueball.jpg)

#Red Ball Tests
red_ball(RedBalls1 balls.jpg)
red_ball(RedBalls2 balls3.jpg)

