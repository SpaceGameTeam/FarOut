// Scene base class for client derivation



#ifndef SCENE
#define SCENE
#include <SFML/Graphics.hpp>

//#include "SystemClass.h"


class Scene {
public:
	Scene(int id);

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

private:
	int id;
	// Some sort of collection of objects? Maybe these should be in the derived class?
};
#endif