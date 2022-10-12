#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Land{
private:
  int _TilePosX;
  int _TilePosY;
protected:
  sf::Sprite _sprite;
  std::string _landType;
public:
  Land();
  Land(sf::Sprite sprite);
  void setSprite(sf::Sprite sprite);
  void setPosition(int TilePosX, int TilePosY);
  sf::Sprite getSprite();
  void setLandType(std::string landType);
  virtual std::string getLandType();
}; 