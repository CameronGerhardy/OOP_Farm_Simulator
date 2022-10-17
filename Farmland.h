#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
protected:
  //indicates growth level: 0-just planted, 1-halfway, 2-fully grown
  int _growth;
public:
  //
  virtual void updateGrowth();
  virtual std::string getLandType();
  int get_growth();
};