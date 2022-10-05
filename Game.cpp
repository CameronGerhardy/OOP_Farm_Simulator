#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>


using namespace sf;
Game::Game(int size, std::string title){
  Game::win = new RenderWindow(VideoMode(size,size),title);
}

void Game::run(){
  while(win->isOpen()){
    Event e;
    while(win->pollEvent(e)){
      if(e.type == Event::Closed){
        win->close();
      }
    }

    win->clear();
    win->display();
  }
}

Game::~Game(){
  delete Game::win;
}