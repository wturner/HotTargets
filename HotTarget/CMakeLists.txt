cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#Executable
find_package(OpenCV REQUIRED)
add_executable(run run.cpp ImageAnalyzer.cpp ScoreAnalyzer.cpp)
target_link_libraries(run ${OpenCV_LIBS})

#Testing
ENABLE_TESTING()
INCLUDE(CTest)

#Tests
add_test(Balls ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/balls.jpg)
set_property(TEST Balls PROPERTY FAIL_REGULAR_EXPRESSION "blue ball finder found 0 match(es)""red ball finder found 0 match(es)")
#set_property(TEST Balls PROPERTY PASS_REGULAR_EXPRESSION "horiz target finder found 0 match(es)""vert target finder found 0 match(es)")
