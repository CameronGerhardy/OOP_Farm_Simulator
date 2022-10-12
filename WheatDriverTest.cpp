#include "Menu.h"
#include "WheatCrop.cpp"
#include "Land.cpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow* window;
    window = new sf::RenderWindow(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window->close();
            }
                
        }

        window->clear();
        window->draw(shape);

        Wheat w;
        Player p;

        w.PLantCrop(&p);

        cout << p.getSeeds("Wheat");

        window->display();
    }

    return 0;
}