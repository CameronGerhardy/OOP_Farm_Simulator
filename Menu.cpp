#include "Menu.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

Menu::Menu(){_nButtons=0;};
Menu::Menu(int nButtons,sf::Vector2f size, sf::Vector2i pos, int borderSize){
  _nButtons = nButtons;
  _buttons = new Button[_nButtons];
  _rectangles[0].setSize(size);
  _rectangles[0].setPosition(pos.x,pos.y);
  _rectangles[0].setFillColor(sf::Color(40,40,40));

  _rectangles[1].setSize(sf::Vector2f(size.x - 2*borderSize,size.y- 2*borderSize));
  _rectangles[1].setPosition(pos.x+borderSize,pos.y+borderSize);
  _rectangles[1].setFillColor(sf::Color(80,80,80));

}

void Menu::draw(sf::RenderWindow* win){
  for(int r = 0; r < 2; r++){
    win->draw(_rectangles[r]);
  }
  for(int b = 0; b < _nButtons; b++){
    _buttons[b].draw(win);
  }
}

bool Menu::isClicked(int index, int mouseX, int mouseY){
  return _buttons[index].isClicked(mouseX,mouseY);
}

bool Menu::isInside(int mouseX, int mouseY){
  return _rectangles[0].getGlobalBounds().contains(mouseX,mouseY);
}

void Menu::setButton(int index, Button b){
  if(index >= _nButtons){return;}
  _buttons[index] = b;
}

void Menu::setButtonPosition(int index, int x, int y){
  _buttons[index].setPosition(x,y);
}
void Menu::setButtonScale(int index, int xS, int yS){
  _buttons[index].setScale(xS,yS);
}


// void Menu::setRectSize(int index, sf::Vector2f v){
//   _rectangles[index].setSize(v);
// }
// void Menu::setRectPosition(int index, int x, int y){
//   _rectangles[index].setPosition(x,y);
// }
// void Menu::setRectFillColor(int index, sf::Color c){
//   _rectangles[index].setFillColor(c);
// }

Menu::~Menu(){
  delete[] _buttons;
}