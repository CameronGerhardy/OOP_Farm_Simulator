#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button{
private:

  
  sf::Text _text;
  sf::Sprite _img;
public:

  bool isClicked(int mouseX, int mouseY);
  Button();
  Button(sf::Sprite s);
  void setPosition(int x, int y);
  void setScale(int xS, int yS);
  void setSprite(sf::Sprite s);
  void setText(sf::Text t);
  void setString(std::string s);
  void draw(sf::RenderWindow* win, bool drawText);
};