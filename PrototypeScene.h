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

private:
	Background bg;
	Ship ship;
	AlienShip* alien;
	Star* sun;
	Planet** planetarySystemObjects;
	/*
	Star* sun;
	Planet* a;
	Planet* b;
	Planet* c;
	Planet* d;
	Planet* e;
	Planet* f;
	Planet* g;
	Planet* h;
	Planet* i;
	Planet* j;
	Planet* k;
	Planet* l;
	Planet* m;
	*/
	Asteroid asteroid;
	sf::Vector2f center;

	sf::View view;

};
#endif