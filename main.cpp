#include <iostream>
#include <threads.h>
#include "snake.hpp"
#include "network.hpp"



int main(){
    Snake snek("Heisenberg");
    std::cout << snek.say_my_name() << std::endl;
    std::cout << "You're god damn right!" << std::endl;
    return 0;
}