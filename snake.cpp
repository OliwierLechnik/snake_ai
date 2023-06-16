#include "snake.hpp"


Snake::Snake(std::pair <int, int> size){

    this->dead = false;
    this->size = size;
    this->head = {size.first/2, size.second/2};
    do{
        this->fruit = {rand()%size.first, rand()%size.second};
    }while(this->fruit == this->head);
    this->tailSize = 3;


}

void Snake::move(int direction){

    if(this->dead){
        return;
    }

    //add head to tail and shorten tail if nececery
    this->tail.insert(this->tail.begin(), this->head);
    while(this->tail.size() > tailSize){
        this->tail.pop_back();
    }
    //move head to desired grid squere
    switch(direction){
        case 0: 
            head.second--;
        case 1:
            head.first++;
        case 2:
            head.second++;
        case 3:
            head.first--;
    }

    //check if grid state is valid
    if(this->inTail(head)){
        this->dead = true;
    }
    if(this->head.first < 0 || this->head.first >= this->size.first){
        this->dead = true;
    }
    if(this->head.second < 0 || this->head.second >= this->size.second){
        this->dead = true;
    }

    //if head is on a fruit adjust score and move fruit
    if(this->head == this->fruit){
        this->tailSize++;
        this->regularScore++;
        do{
            this->fruit = {rand()%size.first, rand()%size.second};
        }while(this->head == this->fruit || this->inTail(this->fruit));
    }

}


bool Snake::inTail(std::pair <int,int> cell){
    for(const std::pair <int,int> & p : this->tail){
        if(p==cell){
            return true;
        }
    }
    return false;
}

bool Snake::isDead(){
    return this->dead;
}

std::vector <uint8_t> Snake::getPixelVector(){

    /*
        before we call this function, we assume that the state of the grid is valid
        
        black - empty cell
        red - head
        green - fruit
        blue - tail
    */

    std::vector <uint8_t> pixels;
    pixels.resize(this->size.first*this->size.second*4);
    std::fill(pixels.begin(), pixels.end(), 0);

    for(int i = 3; i<=this->size.first*this->size.second*4; i+=4){
        pixels[i]=255;
    }

    pixels[this->head.first*this->head.second*4]=255;
    
    pixels[this->fruit.first*this->fruit.second*4+1]=255;

    for(const std::pair <int, int> & t : this->tail){
        pixels[t.first*t.second*4+2]=255;
    }

    return pixels;
}