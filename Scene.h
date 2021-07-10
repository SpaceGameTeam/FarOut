#pragma once

#include <SFML/Graphics.hpp>
#include "SystemClass.h"


class Scene {
public:
	Scene();

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderWindow window) = 0;

private:
	// Some sort of collection of objects? Maybe these should be in the derived class?
};