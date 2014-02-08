cmake_minimum_required(VERSION 2.8)
project(HotTargets)

#used to link the network tables libraries (check CMakeCache.txt to change the directory variables search NetworkTable)
INCLUDE_DIRECTORIES(${NetworkTables_INC_DIR} ${NetworkTables_INC_DIR}/networktablesshim)
set(NetworkTables_LIB_DIR "NetworkTables_LIB_DIR-NOT_FOUND" CACHE PATH "Directory containing library file")
set(NetworkTables_INC_DIR "NetworkTables_INC_DIR-NOT_FOUND" CACHE PATH "Directory containing .f files")  
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -pthread -lrt -fPIC")

#Executable
add_executable(run run.cpp ImageAnalyzer.cpp ScoreAnalyzer.cpp NetTable.cpp)
target_link_libraries(run ${OpenCV_LIBS} ${NetworkTables_LIB_DIR}/libnetworktables_static.a)
