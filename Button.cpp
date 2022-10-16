#include "Button.h"
#include <SFML/Graphics.hpp>

Button::Button(){}

Button::Button(sf::Sprite s){
  _img = s;
}

bool Button::isClicked(int mouseX, int mouseY){
  return _img.getGlobalBounds().contains(mouseX,mouseY);
}

void Button::setPosition(int x, int y){
  _img.setPosition(x,y);
}

void Button::setScale(int xS, int yS){
  _img.setScale(xS,yS);
}

void Button::setText(sf::Text t){
  _text = t;
}

void Button::draw(sf::RenderWindow* win, bool drawText){
  win->draw(_img);
  if(drawText){win->draw(_text);}
  
}

void Button::setSprite(sf::Sprite s){
  _img = s;
}
