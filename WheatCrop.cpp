#include "Wheat.h"

void Wheat::Wheat(){

}

Wheat::PlantCrop(){
    Timer::Start()
    WheatQuantity = WheatQuanity-1;
    // square becomes used
}


int Wheat::get_number_of_wheat_seeds(){
    return WheatQuanity;
}


HarvestCrop(){
    if(Timer::GetDuration() >= 120){
        WheatQuantity = WheatQuantity+2;
        // square becomes empty 
    }
}



 
        
        