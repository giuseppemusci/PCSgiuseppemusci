cmake_minimum_required(VERSION 3.20)

project(primialg) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(primialg primialg.cpp)
add_executable(bubblesort bubblesort.cpp)
add_executable(posizionamento posizionamento.cpp)