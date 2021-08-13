// Implements the demo scene

#include "PrototypeScene.h"
#include <string>



//Background stuff

Background::Background() {

	// These should be adjusted to use system-wide constants when those are implemented
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
// Some of the data members are dynamically allocated because constructors with arguments were written
PrototypeScene::PrototypeScene() {
	alien = new AlienShip();
	sun = new Star(30, sf::Color(219, 57, 5), 3, sf::Color(255, 154, 1), sf::Vector2f(-700, 200)); 

	planetarySystemObjects = new Planet*[SYSTEMOBJECTS];

	planetarySystemObjects[0] = new Planet(5, 100, sf::Color::Green, 0.5);
	planetarySystemObjects[1] = new Planet(8, 140, sf::Color::Blue, 0.05);
	planetarySystemObjects[2] = new Planet(10, 180, sf::Color::Magenta, 0.25);
	planetarySystemObjects[3] = new Planet(4, 200, sf::Color::Yellow, 0.04);
	planetarySystemObjects[4] = new Planet(50, 350, sf::Color::Cyan, 0.045);
	planetarySystemObjects[5] = new Planet(25, 460, sf::Color::Green, 0.09);
	planetarySystemObjects[6] = new Planet(10, 500, sf::Color::Blue, 0.03);
	planetarySystemObjects[7] = new Planet(10, 540, sf::Color::Yellow, 0.2);
	planetarySystemObjects[8] = new Planet(3, 600, sf::Color::Yellow, 0.15);
	planetarySystemObjects[9] = new Planet(2, 15, sf::Color::White, 0.5);
	planetarySystemObjects[10] = new Planet(2, 10, sf::Color::White, 0.15);
	planetarySystemObjects[11] = new Planet(2, 30, sf::Color::White, 0.6);
	planetarySystemObjects[12] = new Planet(1, 17, sf::Color::White, 0.9);

	view.setSize(System.getData("DesktopX"), System.getData("DesktopY"));
}



// Destruct the alien, sun, and planets
PrototypeScene::~PrototypeScene() {
	delete alien;
	delete sun;
	for(int i = 0; i < SYSTEMOBJECTS; ++i) {
		delete planetarySystemObjects[i];
	}
}



// Update data members that get updated
void PrototypeScene::update(sf::Time dt) {
	
	// Key press checks
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
		System.window.create(System.videoMode, "FarOut");
	}
    
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
		System.window.create(System.videoMode, "FarOut", sf::Style::Fullscreen);
	}

	bg.update(dt);
	ship.update(dt);
	alien->update(dt, ship.getPosition());
	asteroid.update(dt);
	sun->update(dt);
	sf::Vector2f center = sun->getPosition();
	
	for (int i = 0; i < 9; ++i) {
		planetarySystemObjects[i]->update(dt, center);
	}
	planetarySystemObjects[9]->update(dt, planetarySystemObjects[6]->getPosition());
	planetarySystemObjects[10]->update(dt, planetarySystemObjects[3]->getPosition());
	planetarySystemObjects[11]->update(dt, planetarySystemObjects[8]->getPosition());
	planetarySystemObjects[12]->update(dt, planetarySystemObjects[11]->getPosition());
	view.setCenter(ship.getPosition());
}



// Draw all the objects in the scene
void PrototypeScene::draw(sf::RenderWindow& window) {
	window.setView(view);
	window.draw(bg);
	window.draw(ship);
	window.draw(*alien);
	window.draw(*sun);
	for (int i = 0; i < SYSTEMOBJECTS; ++i) {
		window.draw(*planetarySystemObjects[i]);
	}
	window.draw(asteroid);
}



// Here so the system class can call something to know where the ship is for window.setCenter()
sf::Vector2f PrototypeScene::getCenter(){
	return ship.getPosition();
}