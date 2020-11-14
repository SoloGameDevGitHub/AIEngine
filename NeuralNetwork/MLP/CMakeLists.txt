set(FILES
        ../../Miscellaneous/Random.cpp
        ../../Miscellaneous/ISerializable.cpp
        ../ActivationFunctions.cpp
        ../Neuron.cpp
        Layer.cpp
        MLP.cpp
        Main.cpp
)
add_executable(MultiLayerPerceptron ${FILES})
