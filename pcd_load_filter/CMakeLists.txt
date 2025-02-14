cmake_minimum_required(VERSION 3.0)

project(pcd_load_filter)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcd_load_filter src/pcd_load_filter.cpp)
target_link_libraries(pcd_load_filter ${PCL_LIBRARIES})