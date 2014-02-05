# CMake generated Testfile for 
# Source directory: /home/jagen31/Robotics/HotTarget/HotTarget
# Build directory: /home/jagen31/Robotics/HotTarget/HotTarget/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(Balls "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/balls.jpg")
SET_TESTS_PROPERTIES(Balls PROPERTIES  FAIL_REGULAR_EXPRESSION "horiz target finder found 0 match(es);vert target finder found 0 match(es)" PASS_REGULAR_EXPRESSION "red ball finder found 0 match(es);blue ball finder found 0 match(es)")
ADD_TEST(BlueBall "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/blueball.jpg")
ADD_TEST(Target1 "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/target1.jpg")
ADD_TEST(Balls3 "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/balls3.jpg")
ADD_TEST(ballOnChair "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/ballOnChair.jpg")
ADD_TEST(Target2 "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/target2.jpg")
ADD_TEST(FRC "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/FRC.jpg")
