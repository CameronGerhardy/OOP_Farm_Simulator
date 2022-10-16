#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
private:
  int _growth = 0;
public:
  virtual std::string getLandType();
};