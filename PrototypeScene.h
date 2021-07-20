// #pragma once

#ifndef PROTO
#define PROTO
#include "Scene.h"
#include "GameObject.h"

const int PLANETS = 9;


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

	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);

private:
	Background bg;
	Ship ship;
	AlienShip* alien;
	Star* sun;
	Planet* planet[PLANETS];
	Asteroid asteroid;

};
#endif