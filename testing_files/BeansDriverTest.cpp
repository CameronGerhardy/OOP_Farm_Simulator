#include <SFML/Graphics.hpp>

#include "../Land.h"
#include "../Farmland.h"
#include "../Menu.h"
#include "../Player.h"
#include "../Bean.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Beans Test");
  //   sf::CircleShape shape(100.f);
  //   shape.setFillColor(sf::Color::Green);

  Bean b;

  Player* p = new Player;

  sf::Texture textureFile;

  if (!textureFile.loadFromFile("texture.png", sf::IntRect(0, 0, 192, 128))) {
    std::cout << "Cant load texture file\n";
  }
  textureFile.create(192, 128);

  b.setPosition(window.getSize().x / 2, window.getSize().x / 2);

  sf::Sprite seeded;
  seeded.setTexture(textureFile);
  seeded.setTextureRect(sf::IntRect(64, 32, 32, 32));  // Bean seeded texture

  sf::Sprite fully;
  fully.setTexture(textureFile);
  fully.setTextureRect(sf::IntRect(160, 0, 32, 64));  // Bean fully texture
  fully.setOrigin(0, 32);

  sf::Sprite half;
  half.setTexture(textureFile);
  half.setTextureRect(sf::IntRect(160, 64, 32, 64));  // Bean fully texture
  half.setOrigin(0, 32);

  b.PlantCrop(p);


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    b.updateGrowth();
    if (b.getGrowth() == 0) {
      b.setSprite(seeded);
    }
    if (b.getGrowth() == 1) {
      b.setSprite(half);
    }
    if (b.getGrowth() == 2) {
      b.setSprite(fully);
    }
    b.setPosition(6, 6);

    window.draw(b.getSprite());

    window.display();
  }
  return 0;
}