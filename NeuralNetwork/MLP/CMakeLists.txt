# uncomment to persist weights from MLP tests
#add_definitions(-DPERSIST_WEIGHTS)

set(FILES
        ../../Miscellaneous/Random.cpp
        ../../Miscellaneous/ISerializable.cpp
        ../Common/ActivationFunctions.cpp
        ../Common/Neuron.cpp
        Layer.cpp
        MLP.cpp
        MLPMain.cpp
)
add_executable(MultiLayerPerceptron ${FILES})
