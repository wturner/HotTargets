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
set_property(TEST Balls PROPERTY FAIL_REGULAR_EXPRESSION "blue ball finder found 0 match(es)*" "red ball finder found 0 match(es)*")
set_property(TEST Balls PROPERTY PASS_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*")

add_test(BlueBall ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/blueball.jpg)
set_property(TEST BlueBall PROPERTY FAIL_REGULAR_EXPRESSION "blue ball finder found 0 match(es)*")
set_property(TEST BlueBall PROPERTY PASS_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*" "red ball finder found 0 match(es)*")

add_test(Target1 ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/target1.jpg)
set_property(TEST Target1 PROPERTY FAIL_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*")
set_property(TEST Target1 PROPERTY PASS_REGULAR_EXPRESSION "red ball finder found 0 match(es)*" "blue ball finder found 0 match(es)*")

add_test(Balls3 ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/balls3.jpg)
set_property(TEST Balls3 PROPERTY FAIL_REGULAR_EXPRESSION "red ball finder found 0 match(es)*")
set_property(TEST Balls3 PROPERTY PASS_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*" "blue ball finder found 0 match(es)*")

add_test(ballOnChair ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/ballOnChair.jpg)
set_property(TEST ballOnChair PROPERTY FAIL_REGULAR_EXPRESSION "blue ball finder found 0 match(es)*")
set_property(TEST ballOnChair PROPERTY PASS_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*" "red ball finder found 0 match(es)*")

add_test(Target2 ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/target2.jpg)
set_property(TEST Target2 PROPERTY FAIL_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*")
set_property(TEST Target2 PROPERTY PASS_REGULAR_EXPRESSION "red ball finder found 0 match(es)*" "blue ball finder found 0 match(es)*")

add_test(FRC ${EXECUTABLE_OUTPUT_PATH}/run ${CMAKE_SOURCE_DIR}/FRC.jpg)
set_property(TEST FRC PROPERTY FAIL_REGULAR_EXPRESSION "horiz target finder found 0 match(es)*" "vert target finder found 0 match(es)*")
set_property(TEST FRC PROPERTY PASS_REGULAR_EXPRESSION "red ball finder found 0 match(es)*" "blue ball finder found 0 match(es)*")

