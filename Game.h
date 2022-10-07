#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

class Game{
private:
  sf::RenderWindow* win;
  Player* player;
  

  sf::Texture textureFile;
  sf::Sprite* sprites;

public:
  Game(int width,int height,
     std::string title,std::string location, int sizeX, int sizeY);
  void run();
  ~Game();
};