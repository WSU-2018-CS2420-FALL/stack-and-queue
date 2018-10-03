cmake_minimum_required(VERSION 3.10)
project(stackAndQueue)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(stack src/stack.cpp )
  
add_executable(queue src/queue.cpp )

add_executable(tester test/tester.cpp)