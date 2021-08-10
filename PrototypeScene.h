// #pragma once

#ifndef PROTO
#define PROTO
#include "Scene.h"
#include "GameObject.h"
#include "AlienShip.h"
#include "Ship.h"
#include "PlanetarySystem.h"
#include "Asteroid.h"

const int SYSTEMOBJECTS = 13;





class Background : public GameObject {
public:
	Background();

	void update(sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};



class PrototypeScene : public Scene {
public:
	PrototypeScene();
	~PrototypeScene();

	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getCenter();

	// prototype collision methods
	void collision_check();
	bool hitbox_detection(Ship sh, Asteroid ast);
	bool hitbox_detection_2(Ship sh, Asteroid ast);
	bool hitbox_detection_3(Ship sh, Asteroid ast);

private:
	Background bg;
	AlienShip* alien;
	Star* sun;
	Planet** planetarySystemObjects;

	// collision type objects
	Ship ship;
	Asteroid asteroid;

	sf::Vector2f center;
	sf::View view;

	bool debug = true;

};
#endif