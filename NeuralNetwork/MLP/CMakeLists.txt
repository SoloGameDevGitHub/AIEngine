set(FILES
        ../Common/ActivationFunctions.cpp
        ../Common/Random.cpp
        ../Common/Matrix.cpp
        ../Perceptron/Neuron.cpp
        ../Perceptron/Perceptron.cpp
        Layer.cpp
        MLP.cpp
        Main.cpp
)
add_executable(MultiLayerPerceptron ${FILES})
