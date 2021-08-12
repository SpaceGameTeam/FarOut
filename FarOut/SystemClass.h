// FarOut - System Class

#ifndef SYSCLS
#define SYSCLS

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <list>
#include <unordered_map>
#include <string>

#include "Scene.h"

class SystemClass {
public:
	SystemClass();
	
	// Starts the window and runs the game loop
	void runWindow();

	// Active Scene Stack Functions
	void pushScene(std::shared_ptr<Scene> toPush);
	void pushScene(int toPush);
	bool popScene();

    // Scene Collection Functions
	bool addScene(int id, std::shared_ptr<Scene> toadd);
	std::shared_ptr<Scene> getScene(int id);
	bool removeScene(int id);

	// Data Storage Module Functions
	bool addData(std::string name, float toadd);
	float getData(std::string name);

	//Other utility functions for developers 
	void setVSync(bool);
	void setFPSCounter(bool);
	void quit();
	
private:
	// Basic actions to be taken each loop, including calling update
	// and draw functions for the active scene, and checking some key events
	void update(sf::Time dt);

	//Scenes - All scenes in the hash table and active scenes in the stack
	std::list<std::shared_ptr<Scene>> sceneStack;
	std::list<std::shared_ptr<Scene>>::reverse_iterator currentScene;
	std::unordered_map<int, std::shared_ptr<Scene>> sceneCollection;

	//Data Storage Module
	std::unordered_map<std::string, float> dataCollection;

	//Window stuff
	sf::VideoMode desktop;
	sf::RenderWindow window;
	sf::View view; 
	sf::Clock clock;
	bool VSyncEnabled;

	//FPS Counter
	void updateFPS();
	bool FPSActive;
	sf::Font FPSFont;
	sf::Text FPSText;
	sf::Time FPSTime;
	sf::Clock FPSClock;
	int FPSFrames;

	//Misc
	bool inFocus;
};

extern SystemClass System;

#endif
