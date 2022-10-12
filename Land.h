#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"

class Land{
private:
  int _TilePosX;
  int _TilePosY;
protected:
  sf::Sprite _sprite;
public:
  Land();
  Land(sf::Sprite sprite);
  void setSprite(sf::Sprite sprite);
  void setPosition(int TilePosX, int TilePosY);
  sf::Sprite getSprite();
  
  //abstract
  virtual std::string getLandType() = 0;

  virtual void HarvestCrop(Player* p); 
  virtual void PlantCrop(Player* p); 

}; 

