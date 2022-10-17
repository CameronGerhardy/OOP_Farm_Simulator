// the wheat crop takes 2 mins to grown 
// each seed planted doubles
// at one minute the crop will be half grown 
// this is the bigining crop
// these cost $2 a seed


#ifndef WheatCrop_H
#define WheatCrop_H
#include "Land.h"
#include <string>
#include "Timer.h"
#include "Farmland.h"
using namespace std;
    
class Wheat : public Farmland{

    private: 
        Timer timer;


    public:

        std::string getLandType();
        
        void IncrementXP(Player* p, int XP);

        void HarvestCrop(Player* p); 
        void PlantCrop(Player* p); 

        void updateGrowth();
};  
 
#endif