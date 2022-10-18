// the corn crop takes 4 mins to grown 
// each seed planted doubles
// at one 2 the crop will be half grown 
// this is the second crop
// these cost $4 a seed

#ifndef CornCrop_H
#define CornCrop_H
#include "Land.h"
#include <string>
#include "Timer.h"
#include "Farmland.h"
using namespace std;
    
    
class Corn : public Farmland{

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