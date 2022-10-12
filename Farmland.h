#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
private:
public:
  std::string getLandType();
};