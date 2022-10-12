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
    
class Wheat: Land{

    private: 
        int WheatQuanity;
        Timer timer;

    public:
        
        
        Wheat();

        int get_number_of_wheat_seeds();
        void ImcrementXP(*Player p, int XP);
    
         
};  
 
#endif