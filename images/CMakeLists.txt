#Test Functions

function(horizontal_target testName imageName)
	add_test(${testName} ${EXECUTABLE_OUTPUT_PATH}/src/run horiztarget ${CMAKE_SOURCE_DIR}/images/${imageName})
	SET_TESTS_PROPERTIES(${testName} PROPERTIES FAIL_REGULAR_EXPRESSION "horiz target finder not found")
endfunction()

function(vertical_target testName imageName)
	add_test(${testName} ${EXECUTABLE_OUTPUT_PATH}/src/run verttarget ${CMAKE_SOURCE_DIR}/images/${imageName})
	SET_TESTS_PROPERTIES(${testName} PROPERTIES FAIL_REGULAR_EXPRESSION "vertical target finder not found")
endfunction()

function(blue_ball testName imageName)
	add_test(${testName} ${EXECUTABLE_OUTPUT_PATH}/src/run blueball ${CMAKE_SOURCE_DIR}/images/${imageName})
	SET_TESTS_PROPERTIES(${testName} PROPERTIES FAIL_REGULAR_EXPRESSION "blue ball finder not found")
endfunction()

function(red_ball testName imageName)
	add_test(${testName} ${EXECUTABLE_OUTPUT_PATH}/src/run redball ${CMAKE_SOURCE_DIR}/images/${imageName})
	SET_TESTS_PROPERTIES(${testName} PROPERTIES FAIL_REGULAR_EXPRESSION "red ball finder not found")
endfunction()
