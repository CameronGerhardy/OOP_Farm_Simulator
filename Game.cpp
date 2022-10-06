#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Player.h"

using namespace sf;
Game::Game(int width, int height, std::string title, std::string location,
           int sizeX, int sizeY) {
  Game::win = new RenderWindow(VideoMode(width, height), title);
  Game::player = new Player(5, 10);
  textureFile.loadFromFile(location, sf::IntRect(0, 0, sizeX, sizeY));
  textureFile.create(sizeX, sizeY);
}

void Game::run() {
  CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  int rows = win->getSize().y / 32;
  int cols = win->getSize().x / 32;
  sf::Sprite grassTiles[rows][cols];
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grassTiles[r][c].setTexture(textureFile);
      grassTiles[r][c].setPosition(32 * c, 32 * r);
    }
  }
  // sf::Sprite grass_s;
  //  grass_s.setTexture(grass_t);
  //  grass_s.setPosition(0,0);
  //  //grass_s.scale(2,2);

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
        if (event.mouseButton.button == sf::Mouse::Right) {
          std::cout << "the right button was pressed" << std::endl;
          std::cout << "mouse x: " << event.mouseButton.x << std::endl;
          std::cout << "mouse y: " << event.mouseButton.y << std::endl;
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

    win->draw(shape);

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