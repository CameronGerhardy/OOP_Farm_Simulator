#include "Land.h"
#include "Grassland.h"
#include <string>
#include <iostream>

std::string Grassland::getLandType(){
  return "Grassland";
}

void Grassland::updateGrowth(){
  _growth =0;
  //std::cout << "Grassland growth\n";
}