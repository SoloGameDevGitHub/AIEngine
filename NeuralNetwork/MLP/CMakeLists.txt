set(FILES
        ../Common/ActivationFunctions.cpp
        ../Common/Matrix.cpp
        ../../Common/Random.cpp
        ../Perceptron/Neuron.cpp
        ../Perceptron/Perceptron.cpp
        Layer.cpp
        MLP.cpp
        Main.cpp
)
add_executable(MultiLayerPerceptron ${FILES})
