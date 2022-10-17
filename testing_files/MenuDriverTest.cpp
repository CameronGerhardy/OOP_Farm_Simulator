#include "../Menu.h"
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
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(shape);


        // Menu menu();
        // menu.setRectSize(0,sf::Vector2f(50,100));
        // menu.setRectPosition(0,25,25);
        // menu.setRectFillColor(0,sf::Color(70,70,70));
        // menu.draw(window);

        window->display();
    }

    return 0;
}