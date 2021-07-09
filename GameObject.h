#pragma once

#include <SFML/Graphics.hpp>
#include "SystemClass.h"


#ifndef GAMEOBJ
#define GAMEOBJ
class GameObject : public sf::Drawable, public sf::Transformable {
public:
	GameObject();

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

// Including this here because having trouble with circular #includes
// We want this to be defined in its own file
class Ship : public GameObject {
public:
	Ship();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dt);

private:
    sf::ConvexShape Body;
    float movementSpeed;

};
#endif