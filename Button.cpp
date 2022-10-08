#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button(){}

Button::Button(sf::Sprite s){
  _img = s;
}

bool Button::isClicked(int mouseX, int mouseY){
  sf::IntRect rect = _img.getTextureRect();
  return rect.contains(mouseX,mouseY);
}

void Button::setPosition(int x, int y){
  _img.setPosition(x,y);
}

void Button::setScale(int xS, int yS){
  _img.setScale(xS,yS);
}

void Button::draw(sf::RenderWindow* win){
  win->draw(_img);
}
