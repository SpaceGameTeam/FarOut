#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class System {
public:
	System();

	// Starts the window and runs the game loop
	void runWindow();

	// Function to request a scene change (takes name/ID of new scene)

private:
	// Basic actions to be taken each loop, including calling update
	// and draw functions for the active scene, and checking some key events
	void update(sf::Time dt);

	//Data module
	//Scenes (probably stored in hash table)

	//Window stuff
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::View view; //not sure if this should be here or in each scene
	sf::Clock clock;
};