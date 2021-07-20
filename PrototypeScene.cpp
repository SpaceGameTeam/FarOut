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

PrototypeScene::PrototypeScene() {
	alien = new AlienShip(&ship);
	sun = new Star(2000, sf::Color(28, 57, 5), 3, sf::Color(255, 154, 1), sf::Vector2f(300, -10000));
	planet[0] = new Planet(50, 3000, sf::Color::Green, sun, 0.01);
	planet[1] = new Planet(80, 4000, sf::Color::Blue, sun, 0.001);
	planet[2] = new Planet(100, 5000, sf::Color::Magenta, sun, 0.005);
	planet[3] = new Planet(40, 8000, sf::Color::Yellow, sun, 0.001);
	planet[4] = new Planet(1000, 10000, sf::Color::Cyan, sun, 0.0009);
	planet[5] = new Planet(750, 15000, sf::Color::Green, sun, 0.0008);
	planet[6] = new Planet(300, 18000, sf::Color::Blue, sun, 0.0009);
	planet[7] = new Planet(300, 20000, sf::Color::Yellow, sun, 0.002);
	planet[8] = new Planet(30, 25000, sf::Color::Yellow, sun, 0.003);
}



PrototypeScene::~PrototypeScene() {
	delete alien;
	delete sun;
	for (int i = 0; i < PLANETS; ++i){
		delete planet[i];
	}
}



void PrototypeScene::move(sf::Time dt){
	ship.move(dt);
	alien->move(dt);
	asteroid.move(dt);
}



void PrototypeScene::update(sf::Time dt) {
	bg.update(dt);
	ship.update(dt);
	alien->update(dt);
	asteroid.update(dt);
	sun->update(dt);
	planet[0]->update(dt);
	planet[1]->update(dt);
	planet[2]->update(dt);
	planet[3]->update(dt);
	planet[4]->update(dt);
	planet[5]->update(dt);
	planet[6]->update(dt);
	planet[7]->update(dt);
	planet[8]->update(dt);
}



void PrototypeScene::draw(sf::RenderWindow& window) {
	window.draw(bg);
	window.draw(ship);
	window.draw(*alien);
	window.draw(*sun);
	window.draw(*planet[0]);
	window.draw(*planet[1]);
	window.draw(*planet[2]);
	window.draw(*planet[3]);
	window.draw(*planet[4]);
	window.draw(*planet[5]);
	window.draw(*planet[6]);
	window.draw(*planet[7]);
	window.draw(*planet[8]);
	window.draw(asteroid);
}



sf::Vector2f PrototypeScene::getCenter(){
	return ship.getPosition();
}