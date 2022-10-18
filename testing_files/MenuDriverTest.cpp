#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Button.h"
#include "../Menu.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Menu Test");

  sf::Texture textureFile;

  if (!textureFile.loadFromFile("texture.png", sf::IntRect(0, 0, 192, 128))) {
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(192, 128);

  Menu menu(2, sf::Vector2f(150, 50), sf::Vector2i(50, 50), 2);

  Button b1;
  Button b2;

  sf::Sprite seeded;
  seeded.setTexture(textureFile);
  seeded.setTextureRect(sf::IntRect(64, 0, 32, 32));  // wheat seeded texture

  sf::Sprite fully;
  fully.setTexture(textureFile);
  fully.setTextureRect(sf::IntRect(96, 0, 32, 64));  // wheat fully texture
  fully.setOrigin(0, 32);

  b1.setSprite(seeded);
  b2.setSprite(fully);

  menu.setButton(0,b1);
  menu.setButton(1,b2);
  menu.setButtonPosition(0, 60,55);
  menu.setButtonPosition(1, 160,55);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();
    menu.draw(&window,false);
    window.display();
  }

  return 0;
}