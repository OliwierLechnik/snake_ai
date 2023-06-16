#include <iostream>
#include <threads.h>
#include "snake.hpp"
#include "network.hpp"
#include <SFML/Graphics.hpp>

void playSnek();

int main(){
    Network network({4,3,3,2});
    auto decition = network.evaluate({0,0,0,1});
    std::cout << decition[0] << " " << decition[1] << std::endl;

    return 0;
}

void playSnek(){
    const int width = 35;
    const int height = 25;
    const int scale = 25;

    sf::RenderWindow window(sf::VideoMode(width*scale, height*scale), "SFML Window");

    Snake snek({width,height});

    sf::Texture snekTexture;
    snekTexture.create(width,height);
    sf::Sprite snekSprite;

    sf::Clock clock;
    sf::Time t = clock.getElapsedTime();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    snek.move(0);
                    break;
                case sf::Keyboard::Right:
                    snek.move(1);
                    break;
                case sf::Keyboard::Down:
                    snek.move(2);
                    break;
                case sf::Keyboard::Left:
                    snek.move(3);
                    break;
                default:
                    break;
                }
            }
        }

        std::vector <uint8_t> pixels = snek.getPixelVector();
        snekTexture.update(pixels.data());
        snekSprite.setTexture(snekTexture);
        snekSprite.setScale({scale, scale});

        window.clear();
        window.draw(snekSprite);
        window.display();
    }
}