#include "Player.h"
#include <map>
#include <string>

Player::Player(){
  _maxLand = 3;
  _coins = 0;
  _xp = 0;
  _seeds.insert({"Wheat",0});
  _seeds.insert({"Corn",0});
  _seeds.insert({"Beans",0});
}

Player::Player(int coins, int xp){
  _maxLand = 3;
  _coins = coins;
  _xp = xp;
  _seeds.insert({"Wheat",4});
  _seeds.insert({"Corn",0});
  _seeds.insert({"Beans",0});
}

int Player::getCoins(){
  return _coins;
}
int Player::getXP(){
  return _xp;
}

int Player::getSeeds(std::string seedName){
  return _seeds.at(seedName);
}

void Player::incremCoins(){
  _coins++;
}