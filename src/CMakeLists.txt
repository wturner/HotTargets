cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#Debug mode?
option(DISPLAY_FRAME "Display camera frame when passing raw image?" ON) 

if(DISPLAY_FRAME)
	add_definitions(-DDEBUG_ON)
endif(DISPLAY_FRAME)

#Executable
add_executable(run run.cpp ImageAnalyzer.cpp ScoreAnalyzer.cpp)
target_link_libraries(run ${OpenCV_LIBS})

