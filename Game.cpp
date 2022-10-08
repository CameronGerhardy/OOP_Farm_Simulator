#include "Game.h"
#include "Menu.h"
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Player.h"

using namespace sf;
Game::Game(int width, int height, std::string title, std::string location,
           int sizeX, int sizeY) {
  //create window to display game
  win = new RenderWindow(VideoMode(width, height), title);

  //create player object
  player = new Player(95, 0);

  //setup font
  if (!font.loadFromFile("SHOWG.TTF")){
    std::cout << "Cant load font file\n";
  }

  //load texture containing all images
  if(!textureFile.loadFromFile(location, sf::IntRect(0, 0, sizeX, sizeY))){
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(sizeX, sizeY);

  // convert texture to individual sprites
  sprites = new sf::Sprite[8];
  for(int i = 0; i < 8; i++){
    sprites[i].setTexture(textureFile);
  }
  sprites[0].setTextureRect(sf::IntRect(0,0,32,32));//grass texture
  sprites[1].setTextureRect(sf::IntRect(32,0,32,32));//land texture
  sprites[2].setTextureRect(sf::IntRect(64,0,32,32));//wheat seeded texture
  
  sprites[3].setTextureRect(sf::IntRect(96,0,32,64));//wheat fully texture
  sprites[3].setOrigin(0,32);

  sprites[4].setTextureRect(sf::IntRect(96,64,32,64));//wheat half texture
  sprites[4].setOrigin(0,32);

  sprites[5].setTextureRect(sf::IntRect(0,32,32,32));//seed icon texture
  sprites[6].setTextureRect(sf::IntRect(32,32,32,32));//coin texture
  sprites[7].setTextureRect(sf::IntRect(0,64,32,32));//scythe texture

  //setup toolbar
  int rectWidth = 170;
  int rectHeight = 65;
  int borderSize = 4;
  toolbar = new Menu(2,sf::Vector2f(rectWidth,rectHeight),sf::Vector2i(320-rectWidth/2,480-rectHeight),borderSize);
  toolbar->setButton(0,Button(sprites[7]));//scythe
  toolbar->setButtonPosition(0,250,430);
  toolbar->setButtonScale(0,1.5,1.5);
  toolbar->setButton(1,Button(sprites[5]));//seed
  toolbar->setButtonPosition(1,360,430);
  toolbar->setButtonScale(1,1.5,1.5);

  // create 2d array of land tiles
  rows = win->getSize().y / 32;
  cols = win->getSize().x / 32;
  land = new Land*[rows];

  for (int r = 0; r < rows; r++) {
    land[r] = new Land[cols];
    for (int c = 0; c < cols; c++) {
      // set them all to grass tiles and set the positions of them
      land[r][c].setSprite(sprites[0]);
      land[r][c].setPosition(c,r);
    }
  }

}

void Game::run() {
  sf::Sprite fully_s;
  fully_s = sprites[3];

  sf::Sprite half_s;
  half_s = sprites[4];


  while (win->isOpen()) {
    Event event;
    while (win->pollEvent(event)) {
      if (event.type == Event::Closed) {
        win->close();
      }

      if (event.type == sf::Event::MouseButtonPressed) {
        int Mx = event.mouseButton.x;
        int My = event.mouseButton.y;
        if (event.mouseButton.button == sf::Mouse::Left) {

          if(toolbar->isInside(Mx,My)){
            std::cout << "inside Click\n";
          }else{
            int TilePosX = Mx/(win->getSize().x/cols);
            int TilePosY = My/(win->getSize().y/rows);
            std::cout << "the Left button was pressed" << std::endl;
            std::cout << "mouse x: " << Mx << ", "<< TilePosX << std::endl;
            std::cout << "mouse y: " << My << ", "<< TilePosY << std::endl;
            std::cout << std::endl;

            land[TilePosY][TilePosX].setSprite(fully_s);
            land[TilePosY][TilePosX].setPosition(TilePosX,TilePosY);
          }
        }
      if (event.mouseButton.button == sf::Mouse::Right) {
          int Mx = event.mouseButton.x;
          int My = event.mouseButton.y;
          int TilePosX = Mx/(win->getSize().x/cols);
          int TilePosY = My/(win->getSize().y/rows);
          std::cout << "the Right button was pressed" << std::endl;
          std::cout << "mouse x: " << Mx << ", "<< TilePosX << std::endl;
          std::cout << "mouse y: " << My << ", "<< TilePosY << std::endl;
          std::cout << std::endl;

          player->incremCoins();

          land[TilePosY][TilePosX].setSprite(half_s);
          land[TilePosY][TilePosX].setPosition(TilePosX,TilePosY);
        }
      }
    }
    //clear the window
    win->clear();

    ////drawing to the screen///
    ////////////////////////////

    //draw all land objects to the screen
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        win->draw(land[r][c].getSprite());
      }
    }

    /////draw Overlay
    /////////////////
    
    //draw XP amount
    sf::Text XPText;
    XPText.setFont(font);
    XPText.setString(std::to_string(player->getXP()));
    XPText.setCharacterSize(50);
    XPText.setFillColor(sf::Color::White);
    //set local origin to centre of text
    sf::FloatRect XPText_Bounds = XPText.getLocalBounds();
    XPText.setOrigin(XPText_Bounds.width/2,XPText_Bounds.height/2);

    XPText.setPosition(320,XPText_Bounds.height/2);
    win->draw(XPText);

    //draw coins logo
    int coinHeight = 125;
    sf::Sprite coinLogo;
    coinLogo = sprites[6];
    coinLogo.setOrigin(16,16);
    coinLogo.scale(1.5,1.5);
    coinLogo.setPosition(600,coinHeight);
    
    win->draw(coinLogo);
    //draw coins amount
    sf::Text CoinsText;
    CoinsText.setFont(font);
    CoinsText.setString(std::to_string(player->getCoins()));
    CoinsText.setCharacterSize(30);
    CoinsText.setFillColor(sf::Color::Yellow);
    //set local origin to right side
    sf::FloatRect CoinsText_Bounds = CoinsText.getLocalBounds();
    CoinsText.setOrigin(CoinsText_Bounds.width,CoinsText_Bounds.height/2);
    CoinsText.setPosition(575,coinHeight);
    win->draw(CoinsText);

    //draw toolbar
    toolbar->draw(win);

    ////////////////////////////

    //update the window
    win->display();
  }
}

Game::~Game() {
  delete player;

  //delete all the land objects
  for(int r = 0; r < rows; r++){
    delete[] land[r];
  }
  delete[] land;

  delete[] sprites;
  delete win;
}