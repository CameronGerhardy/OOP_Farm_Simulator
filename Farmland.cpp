#include "Land.h"
#include "Farmland.h"
#include <string>

std::string Farmland::getLandType(){
  return "Farmland";
}

void Farmland::updateGrowth(){_growth =0;}
