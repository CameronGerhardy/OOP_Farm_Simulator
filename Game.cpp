#include "Game.h"

#include <SFML/Graphics.hpp>
#include <iostream>
//#include "Player.h"

using namespace sf;
bool Game::inBoxes(int x, int y, int n){
  for(int i = 0; i < n; i++){
    if(boxes[i].contains(x,y)){
      return true;
    }
  }
  return false;
}
Game::Game(int width, int height, std::string title, std::string location,
           int sizeX, int sizeY) {
  //create window to display game
  win = new RenderWindow(VideoMode(width, height), title);

  //create player object
  player = new Player(95, 0);

  //set current state of screen
  screenState = "main";

  //prepare boxes for buttons and menus
  boxes = new sf::IntRect[5];

  //prepare menu rectangles
  rectangles = new sf::RectangleShape[2];
  int rectWidth = 170;
  int rectHeight = 65;    
  int borderSize = 4;

  //outer rect for toolbar
  rectangles[0].setSize(Vector2f(rectWidth,rectHeight));
  rectangles[0].setPosition(320 - rectWidth/2,480-rectHeight);
  rectangles[0].setFillColor(Color(40,40,40));

  //inner rect for toolbar
  rectangles[1].setSize(Vector2f(rectWidth - 2*borderSize,rectHeight - 2*borderSize));
  rectangles[1].setPosition(320 - rectWidth/2  + borderSize,480-rectHeight+borderSize);
  rectangles[1].setFillColor(Color(80,80,80));
    
  //setup font
  if (!font.loadFromFile("SHOWG.TTF")){
    std::cout << "Cant load font file\n";
  }

  //load texture containing all images
  if(!textureFile.loadFromFile(location, IntRect(0, 0, sizeX, sizeY))){
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(sizeX, sizeY);

  // convert texture to individual sprites
  sprites = new Sprite[8];
  for(int i = 0; i < 8; i++){
    sprites[i].setTexture(textureFile);
  }
  sprites[0].setTextureRect(IntRect(0,0,32,32));//grass texture
  sprites[1].setTextureRect(IntRect(32,0,32,32));//land texture
  sprites[2].setTextureRect(IntRect(64,0,32,32));//wheat seeded texture
  
  sprites[3].setTextureRect(IntRect(96,0,32,64));//wheat fully texture
  sprites[3].setOrigin(0,32);

  sprites[4].setTextureRect(IntRect(96,64,32,64));//wheat half texture
  sprites[4].setOrigin(0,32);

  sprites[5].setTextureRect(IntRect(0,32,32,32));//seed icon texture
  sprites[6].setTextureRect(IntRect(32,32,32,32));//coin texture
  sprites[7].setTextureRect(IntRect(0,64,32,32));//scythe texture

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
  Sprite fully_s;
  fully_s = sprites[3];

  Sprite half_s;
  half_s = sprites[4];


  while (win->isOpen()) {
    Event event;
    while (win->pollEvent(event)) {
      if (event.type == Event::Closed) {
        win->close();
      }
      // if (event.type == Event::KeyPressed) {
      //   if (event.key.code == Keyboard::Escape) {
      //     std::cout << "the escape key was pressed" << std::endl;
      //     std::cout << "control:" << event.key.control << std::endl;
      //     std::cout << "alt:" << event.key.alt << std::endl;
      //     std::cout << "shift:" << event.key.shift << std::endl;
      //     std::cout << "system:" << event.key.system << std::endl;
      //   }
      // }
      if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
          if(screenState == "seeds"){

          }else{
            if(1){
              int Mx = event.mouseButton.x;
              int My = event.mouseButton.y;
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
        }
      if (event.mouseButton.button == Mouse::Right) {
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
      // if (event.type == Event::MouseMoved) {
      //   std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
      //   std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
      // }
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
    Text XPText;
    XPText.setFont(font);
    XPText.setString(std::to_string(player->getXP()));
    XPText.setCharacterSize(50);
    XPText.setFillColor(Color::White);
    //set local origin to centre of text
    FloatRect XPText_Bounds = XPText.getLocalBounds();
    XPText.setOrigin(XPText_Bounds.width/2,XPText_Bounds.height/2);

    XPText.setPosition(320,XPText_Bounds.height/2);
    win->draw(XPText);

    //draw coins logo
    int coinHeight = 125;
    Sprite coinLogo;
    coinLogo = sprites[6];
    coinLogo.setOrigin(16,16);
    coinLogo.scale(1.5,1.5);
    coinLogo.setPosition(600,coinHeight);
    ;
    win->draw(coinLogo);
    //draw coins amount
    Text CoinsText;
    CoinsText.setFont(font);
    CoinsText.setString(std::to_string(player->getCoins()));
    CoinsText.setCharacterSize(30);
    CoinsText.setFillColor(Color::Yellow);
    //set local origin to right side
    FloatRect CoinsText_Bounds = CoinsText.getLocalBounds();
    CoinsText.setOrigin(CoinsText_Bounds.width,CoinsText_Bounds.height/2);
    CoinsText.setPosition(575,coinHeight);
    win->draw(CoinsText);

    //draw toolbar rectangle
    win->draw(rectangles[0]);
    win->draw(rectangles[1]);

    //draw toolbar icons
    Sprite scythe_s = sprites[7];
    scythe_s.setPosition(250,420);
    scythe_s.setScale(1.5,1.5);
    win->draw(scythe_s);
    Sprite seeds_s = sprites[5];
    seeds_s.setPosition(350,420);
    seeds_s.setScale(1.5,1.5);
    win->draw(seeds_s);
    

    ////////////////////////////

    //update the window
    win->display();
  }
}

Game::~Game() {
  delete player;

  //delete all the land objects
  for(int r = 0; r < rows; r++){
    delete land[r];
  }
  delete land;

  delete sprites;
  delete win;
}