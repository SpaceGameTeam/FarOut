// FarOut - Scene Class

#ifndef SCENE
#define SCENE
#include <SFML/Graphics.hpp>

class Scene {
public:
	Scene();

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

private:
	int ID;
};

#endif