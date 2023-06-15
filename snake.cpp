#include "snake.hpp"


Snake::Snake(std::string name){
    this->name = name;
}

std::string Snake::say_my_name(){
    return this->name;
}