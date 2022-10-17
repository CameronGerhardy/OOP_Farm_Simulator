#include "Timer.cpp"



#include <iostream>
int main()
{
    Timer t;
  t.start();
  std::cout << "Hello, World\n";
  std::cin.ignore();
  t.stop();
  std::cout << t.elapsedSeconds() << std::endl;
  return 0;
}