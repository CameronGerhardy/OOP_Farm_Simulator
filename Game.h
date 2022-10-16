#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Land.h"
#include "Menu.h"
#include "Grassland.h"
#include "Farmland.h"
#include "Timer.h"

class Game{
private:
  sf::RenderWindow* win;
  Player* player;
  Land*** land;

  sf::Texture textureFile;
  sf::Sprite* sprites;
  sf::Font font;

  Menu* toolbar;
  Menu* seedbar;

  int cols;
  int rows;

  int toolMode;// 0-nothing , 1-cut, 2-selectplant, 3-plant,
  int seedMode;// 0-nothing, 1-wheat, 2-beans, 3-corn

  int mouseX;//mouse Coords
  int mouseY;

public:
  Game(int width,int height,
     std::string title,std::string location, int sizeX, int sizeY);
  void run();
  ~Game();
};