#include <string>
#include <vector>

class Snake{
private:

    const int moveCost = 10;
    const int fruitScore = 100;

    std::pair <int, int> size;
    int regularScore;
    int trueScore;
    std::pair <int,int> head;
    std::vector <std::pair <int,int>> tail;
    int tailSize;
    std::pair <int, int> fruit;

public:
    Snake(std::pair <int, int> size);
    bool isDead();
    
};