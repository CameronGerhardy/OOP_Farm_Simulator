#include <SFML/Graphics.hpp>

#include "../Land.h"
#include "../Farmland.h"
#include "../Menu.h"
#include "../Player.h"
#include "../WheatCrop.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Wheat test");
  //   sf::CircleShape shape(100.f);
  //   shape.setFillColor(sf::Color::Green);

  Wheat w;

  Player* p = new Player;

  sf::Texture textureFile;

  if (!textureFile.loadFromFile("texture.png", sf::IntRect(0, 0, 192, 128))) {
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(192, 128);

  w.setPosition(window.getSize().x / 2, window.getSize().x / 2);

  sf::Sprite seeded;
  seeded.setTexture(textureFile);
  seeded.setTextureRect(sf::IntRect(64, 0, 32, 32));  // wheat seeded texture

  sf::Sprite fully;
  fully.setTexture(textureFile);
  fully.setTextureRect(sf::IntRect(96, 0, 32, 64));  // wheat fully texture
  fully.setOrigin(0, 32);

  sf::Sprite half;
  half.setTexture(textureFile);
  half.setTextureRect(sf::IntRect(96, 64, 32, 64));  // wheat fully texture
  half.setOrigin(0, 32);

  w.PlantCrop(p);


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    w.updateGrowth();
    if (w.getGrowth() == 0) {
      w.setSprite(seeded);
      w.setPosition(6, 6);
    }
    if (w.getGrowth() == 1) {
      w.setSprite(half);
      w.setPosition(6, 6);
    }
    if (w.getGrowth() == 2) {
      w.setSprite(fully);
      w.setPosition(6, 6);
    }

    window.draw(w.getSprite());

    window.display();
  }
  return 0;
}