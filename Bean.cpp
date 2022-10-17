#include "Bean.h"
#include "Land.h"
#include "Player.h"
#include "Timer.h"
#include "Farmland.h"
#include <iostream>



void Bean::PlantCrop(Player* p){
    timer.start();
    _growth = 0;
    int currSeeds = p->getSeeds("Beans");
    p->changeSeeds("Beans",currSeeds-1);

    // square becomes used
}

void Bean::IncrementXP(Player* p, int XP){
        p->incremXP(XP);    
}

void Bean::HarvestCrop(Player* p){
    if(_growth ==2){

        p->changeSeeds("Beans",p->getSeeds("Beans")+2);
        // square becomes empty 
        IncrementXP(p, 2);
        
    }
}

std::string Bean::getLandType(){
    return "Bean Crop";
}

void Bean::updateGrowth(){
    if(timer.elapsedSeconds() > 1){
        _growth = 1;
    }if(timer.elapsedSeconds() > 2){
        _growth = 2;
        timer.stop();
    }
    //std::cout << "Bean crop Growth\n";
}
       