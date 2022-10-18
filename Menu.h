#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class Menu{
private:
  sf::RectangleShape _rectangles[2];
  Button* _buttons;

  int _nButtons;

  
public:
  Menu();
  Menu(int nButtons,sf::Vector2f size, sf::Vector2i pos, int borderSize);

  //draws the menu to the screen
  void draw(sf::RenderWindow* win, bool drawText);

  //sets the buttons on the menu
  void setButton(int index, Button b);

  //sets the button position
  void setButtonPosition(int index, int x, int y);

  //sets the button scale
  void setButtonScale(int index, int xS, int yS);

  //sets the button text
  void setText(int index, sf::Text t);

  //checks if the user has clicked on a button
  bool isClicked(int index, int mouseX, int mouseY);

  //checks if the mouse is inside the menu
  bool isInside(int mouseX, int mouseY);

  //sets the string of the button
  void setString(int index, std::string s);
  ~Menu();

};