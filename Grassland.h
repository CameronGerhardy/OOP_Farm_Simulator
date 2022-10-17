#pragma once
#include "Land.h"
#include <string>

class Grassland : public Land{
private:
public:
  virtual std::string getLandType();
  void updateGrowth();
};