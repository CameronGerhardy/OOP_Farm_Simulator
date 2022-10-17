// bean seeds are unlocked at level 3
// beans take 10 minutes to grow 
// bean cost $10 a seed



#ifndef BeanCrop_H
#define BeanCrop_H
#include "Land.h"
#include <string>
#include "Timer.h"
#include "Farmland.h"
using namespace std;
    
    
class Bean : public Farmland{

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