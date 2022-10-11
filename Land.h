#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Land{
private:
  int _TilePosX;
  int _TilePosY;
  sf::Sprite _sprite;
  std::string _landType;
public:
  Land();
  Land(sf::Sprite sprite);
  void setSprite(sf::Sprite sprite);
  void setPosition(int TilePosX, int TilePosY);
  sf::Sprite getSprite();
  virtual std::string getLandType();
}; 