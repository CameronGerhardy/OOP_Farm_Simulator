#include "Land.h"
#include <SFML/Graphics.hpp>
#include "Player.h"

Land::Land(sf::Sprite sprite){
  _sprite =sprite;
  _TilePosX =0;
  _TilePosY =0;
}

Land::Land(){
  _TilePosX =0;
  _TilePosY =0;
}
void Land::setPosition(int TilePosX, int TilePosY){
  _TilePosX = TilePosX;
  _TilePosY = TilePosY;
  _sprite.setPosition(32* _TilePosX, 32* _TilePosY);
}
void Land::setSprite(sf::Sprite sprite){
  _sprite =sprite;
}

sf::Sprite Land::getSprite(){
  return _sprite;
}

// void Land::setLandType(std::string landType){
//   _landType = landType;
// }
void Land::updateGrowth(){_growth =0;}

int Land::getGrowth(){
  return _growth; 
}

void Land::HarvestCrop(Player* p){}
void Land::PlantCrop(Player* p){}
