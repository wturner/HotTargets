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

#Horizontal Target Tests
horizontal_target(HorizontalTarget1 FRC.jpg)
horizontal_target(HorizontalTarget2 image.jpg)
horizontal_target(HorizontalTarget3 image3.jpg)
horizontal_target(HorizontalTarget4 target1.jpg)
horizontal_target(HorizontalTarget5 target2.jpg)

#Vertical Target Tests
vertical_target(VerticalTarget1 FRC.jpg)
vertical_target(VerticalTarget2 image.jpg)
vertical_target(VerticalTarget3 image3.jpg)
vertical_target(VerticalTarget4 target1.jpg)
vertical_target(VerticalTarget5 target2.jpg)
vertical_target(VerticalTarget6 DEBUG.jpg)
