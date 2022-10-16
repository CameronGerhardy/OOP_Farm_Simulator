// bean seeds are unlocked at level 3
// beans take 10 minutes to grow 
// bean cost $10 a seed



#ifndef BeanCrop_H
#define BeanCrop_H
#include "Land.h"
#include <string>
#include "Timer.h"
using namespace std;
    
class Bean : public Land{

    private: 
        Timer timer;

    public:
        
        
        std::string getLandType();
        void ImcrementXP(Player* p, int XP);

        virtual void HarvestCrop(Player* p); 
        virtual void PlantCrop(Player* p); 
         
};  
 
#endif