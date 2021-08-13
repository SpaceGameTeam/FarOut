// FarOut - System Class

#include "SystemClass.h"

// Singular global instance of the System class
SystemClass System;


//Constructor
SystemClass::SystemClass() :
	desktop(sf::VideoMode::getDesktopMode())
{
	inFocus = true;

	windowTitle = "FarOut";

	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

	for (int i = 0; i < modes.size(); ++i) {
		if (modes[i].height == desktop.height && modes[i].width == desktop.width) {
			desktop = modes[i];
			break;
		}
	}
	if (desktop.isValid()) 
		window.create(desktop, windowTitle, sf::Style::Fullscreen);
	else window.create(desktop, windowTitle);

	addData("DesktopX", desktop.width);
	addData("DesktopY", desktop.height);

	view = window.getDefaultView();

	//FPS Stuff
	FPSActive = true;
	FPSFont.loadFromFile("Assets/AreaKilometer50.otf");
	FPSText.setFont(FPSFont);
	FPSText.setCharacterSize(desktop.height / 30);
	FPSText.setPosition(10, 0);

	//VSync
	VSyncEnabled = false;
	window.setVerticalSyncEnabled(VSyncEnabled);
}



// Push to the sceneStack to be call during update and draw
void SystemClass::pushScene(std::shared_ptr<Scene> toPush)
{
	sceneStack.push_front(toPush);

	return;
}



// Pop scenes from the sceneStack
// Return true for success, false for empty stack
bool SystemClass::popScene()
{
	if (sceneStack.empty())
		return false;

	sceneStack.pop_front();

	return true;
}



// Add a scene to the collection
// Returns true for success, false if there is already a scene at that key value
bool SystemClass::addScene(int id, std::shared_ptr<Scene> toadd)
{
	if(!sceneCollection[id]) {
		sceneCollection[id] = toadd;
		return true; 
	}

	return false;
}



// Return a scene from the scene collection
// Returns NULL if no scene at that id
std::shared_ptr<Scene> SystemClass::getScene(int id)
{
	std::shared_ptr<Scene> temp = sceneCollection[id];

	if (temp)
		return temp;

	return NULL;
}



/*  Not sure if this is usefull now...

// Remove a scene from the scene collection 
bool SystemClass::removeScene(int id)
{

	return false;
}
*/



// Add data to the collection
// Returns true for success, false if there is already data at that key value
bool SystemClass::addData(std::string name, float toadd)
{
	if(!dataCollection[name]) {
		dataCollection[name] = toadd;
		return true; 
	}

	return false;
}



// Return data from the scene collection
// Check for NULL?
float SystemClass::getData(std::string name)
{
	return dataCollection[name];
}


// This function starts the window and runs the game loop
void SystemClass::runWindow() {
	sf::Time dt; //SFML time object for tracking time between updates

	while (window.isOpen()) { //This is the game loop

		//Event check
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
			
			//Pauses when out of focus
			if (event.type == sf::Event::LostFocus)
				inFocus = false;
			if (event.type == sf::Event::GainedFocus)
				inFocus = true;

			//Most events should only be checked when in focus
			if (inFocus) {
				if (event.type == sf::Event::KeyPressed) {

					//ESC
					if (event.key.code == sf::Keyboard::Escape)
						window.close();

					//VSync toggle
					if (event.key.code == sf::Keyboard::V) {
						if (VSyncEnabled) VSyncEnabled = false;
						else VSyncEnabled = true;
						window.setVerticalSyncEnabled(VSyncEnabled);
					}
				}
			}
		}

		//Restart returns the amount of time on the clock (aka stopwatch) and
		//starts it from zero again. This is the amount of time since the last
		//time we came through this loop
		dt = clock.restart();

		if (inFocus) {
			window.clear();

			update(dt);

			if (FPSActive) {
				updateFPS();
				window.setView(view);
				window.draw(FPSText);
			}

			window.display();
		}
	}
}



// Basic actions to be taken each loop, including calling update
// and draw functions for the active scene, and checking some key events
void SystemClass::update(sf::Time dt) {
	
	// Update active scenes (dt)
	for (currentScene = sceneStack.rbegin(); currentScene != sceneStack.rend(); ++currentScene)
		(*currentScene)->update(dt);

	// Draw active scene
	for (currentScene = sceneStack.rbegin(); currentScene != sceneStack.rend(); ++currentScene)
		(*currentScene)->draw(window);
}




//Update FPS text
void SystemClass::updateFPS() {
	++FPSFrames;
	FPSTime = FPSClock.getElapsedTime();
	if (FPSTime.asSeconds() > 1) {
		FPSClock.restart();
		FPSText.setString(std::to_string(FPSFrames));
		FPSFrames = 0;
	}
}


//Toggle FPS counter utility function
void SystemClass::setFPSCounter(bool set) {
	FPSActive = set;
}


//VSync utility function
void SystemClass::setVSync(bool set) {
	window.setVerticalSyncEnabled(set);
}


//Quit function
void SystemClass::quit() {
	//save data system to file

	window.close();
}


