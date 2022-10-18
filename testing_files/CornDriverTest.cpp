#include <SFML/Graphics.hpp>

#include "../Land.h"
#include "../Farmland.h"
#include "../Menu.h"
#include "../Player.h"
#include "../CornCrop.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Corn Test");
  //   sf::CircleShape shape(100.f);
  //   shape.setFillColor(sf::Color::Green);

  Corn c;

  Player* p = new Player;

  sf::Texture textureFile;

  if (!textureFile.loadFromFile("texture.png", sf::IntRect(0, 0, 192, 128))) {
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(192, 128);

  c.setPosition(window.getSize().x / 2, window.getSize().x / 2);

  sf::Sprite seeded;
  seeded.setTexture(textureFile);
  seeded.setTextureRect(sf::IntRect(64, 64, 32, 32));  // Corn seeded texture

  sf::Sprite fully;
  fully.setTexture(textureFile);
  fully.setTextureRect(sf::IntRect(128, 0, 32, 64));  // Corn fully texture
  fully.setOrigin(0, 32);

  sf::Sprite half;
  half.setTexture(textureFile);
  half.setTextureRect(sf::IntRect(128, 64, 32, 64));  // Corn fully texture
  half.setOrigin(0, 32);

  c.PlantCrop(p);


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    c.updateGrowth();
    if (c.getGrowth() == 0) {
      c.setSprite(seeded);
    }
    if (c.getGrowth() == 1) {
      c.setSprite(half);
    }
    if (c.getGrowth() == 2) {
      c.setSprite(fully);
    }
    c.setPosition(6, 6);

    window.draw(c.getSprite());

    window.display();
  }
  return 0;
}