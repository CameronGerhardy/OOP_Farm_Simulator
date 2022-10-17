#include "WheatCrop.h"
#include "Land.h"
#include "Player.h"
#include "Timer.h"
#include "Farmland.h"
#include <iostream>


void Wheat::PlantCrop(Player* p){
    timer.start();
    _growth = 0;
    int currSeeds = p->getSeeds("Wheat");
    std::cout <<  p->getSeeds("Wheat") << endl;
    p->changeSeeds("Wheat",currSeeds-1);
    std::cout <<  p->getSeeds("Wheat") << endl;

    // square becomes used
}

void Wheat::IncrementXP(Player* p, int XP){
        p->incremXP(XP);    
}

void Wheat::HarvestCrop(Player* p){
    if(_growth ==2){
        p->changeSeeds("Wheat",p->getSeeds("Wheat")+2);
        // square becomes empty 
        IncrementXP(p, 2);
        
    }
}

std::string Wheat::getLandType(){
    return "Wheat Crop";
}

void Wheat::updateGrowth(){
    if(timer.elapsedSeconds() > 1){
        _growth = 1;
    }if(timer.elapsedSeconds() > 2){
        // std::cout << "Wheat Crop fully\n";
        _growth = 2;
        timer.stop();
    }
    
}