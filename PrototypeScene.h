// The demo scene

// Our example scene is made by deriving a class from our library’s Scene class. 
// In order to do so, we overload Scene’s update and draw functions as well as 
// adding any GameObject-derived classes that we want to include in the scene. 
// For our example we have a background, ship, alien ship, asteroid, sun, and 
// many planets, all stored as data members of Prototype Scene. Each of these 
// is an instantiation of a class, derived from FarOut’s GameObject class which 
// is itself derived from SFML’s Drawable and Transformable classes. 

#ifndef PROTO
#define PROTO

#include "AlienShip.h"
#include "Ship.h"
#include "PlanetarySystem.h"
#include "Asteroid.h"

const int SYSTEMOBJECTS = 13;


// Stars that go on almost forever
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
	Asteroid asteroid;
	sf::Vector2f center;
	sf::View view;
};
#endif