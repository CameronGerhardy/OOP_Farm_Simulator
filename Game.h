#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

class Game{
private:
  sf::RenderWindow* win;
  Player* player;

public:
  Game(int size, std::string title);
  void run();
  ~Game();
};