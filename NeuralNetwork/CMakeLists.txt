cmake_minimum_required(VERSION 3.15)
project(NeuralNetwork)
set(CMAKE_CXX_STANDARD 14)
add_executable(NeuralNetwork NeuralNetwork/PerceptronTests.cpp
        NeuralNetwork/Matrix.h
        NeuralNetwork/Matrix.cpp
        NeuralNetwork/Neuron.h
        NeuralNetwork/Neuron.cpp
        NeuralNetwork/Perceptron.h
        NeuralNetwork/Perceptron.cpp)
