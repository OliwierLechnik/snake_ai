#include <vector>
#include <SFML/Graphics.hpp>

class Network{
private:
    std::vector <int> layers;
    std::vector <std::vector <float>> mBias;
    std::vector <std::vector <std::vector <float>>> tWeight;

    float fSigmoid(float value);

public:
    Network(std::vector <int> layers);
    
    void printBias();
    void printWeights();
    void save(std::string path);
    void loadFromFile(std::string path);
    void permutate(float wFrequency, float wMagnitude, float bFrequency, float bMagnitude);

    std::vector <float> evaluate(std::vector <float> input);
};