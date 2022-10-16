#pragma once
#include "Land.h"
#include "string.h"

class Farmland : public Land{
private:
public:
  virtual std::string getLandType();
};