#include "WheatCrop.h"
#include "Land.h"
#include "Player.h"


Wheat::Wheat(){
    _landType = "Wheat";
}

void Wheat::PlantCrop(Player* p){
    timer.start();
    p->changeSeeds("Wheat",p->getSeeds("Wheat")-1);

    // square becomes used
}


int Wheat::get_number_of_wheat_seeds(){
    return 0;//WheatQuantity;
}
void ImcrementXP(Player* p, int XP){
        p->incremXP(XP);    
        }

void Wheat::HarvestCrop(Player* p){
    if(timer.elapsedSeconds() >= 120){
        p->changeSeeds("Wheat",p->getSeeds("Wheat")+2);
        // square becomes empty 
        ImcrementXP(p, 2);
        
    }
}
       