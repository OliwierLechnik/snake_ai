#include <iostream>
#include <thread>
#include "snake.hpp"
#include "network.hpp"
#include <SFML/Graphics.hpp>

const int width = 35;
const int height = 25;


void playSnek();
int score(Network specimen);
int decide(std::vector <float> v);
void geneticAlgorythm(Network network);

int main(){
    Network empty({width*height*4,64,64,4});
    geneticAlgorythm(empty);
    // playSnek();
    return 0;
}


int decide(std::vector <float> v){
    float mx = 0;
    int index = 0;
    for(int i = 1; i<v.size(); i++){
        if(mx < v[i]){
            mx = v[i];
            index = i;
        }
    }
    return index;
}

void mutateAndScore(Network * specimen, float * result){
    specimen->permutate(0.1,0.1,0.1,0.1);
    Snake snek({width,height});

    while(!snek.isDead()){
        std::vector <uint8_t> pixels = snek.getPixelVector();
        std::vector <float> inputNeurons;
        inputNeurons.resize(width*height*4);
        for(int i = 0; i<width*height*4; i++){
            inputNeurons[i] = pixels[i]/255.f;
        }
        std::vector <float> outputNeurons = specimen->evaluate(inputNeurons);
        snek.move(decide(outputNeurons));
    }
    *result = snek.getRealScore();
}

void geneticAlgorythm(Network network){
    const int amount = 4;
    const int iterationCap = 1024;
    const float frequency = 0.01;
    const float magnitude = 0.1;

    int i = 0;
    while(true){

        std::vector <Network> specimen;
        specimen.reserve(amount);
        std::fill(specimen.begin(), specimen.end(), network);
        std::vector <float> score;
        score.resize(amount);
        std::vector <std::thread> workers;

        for(int j = 0; j<amount; j++){
        std::cout << "tu" << std::endl;
            workers.emplace_back(mutateAndScore, &specimen[j], &score[j]);
        }

        for(std::thread & worker : workers){
            worker.join();
        }

        network = specimen[decide(score)];


    }

}

void playSnek(){
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