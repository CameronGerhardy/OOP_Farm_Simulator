#pragma once

#include <SFML/Graphics.hpp>

class Button{
private:

  sf::Sprite _img;

public:
  bool isClicked(int mouseX, int mouseY);
  Button();
  Button(sf::Sprite);
  void setPosition(int x, int y);
  void setScale(int xS, int yS);
  void draw(sf::RenderWindow* win);
};