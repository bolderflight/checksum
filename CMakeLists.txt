cmake_minimum_required(VERSION 3.13)
# Project information
project(Checksum
  VERSION 1.0
  DESCRIPTION "Checksum functions."
  LANGUAGES CXX
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
# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(checksum_example examples/checksum_example.cc)
	# Add the includes
	target_include_directories(checksum_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(checksum_example
		PRIVATE 
			checksum
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY 	https://github.com/google/googletest.git
		GIT_TAG 				release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(checksum_test tests/checksum_test.cc)
	# Add the includes
	target_include_directories(checksum_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(checksum_test
		PRIVATE 
			checksum
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(checksum_test)
endif()

