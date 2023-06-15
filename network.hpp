#include <vector>
#include <SFML/Graphics.hpp>

class Network{
private:
    std::vector <int> layers;
    std::vector <std::vector <float>> mBias;
    std::vector <std::vector <std::vector <float>>> tWeight;

    void emptyBiasMatrix();
    void emptyWeightTensor();

public:
    Network(std::vector <int> layers);
    
    void printBias();
    void printWeights();
    void saveNetwork(std::string path);
    void loadFromFile(std::string path);

    std::vector <float> evaluate(std::vector <float> input);
};