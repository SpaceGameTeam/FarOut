#pragma once

#include <SFML/Graphics.hpp>
#include "SystemClass.h"



class GameObject {
public:
	GameObject();

	virtual void update(sf::Time dt) = 0;

};


class VisableObject: public GameObject {
public:
	VisableObject();

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderWindow window) = 0;

protected:
	sf::Texture texture;
	sf::Sprite sprite;
};