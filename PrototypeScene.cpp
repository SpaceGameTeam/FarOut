#include "PrototypeScene.h"
#include <string>



//Background stuff

Background::Background() {

	// These should be adjusted to use system wide constants when those are implemented
	int x = 1920;
	int y = 1080;
	int universeSize = 1000;
	texture.loadFromFile("Assets/pixelated_halo_starfield_by_necro_skeletal_d56he85.png");
	texture.setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, universeSize * x, universeSize * y));
	sprite.setTexture(texture, false);
	setPosition(-(universeSize * x / 2), -(universeSize * y / 2));
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

