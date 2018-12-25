cmake_minimum_required(VERSION 3.7)

project(proj1)

# Main executable
file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRCS})

# Test executable
file(GLOB_RECURSE TEST_SRCS "test/*.cpp")
add_executable(${PROJECT_NAME}-test ${SRCS} ${TEST_SRCS})
target_compile_definitions(${PROJECT_NAME}-test PRIVATE "DISABLE_MAIN")

# Dependencies
set(LIBS "Threads::Threads")
target_link_libraries(${PROJECT_NAME} ${LIBS})
target_link_libraries(${PROJECT_NAME}-test "gtest_main" "gtest" ${LIBS})

# External projects must be built before this
add_dependencies(${PROJECT_NAME}-test GTEST)

# make run
add_custom_target("run"
	COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
add_dependencies("run" ${PROJECT_NAME})
# make gtest
add_custom_target("gtestrun"
	COMMAND $<TARGET_FILE:${PROJECT_NAME}-test>)
add_dependencies("gtestrun" ${PROJECT_NAME}-test)
