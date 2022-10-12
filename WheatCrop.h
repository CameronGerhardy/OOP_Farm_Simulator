// the wheat crop takes 2 mins to grown 
// each seed planted doubles
// at one minute the crop will be half grown 
// this is the bigining crop
// these cost $2 a seed


#ifndef WheatCrop_H
#define WheatCrop_H
#include "Land.h"
#include <string>
#include "Timer.cpp"
using namespace std;
    
class Wheat : public Land{

    private: 
        Timer timer;

    public:

        std::string getLandType();
        
        void IncrementXP(Player* p, int XP);

        virtual void HarvestCrop(Player* p); 
        virtual void PlantCrop(Player* p); 
         
};  
 
#endif