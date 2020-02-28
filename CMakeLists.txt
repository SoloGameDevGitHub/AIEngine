cmake_minimum_required(VERSION 3.14.5)
project(AIEngine)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build)

set(MODULE_NAME
#                Perceptron
                Matrix
#                Minimax
)

if(${MODULE_NAME} STREQUAL "Perceptron")
    add_subdirectory(NeuralNetwork/Perceptron)
elseif(${MODULE_NAME} STREQUAL "Minimax")
    add_subdirectory(AdversarialSearch/Minimax)
elseif(${MODULE_NAME} STREQUAL "Matrix")
    add_subdirectory(NeuralNetwork/Common)
endif()
