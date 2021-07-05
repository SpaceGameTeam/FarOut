#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class System {
public:
	System();
	void runWindow();

	// Function to request a scene change (takes name/ID of new scene)

private:
	void update(sf::Time dt);

	//Data module
	//Scenes (probably stored in hash table)

	//Window stuff
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::View view; //not sure if this should be here or in each scene
	sf::Clock clock;
};