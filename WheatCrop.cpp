#include "WheatCrop.h"
#include "Land.h"
#include "Player.h"
#include "Timer.h"
#include "Farmland.h"


void Wheat::PlantCrop(Player* p){
    timer.start();
    p->changeSeeds("Wheat",p->getSeeds("Wheat")-1);

    // square becomes used
}

void Wheat::IncrementXP(Player* p, int XP){
        p->incremXP(XP);    
}

void Wheat::HarvestCrop(Player* p){
    if(Farmland::_growth ==2){
        p->changeSeeds("Wheat",p->getSeeds("Wheat")+2);
        // square becomes empty 
        IncrementXP(p, 2);
        
    }
}

std::string Wheat::getLandType(){
    return "Wheat Crop";
}

void Wheat::updateGrowth(){
    if(timer.elapsedSeconds() > 60){
        Farmland::_growth = 1;
    }else if(timer.elapsedSeconds() > 120){
        Farmland::_growth = 2;
        timer.stop();
    }
}