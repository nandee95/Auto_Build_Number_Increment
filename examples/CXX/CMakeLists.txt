cmake_minimum_required(VERSION 3.3)

#Set up project
project(app CXX)
add_executable(app "main.cpp" "build_number.hpp")

#Get master directory
get_filename_component(MASTER_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(MASTER_DIR ${MASTER_DIR} DIRECTORY)

#Execute the script at compile time
add_custom_command(
	TARGET app
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND}
		-DHEADER_DIR:PATH="${CMAKE_SOURCE_DIR}"
		-DCACHE_DIR:PATH="${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}"
		-DLANGUAGE:STRING="CXX"
		-P "${MASTER_DIR}/build_number.cmake"
)