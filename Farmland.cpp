#include "Land.h"
#include "Farmland.h"
#include <string>

std::string Farmland::getLandType(){
  return "Farmland";
}

void Farmland::updateGrowth(){_growth =0;}

Farmland::int get_growth(){
  return _growth; 
}