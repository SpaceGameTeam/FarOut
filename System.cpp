#include "SystemClass.h"


System::System() :
	desktop(sf::VideoMode::getDesktopMode()),
	window(desktop, "FarOut")
{
	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false); //debug
	view = window.getDefaultView(); //again, might move into scenes
}

void System::runWindow() {
	sf::Time dt;
	sf::Time timer;
	
	while (window.isOpen()) {

		//Event check
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		dt = clock.restart();

		window.clear();

		update(dt);

		window.display();
	}
}



void System::update(sf::Time dt) {

	//Keyboard events     ---Most keyboard events will need to be passed into the active scene
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}



	//Update active scene (dt)

	//Draw active scene

}