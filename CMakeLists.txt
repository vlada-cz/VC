cmake_minimum_required(VERSION 2.8.7)

project(VC)

set(VC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(VC_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${VC_INCLUDE_DIR})
include_directories(${VC_SRC_DIR})

add_executable(vc
	       ${VC_SRC_DIR}/main.cpp
	       ${VC_SRC_DIR}/graph.cpp
	       ${VC_SRC_DIR}/algorithms.cpp
	       ${VC_SRC_DIR}/algorithms/dummy.cpp
	       ${VC_SRC_DIR}/algorithms/GIC.cpp
	       ${VC_SRC_DIR}/algorithms/MDG.cpp
	       ${VC_SRC_DIR}/algorithms/ME.cpp
				 ${VC_SRC_DIR}/algorithms/BF.cpp
	       ${VC_SRC_DIR}/experiments/time_size.cpp)

add_executable(graphGen
	       ${VC_SRC_DIR}/graph_gen.cpp)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=gnu++17 -Wall -Wextra -pedantic")
