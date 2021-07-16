#include "PrototypeScene.h"
#include <string>



//Background stuff

Background::Background() {
	texture.loadFromFile("Assets/pixelated_halo_starfield_by_necro_skeletal_d56he85.png");
	sprite.setTexture(texture);
}

void Background::update(sf::Time dt) {}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(sprite, states);
}




//Scene stuff

PrototypeScene::PrototypeScene() {}

void PrototypeScene::update(sf::Time dt) {
	bg.update(dt);
}

void PrototypeScene::draw(sf::RenderWindow& window) {
	window.draw(bg);
}

