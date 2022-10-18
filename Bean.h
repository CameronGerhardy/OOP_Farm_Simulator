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
        // returns conditon of land
        std::string getLandType();
        
        //increments the XP
        void IncrementXP(Player* p, int XP);

        // if conditions are met will harvest the crop
        void HarvestCrop(Player* p); 

        //if conditions are met will plant the crop
        void PlantCrop(Player* p); 

        //used to update the visuals of thr land square according to the land growth
        void updateGrowth();
};  
 
#endif