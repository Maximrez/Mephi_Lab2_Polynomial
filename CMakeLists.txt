cmake_minimum_required(VERSION 3.19)
project(mephi_lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(mephi_lab2 main.cpp Sequence.hpp ArraySequence.hpp DynamicArray.hpp ListSequence.hpp LinkedList.hpp Polynomial.hpp tests.hpp functions.hpp)