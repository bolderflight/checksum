cmake_minimum_required(VERSION 3.13)
# Project information
project(Checksum
  VERSION 1.0
  DESCRIPTION "Checksum functions."
  LANGUAGES C CXX
)
# Add the library target
add_library(checksum
	include/checksum/checksum.h
 	src/checksum/checksum.cc
)
# Setup include directories 
target_include_directories(checksum PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 	$<INSTALL_INTERFACE:include>
)
