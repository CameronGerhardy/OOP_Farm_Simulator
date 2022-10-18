#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
public:
  //updates the growth variable depending on the timer
  void updateGrowth();

  //returns the type of land
  virtual std::string getLandType();
};