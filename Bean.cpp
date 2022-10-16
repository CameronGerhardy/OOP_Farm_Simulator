#include "Bean.h"
#include "Land.h"
#include "Player.h"
#include "Timer.h"



void Bean::PlantCrop(Player* p){
    timer.start();
    p->changeSeeds("Bean",p->getSeeds("Bean")-1);

    // square becomes used
}


void Bean::ImcrementXP(Player* p, int XP){
        p->incremXP(XP);    
}

void Bean::HarvestCrop(Player* p){
    if(timer.elapsedSeconds() >= 600){
        p->changeSeeds("Bean",p->getSeeds("Bean")+2);
        // square becomes empty 
        ImcrementXP(p, 3);
        
    }
}

std::string Bean::getLandType(){
    return "Bean Crop";
}
      
       