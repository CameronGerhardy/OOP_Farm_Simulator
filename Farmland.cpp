#include "Land.h"
#include "Farmland.h"
#include <string>
#include <iostream>

std::string Farmland::getLandType(){
  return "Farmland";
}

void Farmland::updateGrowth(){
  _growth =0;
  //std::cout << "Farmland Growth\n";
}
