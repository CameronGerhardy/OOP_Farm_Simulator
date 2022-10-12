#include "WheatCrop.h"
#include "Land.h"
#include "player.h"


Wheat::Wheat(){
    _landType = "Wheat";
}

void Wheat::PlantCrop(){
    Timer::Start();
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
    if(Timer::GetDuration() >= 120){
        WheatQuantity = WheatQuantity+2;
        // square becomes empty 
        delete Timer;
        ImcrementXP(*Player p, int XP);
        
    }
}
       