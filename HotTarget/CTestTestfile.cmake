# CMake generated Testfile for 
# Source directory: /home/jagen31/Robotics/HotTarget/HotTarget
# Build directory: /home/jagen31/Robotics/HotTarget/HotTarget
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(Balls "/run" "/home/jagen31/Robotics/HotTarget/HotTarget/balls.jpg")
SET_TESTS_PROPERTIES(Balls PROPERTIES  FAIL_REGULAR_EXPRESSION "blue ball finder found 0 match(es);red ball finder found 0 match(es)")
