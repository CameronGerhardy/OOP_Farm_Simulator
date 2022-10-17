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
using namespace std;
    
    
class Corn : public Farmland{

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