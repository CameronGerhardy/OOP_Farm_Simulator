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
  int getCoins();
  int getXP();
  int getSeeds(std::string seedName);

  void changeSeeds(std::string seedName, int amount);
  void setXP(int xp);
  void setCoins(int coins);

  void incremCoins(int n);
  void incremXP(int n);

};