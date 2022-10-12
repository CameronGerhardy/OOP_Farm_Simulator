#include "Menu.h"
#include "WheatCrop.cpp"
#include "Land.cpp"
#include "Land.h"
#include "Player.h"
#include "Player.cpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

        window->clear();
        window->draw(shape);

        Wheat w;
        Land l;
        Player p(3,4);

        w.PlantCrop(&p);
        

        cout << p.getSeeds("Wheat");

        window->display();
        w.HarvestCrop(&p);
        p.incremCoins(4);
        p.incremXP(4);

        cout << p.getCoins();
        cout << p.getXP();
    return 0;
}