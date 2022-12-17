cmake_minimum_required(VERSION 2.6)
project(main)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++17")

file(
	GLOB_RECURSE
	source_files
	src/*.cpp
)

add_executable(
	main
	${source_files}
)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()