#include "network.hpp"
#include <iostream>

Network::Network(std::vector <int> layers){
    // create empty neural network with give size
    this->layers = layers;
    for(int i = 0; i<layers.size()-1; i++){
        std::vector <std::vector <float>> matrix;
        matrix.resize(layers[i+1]);
        std::vector <float> tmp;
        tmp.resize(layers[i]);
        std::fill(tmp.begin(), tmp.end(), 0.f);
        std::fill(matrix.begin(), matrix.end(), tmp);
        this->tWeight.push_back(matrix);

        std::vector <float> v;
        v.resize(layers[i+1]);
        std::fill(v.begin(), v.end(), 0);
        this->mBias.push_back(v);
    }

}

void Network::printWeights(){
    for(const auto & matrix : this->tWeight){
        for(const auto & vec : matrix){
            for(const auto & f : vec){
                std::cout << f << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Network::printBias(){
    for(const auto & vec : this->mBias){
        for(const auto & f : vec){
            std::cout << f << " ";
        }
        std::cout << std::endl;
    }
}

void Network::permutate(float wFrequency, float wMagnitude, float bFrequency, float bMagnitude){
    for(auto & matrix : this->tWeight){
        for(auto & vec : matrix){
            for(auto & f : vec){
                if(rand()%10000<wFrequency*10000){
                    f += wMagnitude*(rand()%2000-1000)/1000;
                }
            }
        }
    }

    for(auto & vec : this->mBias){
        for(auto & f : vec){
            if(rand()%10000<bFrequency*10000){
                f += bMagnitude*(rand()%2000-1000)/1000;
            }
        }
    }
}

float Network::fSigmoid(float value){
    if (value > 4) return 1.f;
    if (value < -4) return 0.f;
    return value/(4+std::abs(value))+0.5;
}

std::vector <float> Network::evaluate(std::vector <float> input){
    std::vector <std::vector <float>> layers;
    layers.push_back(input);
    for(int i = 0; i<this->layers.size()-1; i++){
        std::vector <float> layer;
        for(int j = 0; j<this->layers[i+1]; j++){
            float tmp = 0;
            for(int k = 0; k < this->layers[i]; k++){
                tmp += this->tWeight[i][j][k]*layers[layers.size()-1][k];
            }
            layer.push_back(this->fSigmoid(tmp+mBias[i][j]));
        }
        layers.push_back(layer);
    }
    return layers[layers.size()-1];
}