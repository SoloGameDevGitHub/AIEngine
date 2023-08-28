# set up cmake version
cmake_minimum_required(VERSION 3.14.5)

# create the project
project(AIEngine)

# set project properties
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/Libs)

# include tests from subdirectories
add_subdirectory(AdversarialSearch/Minimax/Tests)
add_subdirectory(Miscellaneous/Tests)
add_subdirectory(NeuralNetwork/Perceptron/Tests)
add_subdirectory(NeuralNetwork/MLP/Tests)

# include examples from subdirectories
add_subdirectory(Examples/MathLibrary)
