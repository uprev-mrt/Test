cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()

add_definitions(
    -DPOLY_PACKET_DEBUG_LVL=0
    -g
    )


include_directories("../Modules")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../*_UT.cpp")

# Link runTests with what we want to test and the GTest and pthread library
add_definitions(-DUNIT_TESTING_ENABLED)
add_definitions(-DMRT_PLATFORM=MRT_PLATFORM_NONE)
add_executable(runTests Tester.cpp ${TEST_FILES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
