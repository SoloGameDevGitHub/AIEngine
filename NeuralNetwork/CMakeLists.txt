cmake_minimum_required(VERSION 3.15)
project(Perceptron)
set(CMAKE_CXX_STANDARD 14)
add_executable(Perceptron Perceptron/PerceptronTests.cpp
        Common/Matrix.h
        Common/Matrix.cpp
        Perceptron/Neuron.h
        Perceptron/Neuron.cpp
        Perceptron/Perceptron.h
        Perceptron/Perceptron.cpp)
