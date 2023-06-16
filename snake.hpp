#include <string>
#include <vector>

class Snake{
private:

    //helper values for neural network
    const int moveCost = 10;
    const int fruitValue = 100;
    int trueScore;

    //regular snake stuff
    bool dead;
    std::pair <int, int> size;
    int regularScore;
    std::pair <int,int> head;
    std::vector <std::pair <int,int>> tail;
    int tailSize;
    std::pair <int, int> fruit;

    bool inTail(std::pair <int, int> cell);

public:

    Snake(std::pair <int, int> size);

    bool isDead();

    std::vector <uint8_t> getPixelVector(); // array of pixels for both rendering and neural network
    /*
        before we call this function, we assume that the state of the grid is valid
        
        black - empty cell
        red - head
        green - fruit
        blue - tail
    */

    void move(int direction); // 0 - up, 1 - right, 2 - down, 3 - left
    
};