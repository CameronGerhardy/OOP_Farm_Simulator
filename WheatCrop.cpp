#include "WheatCrop.h"
#include "Land.h"
#include "player.h"


Wheat::Wheat(){
    _landType = "Wheat";
}

void Wheat::PlantCrop(){
    timer.Start();
    WheatQuantity = WheatQuanity-1;
    // square becomes used
}


int Wheat::get_number_of_wheat_seeds(){
    return WheatQuanity;
}
void ImcrementXP(*Player p, int XP){
        p->incremXP(XP);    
        }

void Wheat::HarvestCrop(){
    if(Timer::elapsedSeconds() >= 120){
        WheatQuantity = WheatQuantity+2;
        // square becomes empty 
        ImcrementXP(*Player p, int XP);
        
    }
}
       