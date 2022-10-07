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

  std::string screenState;

  sf::RectangleShape* rectangles;
  sf::IntRect* boxes;
  
  bool inBoxes(int x, int y, int n);
  bool inRectangles(int x, int y, int n);
public:
  Game(int width,int height,
     std::string title,std::string location, int sizeX, int sizeY);
  void run();
  ~Game();
};