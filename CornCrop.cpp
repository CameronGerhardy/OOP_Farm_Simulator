#include "CornCrop.h"
#include "Land.h"
#include "Player.h"


Corn::Corn(){
    _landType = "Corn";
}

void Corn::PlantCrop(Player* p){
    timer.start();
    p->changeSeeds("Corn",p->getSeeds("Corn")-1);

    // square becomes used
}


}
void ImcrementXP(Player* p, int XP){
        p->incremXP(XP);    
        }

void Corn::HarvestCrop(Player* p){
    if(timer.elapsedSeconds() >= 240){
        p->changeSeeds("Corn",p->getSeeds("Corn")+2);
        // square becomes empty 
        ImcrementXP(p, 2);
        
    }
}
       