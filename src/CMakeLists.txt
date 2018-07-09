cmake_minimum_required(VERSION 3.10)

add_executable(motion-control main.cpp)

target_link_libraries(motion-control pthread)
