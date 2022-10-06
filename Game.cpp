#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>



using namespace sf;
Game::Game(int size, std::string title){
  Game::win = new RenderWindow(VideoMode(size,size),title);
  Game::player = new Player(5,10);
}

void Game::run(){
  CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Texture grass_t;
  grass_t.loadFromFile("grass.png",sf::IntRect(0, 0, 32, 32));

  grass_t.create(32,32);
  int rows = 5;
  int cols = 10;
  sf::Sprite grassTiles[rows][cols];
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < cols; c++){
      grassTiles[r][c].setTexture(grass_t);
      grassTiles[r][c].setPosition(32*c,32*r);
    }
  }
  //sf::Sprite grass_s;
  // grass_s.setTexture(grass_t);
  // grass_s.setPosition(0,0);
  // //grass_s.scale(2,2);


  while(win->isOpen()){
    Event e;
    while(win->pollEvent(e)){
      if(e.type == Event::Closed){
        win->close();
      }
    }

    win->clear();
    ////drawing to the screen///

    //draw grass
    //draw empty land
    //draw planted land
    //draw fully crown crop

    win->draw(shape);
    
    //win->draw(grass_s);
    for(int r = 0; r < rows; r++){
      for(int c = 0; c < cols; c++){
        win->draw(grassTiles[r][c]);
      }
    }
    ////////////////////////////
    win->display();
  }
}

Game::~Game(){
  delete Game::win;
}