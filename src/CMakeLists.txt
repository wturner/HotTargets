cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#Executable
add_executable(run run.cpp ImageAnalyzer.cpp ScoreAnalyzer.cpp)
target_link_libraries(run ${OpenCV_LIBS})

