cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_STANDARD 17)
project(thread_safe_queue)
add_executable(tsq thread_safe_queue/main.cpp)
