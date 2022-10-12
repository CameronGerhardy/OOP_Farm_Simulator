#include "Game.h"
#include "Menu.h"
#include "Button.h"
#include "Land.h"
#include "Grassland.h"
#include "Farmland.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Player.h"

using namespace sf;
Game::Game(int width, int height, std::string title, std::string location,
           int sizeX, int sizeY) {
  //create window to display game
  win = new RenderWindow(VideoMode(width, height), title);

  //create player object
  player = new Player(0, 1);

  //set toolMode and seedMode
  toolMode = 0;
  seedMode = 0;

  //setup font
  if (!font.loadFromFile("SHOWG.TTF")){
    std::cout << "Cant load font file\n";
  }

  //load texture containing all images
  if(!textureFile.loadFromFile(location, sf::IntRect(0, 0, sizeX, sizeY))){
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(sizeX, sizeY);

  /* #region convert texture to individual sprites*/
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
  /* #endregion */

  /* #region setup toolbar*/
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
  /* #endregion */

  /* #region setup seedbar*/
  //setup seedbar
  rectWidth = 400;
  rectHeight = 150;
  borderSize = 4;
  seedbar = new Menu(3,sf::Vector2f(rectWidth,rectHeight),sf::Vector2i(320-rectWidth/2,480-rectHeight - 65),borderSize);
  seedbar->setButton(0,Button(sprites[5]));//seed
  seedbar->setButtonPosition(0,180,305);
  seedbar->setButtonScale(0,2.5,2.5);
  sf::Text t1;
  t1.setFont(font);
  t1.setFillColor(sf::Color::Black);
  t1.setCharacterSize(20);
  t1.setString(std::to_string(player->getSeeds("Wheat")));
  t1.setOrigin(t1.getLocalBounds().width/2, t1.getLocalBounds().height/2);
  t1.setPosition(210,395);
  seedbar->setText(0,t1);

  seedbar->setButton(1,Button(sprites[5]));//seed
  seedbar->setButtonPosition(1,300,305);
  seedbar->setButtonScale(1,2.5,2.5);
  sf::Text t2;
  t2.setFont(font);
  t2.setFillColor(sf::Color::Black);
  t2.setCharacterSize(20);
  t2.setString(std::to_string(player->getSeeds("Corn")));
  t2.setOrigin(t2.getLocalBounds().width/2, t2.getLocalBounds().height/2);
  t2.setPosition(330,395);
  seedbar->setText(1,t2);

  seedbar->setButton(2,Button(sprites[5]));//seed
  seedbar->setButtonPosition(2,420,305);
  seedbar->setButtonScale(2,2.5,2.5);
  sf::Text t3;
  t3.setFont(font);
  t3.setFillColor(sf::Color::Black);
  t3.setCharacterSize(20);
  t3.setString(std::to_string(player->getSeeds("Beans")));
  t3.setOrigin(t3.getLocalBounds().width/2, t3.getLocalBounds().height/2);
  t3.setPosition(450,395);
  seedbar->setText(2,t3);
  /* #endregion */

  /* #region create 2d array of grass tiles */
  // create 2d array of grass tiles
  rows = win->getSize().y / 32;
  cols = win->getSize().x / 32;
  land = new Land*[rows];
  for (int r = 0; r < rows; r++) {
    land[r] = new Grassland[cols];
    for (int c = 0; c < cols; c++) {
      // set them all to grass tiles and set the positions of them
      land[r][c].setSprite(sprites[0]);
      land[r][c].setPosition(c,r);
    }
  }
  // place first 2 land tiles
  Farmland f1;
  land[rows/2][cols/2] = f1;
  land[rows/2][cols/2].setSprite(sprites[1]);
  land[rows/2][cols/2].setPosition(cols/2, rows/2);

  Farmland f2;
  land[rows/2 +1 ][cols/2 + 1] = f2;
  land[rows/2 +1 ][cols/2 + 1].setSprite(sprites[1]);
  land[rows/2 + 1][cols/2 + 1].setPosition(cols/2 + 1, rows/2 + 1);
  /* #endregion */

}

void Game::run() {
  sf::Sprite fully_s;
  fully_s = sprites[3];

  sf::Sprite half_s;
  half_s = sprites[4];

  sf::Sprite seed_s;
  seed_s = sprites[2];


  while (win->isOpen()) {
    //event handler
    Event event;
    while (win->pollEvent(event)) {
      if (event.type == Event::Closed) {
        win->close();
      }

      if (event.type == sf::Event::MouseButtonPressed) {
        mouseX = event.mouseButton.x;
        mouseY = event.mouseButton.y;
        //left mouse button clicked
        if (event.mouseButton.button == sf::Mouse::Left) {
          //if user clicks in toobar
          if(toolbar->isInside(mouseX,mouseY)){
            std::cout << "inside Click\n";

            //if user clicks on scythe button while toolbar open
            if(toolbar->isClicked(0,mouseX,mouseY)){
              std::cout << "Scythe clicked\n";
              if(toolMode == 1){toolMode = 0;}else{toolMode=1;}
             
            }

            //if user clicks on seed button
            if(toolbar->isClicked(1,mouseX,mouseY)){
              std::cout << "Seeds clicked\n";
              if(toolMode == 2){toolMode = 0;}else{toolMode=2;}
            }
          
          // if user doesn't click on toolbar
          }else{
            int TilePosX = mouseX/(win->getSize().x/cols);
            int TilePosY = mouseY/(win->getSize().y/rows);
            if(toolMode == 1 && land[TilePosY][TilePosX].getLandType() == "Land"){
              
              // std::cout << "the Left button was pressed" << std::endl;
              // std::cout << "mouse x: " << mouseX << ", "<< TilePosX << std::endl;
              // std::cout << "mouse y: " << mouseY << ", "<< TilePosY << std::endl;
              // std::cout << std::endl;

              land[TilePosY][TilePosX].setSprite(seed_s);
              land[TilePosY][TilePosX].setPosition(TilePosX,TilePosY);
            }
            
          }
        }
        // mouse right clicks
        if (event.mouseButton.button == sf::Mouse::Right) {
          int mouseX = event.mouseButton.x;
          int mouseY = event.mouseButton.y;
          int TilePosX = mouseX/(win->getSize().x/cols);
          int TilePosY = mouseY/(win->getSize().y/rows);
          // std::cout << "the Right button was pressed" << std::endl;
          // std::cout << "mouse x: " << mouseX << ", "<< TilePosX << std::endl;
          // std::cout << "mouse y: " << mouseY << ", "<< TilePosY << std::endl;
          // std::cout << std::endl;

          player->incremCoins(1);

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
    
    /* #region draw XP amount */
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
    /* #endregion */

    /* #region draw coins logo */
    int coinHeight = 125;
    sf::Sprite coinLogo = sprites[6];
    coinLogo.setOrigin(16,16);
    coinLogo.scale(1.5,1.5);
    coinLogo.setPosition(600,coinHeight);
    win->draw(coinLogo);
    /* #endregion */
    
    /* #region draw coins amount */
    Text CoinsText;
    CoinsText.setFont(font);
    CoinsText.setString(std::to_string(player->getCoins()));
    CoinsText.setCharacterSize(30);
    CoinsText.setFillColor(sf::Color::Yellow);
    //set local origin to right side
    sf::FloatRect CoinsText_Bounds = CoinsText.getLocalBounds();
    CoinsText.setOrigin(CoinsText_Bounds.width,CoinsText_Bounds.height/2);
    CoinsText.setPosition(575,coinHeight);
    win->draw(CoinsText);
    /* #endregion */

    //draw toolbar
    if(1){//toolMode == 0 || toolMode == 1){
      toolbar->draw(win,false);
    }
    
    //draw seedbar
    if(toolMode == 2){
      seedbar->draw(win,true);
    }
    

    /* #region scythe overlay */
    Sprite scythe = sprites[7];
    if(toolMode == 1){
      //std::cout << toolMode << std::endl;
      scythe.setPosition(Mouse::getPosition(*win).x,Mouse::getPosition(*win).y);
      //scythe.setPosition(mouseX,mouseY);
    }else{scythe.setPosition(0,0);}
    win->draw(scythe);
    /* #endregion */

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