#include "SystemClass.h"

// Singular global instance of the System class
SystemClass System;


//Constructor
SystemClass::SystemClass() :
	desktop(sf::VideoMode::getDesktopMode()),
	window(desktop, "FarOut")
{
	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false); //debug
	view = window.getDefaultView(); //again, might move into scenes
	runWindow();
}



// Push to the sceneStack to be call during update and draw
void SystemClass::pushScene(Scene * toPush)
{
	sceneStack.push_front(toPush);

}



// Pop scenes from the sceneStack
// Return true for success, false for empty stack
bool SystemClass::popScene()
{
	sceneStack.pop_front();

  // TODO Check for empty list
	return true;
}



// Add a scene to the collection
bool SystemClass::addScene(int id, Scene * toadd)
{

	return false;
}



// Return a scene from the scene collection
Scene * SystemClass::getScene(int id)
{

	return NULL;
}



// Remove a scene from the scene collection 
bool SystemClass::removeScene(int id)
{

	return false;
}



// This function starts the window and runs the game loop
void SystemClass::runWindow() {
	sf::Time dt; //SFML time object for tracking time between updates
	sf::Time timer; //Currently not used

	PrototypeScene scene;
	Star sun(30, sf::Color(219, 57, 5), 3, sf::Color(255, 154, 1), sf::Vector2f(300, -100));
	Planet a(5, 100, sf::Color::Green, &sun, 0.01);
	Planet b(8, 140, sf::Color::Blue, &sun, 0.001);
	Planet c(10, 180, sf::Color::Magenta, &sun, 0.005);
	Planet d(4, 200, sf::Color::Yellow, &sun, 0.001);
	Planet e(50, 350, sf::Color::Cyan, &sun, 0.0009);
	Planet f(25, 460, sf::Color::Green, &sun, 0.0008);
	Planet g(10, 500, sf::Color::Blue, &sun, 0.0009);
	Planet h (10, 540, sf::Color::Yellow, &sun, 0.002);
	Planet i(3, 600, sf::Color::Yellow, &sun, 0.003);
	Planet j(2, 15, sf::Color::White, &g, 0.01);
	Planet k(2, 10, sf::Color::White, &d, 0.03);
	int numAsteroids = 100;
	Planet* asteroid[numAsteroids];
	for (int i = 0; i < numAsteroids; ++i) {
		srand(time(NULL));
		int randInt = rand();
		int orbitDistance = randInt % 25 + 225;
		int orbitAngle = randInt % 360; 
		int radius = randInt % 7 + 1;
		std::cout << orbitAngle;
		asteroid[i] = new Planet(radius, orbitDistance, sf::Color(202, 199, 190), &sun, 0.005);	
		asteroid[i]->setPosition(sf::Vector2f (sun.getPosition().x + orbitDistance * cos(orbitAngle), sun.getPosition().y + orbitDistance * sin(orbitAngle)));
	}
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

		update(dt);
		scene.update(dt);
		sun.update(dt);
		a.update(dt);
		b.update(dt);
		c.update(dt);
		d.update(dt);
		e.update(dt);
		f.update(dt);
		g.update(dt);
		h.update(dt);
		i.update(dt);
		j.update(dt);
		k.update(dt);
		for (int i = 0; i < numAsteroids; ++i) {
			asteroid[i]->update(dt);
		}
		scene.draw(window);
		window.draw(sun);
		window.draw(a);
		window.draw(b);
		window.draw(c);
		window.draw(d);
		window.draw(e);
		window.draw(f);
		window.draw(g);
		window.draw(h);
		window.draw(i);
		window.draw(j);
		window.draw(k);
		for (int i = 0; i < numAsteroids; ++i) {
			window.draw(*asteroid[i]);
		}
		

		scene.move(dt);
		view.setCenter(scene.getCenter());
		window.setView(view);

		window.display();
	}
}



// Basic actions to be taken each loop, including calling update
// and draw functions for the active scene, and checking some key events
void SystemClass::update(sf::Time dt) {

	//Keyboard events     ---Most keyboard events will need to be passed into the active scene
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}

	//Update active scenes (dt)
	for (currentScene = sceneStack.begin(); currentScene != sceneStack.end(); ++currentScene)
		(*currentScene)->update(dt);


	//Draw active scene
	for (currentScene = sceneStack.begin(); currentScene != sceneStack.end(); ++currentScene)
		(*currentScene)->draw(window);

}


