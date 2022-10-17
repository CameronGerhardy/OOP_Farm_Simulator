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
    //indicates growth level: 0-just planted, 1-halfway, 2-fully grown
  int _growth;
public:
  Land();
  Land(sf::Sprite sprite);
  void setSprite(sf::Sprite sprite);
  void setPosition(int TilePosX, int TilePosY);
  sf::Sprite getSprite();
  
  //abstract
  virtual std::string getLandType() = 0;
  
  virtual void updateGrowth();
  virtual void HarvestCrop(Player* p); 
  virtual void PlantCrop(Player* p); 

  virtual ~Land(){};
  


  
  int getGrowth();
};


