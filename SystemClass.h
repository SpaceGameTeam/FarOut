#include <SFML/Graphics.hpp>
#include <iostream>
#include <forward_list>
#include <unordered_map>

#include "Scene.h"

// #pragma once

#ifndef SYSCLS
#define SYSCLS

// Would like to remove #include of Ship.h, just here to test the ship drawing
#include "Ship.h"
#include "AlienShip.h"
#include "Asteroid.h"

class SystemClass {
public:
	SystemClass();

	// Function to request a scene change (takes name/ID of new scene)

	// Active Scene Stack Functions
	void pushScene(Scene * toPush);
	bool popScene();

  // Scene Collection Functions
	bool addScene(int id, Scene * toadd);
	Scene * getScene(int id);
	bool removeScene(int id);

	// Potential functions to access stored data

private:
	// Starts the window and runs the game loop
	void runWindow();

	// Basic actions to be taken each loop, including calling update
	// and draw functions for the active scene, and checking some key events
	void update(sf::Time dt);

	//Data module
	//Scenes - All scenes in the hash table and active scenes in the stack
	std::forward_list<Scene *> sceneStack;
	std::forward_list<Scene *>::iterator currentScene;
	std::unordered_map<int, Scene *> sceneCollection;

	//Window stuff
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::View view; //not sure if this should be here or in each scene
	sf::Clock clock;
};
#endif