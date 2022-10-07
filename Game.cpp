#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Player.h"

using namespace sf;
Game::Game(int width, int height, std::string title, std::string location,
           int sizeX, int sizeY) {
  //create window to display game
  win = new RenderWindow(VideoMode(width, height), title);

  //create player object
  player = new Player(5, 10);

  //load texture containing all images
  textureFile.loadFromFile(location, sf::IntRect(0, 0, sizeX, sizeY));
  textureFile.create(sizeX, sizeY);

  // convert texture to individual sprites
  sprites = new sf::Sprite[8];
  for(int i = 0; i < 8; i++){
    sprites[i].setTexture(textureFile);
  }
  sprites[0].setTextureRect(sf::IntRect(0,0,32,32));//grass texture
  sprites[1].setTextureRect(sf::IntRect(32,0,64,32));//land texture
  sprites[2].setTextureRect(sf::IntRect(64,0,96,32));//wheat seeded texture

  sprites[3].setTextureRect(sf::IntRect(96,0,128,64));//wheat fully texture

  sprites[4].setTextureRect(sf::IntRect(96,64,128,128));//wheat half texture
  sprites[5].setTextureRect(sf::IntRect(0,32,32,64));//seed icon texture
  sprites[6].setTextureRect(sf::IntRect(32,32,64,364));//coin texture
  sprites[7].setTextureRect(sf::IntRect(0,64,32,96));//scythe texture

}

void Game::run() {
  // CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  // create 2d array of grass tiles
  int rows = win->getSize().y / 32;
  int cols = win->getSize().x / 32;
  sf::Sprite grassTiles[rows][cols];
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grassTiles[r][c] = sprites[0];
      grassTiles[r][c].setPosition(32 * c, 32 * r);
    }
  }

  
  sf::Sprite land_s;
  land_s = sprites[1];


  while (win->isOpen()) {
    Event event;
    while (win->pollEvent(event)) {
      if (event.type == Event::Closed) {
        win->close();
      }
      // if (event.type == sf::Event::KeyPressed) {
      //   if (event.key.code == sf::Keyboard::Escape) {
      //     std::cout << "the escape key was pressed" << std::endl;
      //     std::cout << "control:" << event.key.control << std::endl;
      //     std::cout << "alt:" << event.key.alt << std::endl;
      //     std::cout << "shift:" << event.key.shift << std::endl;
      //     std::cout << "system:" << event.key.system << std::endl;
      //   }
      // }
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          int Mx = event.mouseButton.x;
          int My = event.mouseButton.y;
          int TilePosX = Mx/(win->getSize().x/cols);
          int TilePosY = My/(win->getSize().y/rows);
          std::cout << "the Left button was pressed" << std::endl;
          std::cout << "mouse x: " << Mx << ", "<< TilePosX << std::endl;
          std::cout << "mouse y: " << My << ", "<< TilePosY << std::endl;
          std::cout << std::endl;

          grassTiles[TilePosY][TilePosX] = land_s;
          grassTiles[TilePosY][TilePosX].setPosition(TilePosX*32,TilePosY*32);
        }
      }
      // if (event.type == sf::Event::MouseMoved) {
      //   std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
      //   std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
      // }
    }

    win->clear();
    ////drawing to the screen///

    // draw grass
    // draw empty land
    // draw planted land
    // draw fully crown crop

    //win->draw(shape);

    // win->draw(grass_s);
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        win->draw(grassTiles[r][c]);
      }
    }
    ////////////////////////////
    win->display();
  }
}

Game::~Game() { delete Game::win; }