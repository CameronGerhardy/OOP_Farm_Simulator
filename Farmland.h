#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
public:
  
  void updateGrowth();
  virtual std::string getLandType();
};