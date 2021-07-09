#include "Ship.h"

Ship::Ship(){
    // We don't know what to set movementSpeed to. 
    // Will wait until we can test on a background of stars to see how it works.
    movementSpeed = 10.0;
    // Body[0].position = sf::Vector2f(0.f, 50.f);
    Body.setPointCount(11);
	Body.setPoint(0, sf::Vector2f(0.f, 50.f));
	Body.setPoint(1, sf::Vector2f(-5.f, 45.f));
	Body.setPoint(2, sf::Vector2f(-9.f, 30.f));
	Body.setPoint(3, sf::Vector2f(-11.f, 15.f));
	Body.setPoint(4, sf::Vector2f(-30.f, -50.f));
	Body.setPoint(5, sf::Vector2f(-10.f, -60.f));
	Body.setPoint(6, sf::Vector2f(10.f, -60.f));
	Body.setPoint(7, sf::Vector2f(30.f, -50.f));
	Body.setPoint(8, sf::Vector2f(11.f, 15.f));
	Body.setPoint(9, sf::Vector2f(9.f, 30.f));
	Body.setPoint(10, sf::Vector2f(5.f, 45.f));
	Body.setOutlineThickness(5.f);
	Body.setFillColor(sf::Color::Black);
	Body.scale(0.5f, 0.5f);

    setPosition(0, 0);
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(Body, states); 
}


void Ship::update(sf::Time dt){
    sf::Vector2f shipMovement = sf::Vector2f(20.f, 20.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		rotate(-230.f * dt.asSeconds());
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		rotate(230.f * dt.asSeconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		shipMovement = sf::Vector2f(0.f, 0.f);
		setPosition(0, 0);
		// coords.setPosition(-(desktop.width / 2.f), -(desktop.height / 2.f) + 50);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		shipMovement += movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180))); 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		shipMovement -= movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180)));
	}


}