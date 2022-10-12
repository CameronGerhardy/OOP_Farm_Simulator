// the corn crop takes 4 mins to grown 
// each seed planted doubles
// at one 2 the crop will be half grown 
// this is the second crop
// these cost $4 a seed

#ifndef CornCrop_H
#define CornCrop_H
#include "Land.h"
#include <string>
#include "Timer.cpp"
using namespace std;
    
class Corn : public Land{

    private: 
        Timer timer;

    public:
        
        
        Corn();

        void ImcrementXP(Player* p, int XP);

        virtual void HarvestCrop(Player* p); 
        virtual void PlantCrop(Player* p); 
         
};  
 
#endif