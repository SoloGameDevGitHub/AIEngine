#ifdef _EXPORT_DLL_
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif // _EXPORT_DLL_

#include "../AdversarialSearch/Minimax/BitMath.h"
#include "../AdversarialSearch/Minimax/TicTacToeMinimax.h"
#include "../NeuralNetwork/Common/Random.h"
#include "../NeuralNetwork/Common/Matrix.h"
#include "../NeuralNetwork/Common/ActivationFunctions.h"
#include "../NeuralNetwork/Perceptron/Neuron.h"
#include "../NeuralNetwork/Perceptron/Perceptron.h"
#include "../NeuralNetwork/MLP/Layer.h"
#include "../NeuralNetwork/MLP/MLP.h"
