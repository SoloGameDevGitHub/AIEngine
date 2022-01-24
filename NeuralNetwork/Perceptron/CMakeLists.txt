set(FILES
        ../Common/ActivationFunctions.cpp
        ../../Common/Random.cpp
        ../../Common/Matrix.cpp
        Neuron.cpp
        Perceptron.cpp
        PerceptronTests.cpp
)
add_executable(Perceptron ${FILES})
