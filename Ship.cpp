#include "Ship.h"

Ship::Ship(){
    // We don't know what to set movementSpeed to. 
    // Will wait until we can test on a background of stars to see how it works.
    movementSpeed = 363.0;
    Body.setPointCount(36);
	Body.setPoint(0, sf::Vector2f(0.f, 45.f));
	Body.setPoint(1, sf::Vector2f(-7.f, 45.f));
	Body.setPoint(2, sf::Vector2f(-7.f, 30.f));
	Body.setPoint(3, sf::Vector2f(-9.f, 30.f));
	Body.setPoint(4, sf::Vector2f(-11.f, 15.f));
	Body.setPoint(5, sf::Vector2f(-30.f, -50.f));
	Body.setPoint(6, sf::Vector2f(-30.f, -51.f));
	Body.setPoint(7, sf::Vector2f(-30.f, -52.f));
	Body.setPoint(8, sf::Vector2f(-22.f, -54.f));
	Body.setPoint(9, sf::Vector2f(-17.f, -56.f));
	Body.setPoint(10, sf::Vector2f(-13.f, -58.f));
	Body.setPoint(11, sf::Vector2f(-10.f, -60.f));
	Body.setPoint(12, sf::Vector2f(-10.f, -60.f));
	Body.setPoint(13, sf::Vector2f(-10.f, -70.f));
	Body.setPoint(14, sf::Vector2f(-7.f, -73.f));
	Body.setPoint(15, sf::Vector2f(-9.f, -75.f));
	Body.setPoint(16, sf::Vector2f(-6.f, -74.f));
	Body.setPoint(17, sf::Vector2f(-4.f, -72.f));
	Body.setPoint(18, sf::Vector2f(-2.f, -75.f));
	Body.setPoint(19, sf::Vector2f(2.f, -75.f));
	Body.setPoint(20, sf::Vector2f(4.f, -72.f));
	Body.setPoint(21, sf::Vector2f(6.f, -74.f));
	Body.setPoint(22, sf::Vector2f(9.f, -75.f));
	Body.setPoint(23, sf::Vector2f(7.f, -73.f));
	Body.setPoint(24, sf::Vector2f(10.f, -70.f));
	Body.setPoint(25, sf::Vector2f(10.f, -60.f));
	Body.setPoint(26, sf::Vector2f(13.f, -58.f));
	Body.setPoint(27, sf::Vector2f(17.f, -56.f));
	Body.setPoint(28, sf::Vector2f(22.f, -54.f));
	Body.setPoint(29, sf::Vector2f(30.f, -52.f));
	Body.setPoint(30, sf::Vector2f(30.f, -51.f));
	Body.setPoint(31, sf::Vector2f(30.f, -50.f));
	Body.setPoint(32, sf::Vector2f(11.f, 15.f));
	Body.setPoint(33, sf::Vector2f(9.f, 30.f));
	Body.setPoint(34, sf::Vector2f(7.f, 30.f));
	Body.setPoint(35, sf::Vector2f(7.f, 45.f));

	Body.setOutlineThickness(3.f);
	Body.setFillColor(sf::Color::Black);
	Body.scale(0.5f, 0.5f);

    setPosition(0, 0);
}



void Ship::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(Body, states); 
}



void Ship::update(sf::Time dt){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		rotate(-230.f * dt.asSeconds());
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		rotate(230.f * dt.asSeconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		movement = sf::Vector2f(0.f, 0.f);
		setPosition(0, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		movement += movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180))); 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		movement -= movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180)));
	}


}



void Ship::move(sf::Time dt){
    sf::Transformable::move(movement * dt.asSeconds());
}
