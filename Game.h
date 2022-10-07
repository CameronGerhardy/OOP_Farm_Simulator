#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Land.h"

class Game{
private:
  sf::RenderWindow* win;
  Player* player;
  Land** land;


  sf::Texture textureFile;
  sf::Sprite* sprites;
  sf::Font font;

  int cols;
  int rows;

public:
  Game(int width,int height,
     std::string title,std::string location, int sizeX, int sizeY);
  void run();
  ~Game();
};