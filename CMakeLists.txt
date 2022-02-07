# set up cmake version
cmake_minimum_required(VERSION 3.14.5)

# create the project
project(AIEngine)

# set project properties
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

# include tests from subdirectories
add_subdirectory(AdversarialSearch/Minimax/Tests)
add_subdirectory(Miscellaneous/Tests)
add_subdirectory(NeuralNetwork/Perceptron)
add_subdirectory(NeuralNetwork/MLP)

# include examples from subdirectories
add_subdirectory(Examples/MathLibrary)
