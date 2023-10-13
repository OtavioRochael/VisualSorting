#include <iostream>
#include "WIndow.hpp"
#include "Algorithm.h"

#define COLUMWIDTH 8

int main()
{
    std::srand(std::time(0));

    Window window("Visual sorting", sf::Vector2u(800,600));
    sf::RenderWindow* renderWindow = window.GetRenderWindow();

    std::vector<int> v; 
   
    for (int i = 0; i < window.GetWindowSize().x / COLUMWIDTH; i++) {
        v.push_back((rand() % window.GetWindowSize().y) + 1);
    }
 
    Algorithm alg = Algorithm(v, v.size(), COLUMWIDTH, *renderWindow);

    alg.SetDelay(0);

    while (!window.IsDone()) {
        window.Update();
        window.BeginDraw();

        //Call here the algorithm;
        alg.insertionSort();
        window.EndDraw();
    }
    
    return 0;
}