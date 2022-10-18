#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button{
private:

  
  sf::Text _text;
  sf::Sprite _img;
public:
  Button();
  Button(sf::Sprite s);

  // checks if the button is clicked
  bool isClicked(int mouseX, int mouseY);

  // sets the position of the button
  void setPosition(int x, int y);

  // sets the scale of the button
  void setScale(int xS, int yS);

  // sets the sprite of the button
  void setSprite(sf::Sprite s);

  // sets the text of the button
  void setText(sf::Text t);

  // sets the string of the button
  void setString(std::string s);

  // draws the button to the screen
  void draw(sf::RenderWindow* win, bool drawText);
};