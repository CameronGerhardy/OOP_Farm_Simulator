#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu{
private:
  sf::RectangleShape _rectangles[2];
  Button* _buttons;

  int _nButtons;

  // void setRectSize(int index, sf::Vector2f v);
  // void setRectPosition(int index, int x, int y);
  // void setRectFillColor(int index, sf::Color c);
  
public:
  Menu();
  Menu(int nButtons,sf::Vector2f size, sf::Vector2i pos, int borderSize);
  void draw(sf::RenderWindow* win, bool drawText);
  void setButton(int index, Button b);
  void setButtonPosition(int index, int x, int y);
  void setButtonScale(int index, int xS, int yS);

  void setText(int index, sf::Text t);

  bool isClicked(int index, int mouseX, int mouseY);
  bool isInside(int mouseX, int mouseY);

  void setString(int index, std::string s);
  ~Menu();

};