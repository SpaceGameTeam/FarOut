#include "SystemClass.h"

// Singular global instance of the System class
SystemClass System;


//Constructor
SystemClass::SystemClass() :
	desktop(sf::VideoMode::getDesktopMode()),
	window(desktop, "FarOut")
{

	addData("DesktopX", desktop.width);
	addData("DesktopY", desktop.height);

	view = window.getDefaultView();

	//FPS Stuff
	FPSActive = true;
	FPSFont.loadFromFile("AreaKilometer50.otf");
	FPSText.setFont(FPSFont);
	FPSText.setCharacterSize(desktop.height / 30);
	FPSText.setPosition(10, 0);

	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false); //debug
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
	sf::Time timer; //Currently not used

	//PrototypeScene scene;
	/*std::shared_ptr<Scene> ps(new PrototypeScene);
	std::shared_ptr<Scene> ps2(new PrototypeScene);
	System.addScene(1, ps);
	System.addScene(2, ps2);
	System.pushScene(ps);*/



	while (window.isOpen()) { //This is the game loop

		//Event check
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Restart returns the amount of time on the clock (aka stopwatch) and
		//starts it from zero again. This is the amount of time since the last
		//time we came through this loop
		dt = clock.restart();

		window.clear();
		//window.setView(view);
		update(dt);

		// Remove the next 8 lines when done testing ship implementation
		// Draw the ship
		// This is just here for testing
		//asteroid.move(dt);
		//asteroid.update(dt);
		//window.draw(asteroid);
		//view.setCenter(asteroid.getPosition());

		if (FPSActive) {
			updateFPS();
			window.setView(view);
			window.draw(FPSText);
		}

		window.display();
	}
}



// Basic actions to be taken each loop, including calling update
// and draw functions for the active scene, and checking some key events
void SystemClass::update(sf::Time dt) {

	// Keyboard events     ---Most keyboard events will need to be passed into the active scene
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}


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






