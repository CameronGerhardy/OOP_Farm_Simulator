#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer{

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;

public:
    //starts timer
    void start();
    
    //stops timer
    void stop();
    
    //gets elapsed time in milliseconds
    double elapsedMilliseconds();
    
    //gets elapsed time in seconds
    double elapsedSeconds();

};
