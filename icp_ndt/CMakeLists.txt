cmake_minimum_required(VERSION 3.0)

project(pcd_load_filter)

find_package(PCL 1.8 REQUIRED)

include_directories(
# 	${catkin_INCLUDE_DIRS} 
  ${EIGEN3_INCLUDE_DIR}
#   ${PCL_INCLUDE_DIRS}
#   ${PYTHON_INCLUDE_DIRS}
  include)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(icp src/icp.cpp)
target_link_libraries(icp ${PCL_LIBRARIES})