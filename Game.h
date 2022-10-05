#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Game{
private:
  sf::RenderWindow* win;
public:
  Game(int size, std::string title);
  void run();
  ~Game();
};