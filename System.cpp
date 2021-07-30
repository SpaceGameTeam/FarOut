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
	Planet l(2, 30, sf::Color::White, &i, 0.013);
	Planet m(1, 17, sf::Color::White, &l, 0.05);
	const int numAsteroids = 100;
	Planet* asteroid[numAsteroids];
	for (int i = 0; i < numAsteroids; ++i) {
		srand(time(NULL));
		int randInt = rand();
		int orbitDistance = randInt % 25 + 225;
		int orbitAngle = randInt % 360; 
		int radius = randInt % 7 + 1;
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
		l.update(dt);
		m.update(dt);
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
		window.draw(l);
		window.draw(m);
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

	// Keyboard events     ---Most keyboard events will need to be passed into the active scene
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}


  // Do these loops skip the first element?
	// Update active scenes (dt)
	for (currentScene = sceneStack.end(); currentScene != sceneStack.begin(); --currentScene)
		(*currentScene)->update(dt);


	// Draw active scene
	for (currentScene = sceneStack.end(); currentScene != sceneStack.begin(); --currentScene)
		(*currentScene)->draw(window);

}


