#include "Player.h"
#include <map>
#include <string>

Player::Player(){
  Player::_coins = 0;
  Player::_xp = 0;
  Player::_seeds.insert({"Wheat",0});
  Player::_seeds.insert({"Corn",0});
  Player::_seeds.insert({"Beans",0});
}

Player::Player(int coins, int xp){
  Player::_coins = coins;
  Player::_xp = xp;
  Player::_seeds.insert({"Wheat",4});
  Player::_seeds.insert({"Corn",0});
  Player::_seeds.insert({"Beans",0});
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