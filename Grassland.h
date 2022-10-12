#pragma once
#include "Land.h"
#include "string.h"

class Grassland : public Land{
private:
public:
  std::string getLandType();
};