#pragma once
#include "Land.h"
#include <string>

class Grassland : public Land{
private:
public:
  //returns the type of land
  virtual std::string getLandType();

  //updates the growth variable depending on the timer
  void updateGrowth();
};