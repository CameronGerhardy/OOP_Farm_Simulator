#pragma once
#include "Land.h"
#include "string.h"

class Grassland : public Land{
private:
public:
  virtual std::string getLandType();
};