#pragma once

#include <map>
#include <string>

class Player{
private:
  int _coins;
  int _xp;
  std::map<std::string,int> _seeds;

  int _maxLand;
public:
  Player();
  Player(int coins, int xp);

  //returns number of coins
  int getCoins();

  //returns number of xp
  int getXP();

  //returns the number of seeds
  int getSeeds(std::string seedName);

  //changes the number of seeds
  void changeSeeds(std::string seedName, int amount);

  //changes the xp
  void setXP(int xp);

  //changes the coins
  void setCoins(int coins);

  //increments the coins by a value n
  void incremCoins(int n);

  //increments the xp by a value n
  void incremXP(int n);

};