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

  //sets the sprite
  void setSprite(sf::Sprite sprite);

  //sets the position
  void setPosition(int TilePosX, int TilePosY);

  //returns the sprite
  sf::Sprite getSprite();
  
  //abstract -- returns the type of land
  virtual std::string getLandType() = 0;
  
  //updates the growth variable depending on the timer
  virtual void updateGrowth();

  //harvests the crop and adds xp and seeds to player
  virtual void HarvestCrop(Player* p); 

  //plants crop, starts timer, removes seeds from player
  virtual void PlantCrop(Player* p); 

  virtual ~Land(){};
  


  
  int getGrowth();
};


