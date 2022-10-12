#include "BeanCrop.h"
#include "Land.h"
#include "Player.h"


Bean::Bean(){
    _landType = "Bean";
}

void Bean::PlantCrop(Player* p){
    timer.start();
    p->changeSeeds("Bean",p->getSeeds("Bean")-1);

    // square becomes used
}


}
void ImcrementXP(Player* p, int XP){
        p->incremXP(XP);    
        }

void Corn::HarvestCrop(Player* p){
    if(timer.elapsedSeconds() >= 600){
        p->changeSeeds("Bean",p->getSeeds("Bean")+2);
        // square becomes empty 
        ImcrementXP(p, 2);
        
    }
}
       