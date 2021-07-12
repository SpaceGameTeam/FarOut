#include "Ship.h"

Ship::Ship(){
    // Check movementSpeed setting when star background is working
    movementSpeed = 363.0;

    // Create the ship
    // Can be exchanged with other functions to create other ships
	setBlueShipPoints();
	setBlueShipHitbox();

    setPosition(0, 0);
}


// Sets points for a basic spacecraft outline
void Ship::setMercuryPoints(){
    body.setPointCount(36);
	body.setPoint(0, sf::Vector2f(0.f, 45.f));
	body.setPoint(1, sf::Vector2f(-7.f, 45.f));
	body.setPoint(2, sf::Vector2f(-7.f, 30.f));
	body.setPoint(3, sf::Vector2f(-9.f, 30.f));
	body.setPoint(4, sf::Vector2f(-11.f, 15.f));
	body.setPoint(5, sf::Vector2f(-30.f, -50.f));
	body.setPoint(6, sf::Vector2f(-30.f, -51.f));
	body.setPoint(7, sf::Vector2f(-30.f, -52.f));
	body.setPoint(8, sf::Vector2f(-22.f, -54.f));
	body.setPoint(9, sf::Vector2f(-17.f, -56.f));
	body.setPoint(10, sf::Vector2f(-13.f, -58.f));
	body.setPoint(11, sf::Vector2f(-10.f, -60.f));
	body.setPoint(12, sf::Vector2f(-10.f, -60.f));
	body.setPoint(13, sf::Vector2f(-10.f, -70.f));
	body.setPoint(14, sf::Vector2f(-7.f, -73.f));
	body.setPoint(15, sf::Vector2f(-9.f, -75.f));
	body.setPoint(16, sf::Vector2f(-6.f, -74.f));
	body.setPoint(17, sf::Vector2f(-4.f, -72.f));
	body.setPoint(18, sf::Vector2f(-2.f, -75.f));
	body.setPoint(19, sf::Vector2f(2.f, -75.f));
	body.setPoint(20, sf::Vector2f(4.f, -72.f));
	body.setPoint(21, sf::Vector2f(6.f, -74.f));
	body.setPoint(22, sf::Vector2f(9.f, -75.f));
	body.setPoint(23, sf::Vector2f(7.f, -73.f));
	body.setPoint(24, sf::Vector2f(10.f, -70.f));
	body.setPoint(25, sf::Vector2f(10.f, -60.f));
	body.setPoint(26, sf::Vector2f(13.f, -58.f));
	body.setPoint(27, sf::Vector2f(17.f, -56.f));
	body.setPoint(28, sf::Vector2f(22.f, -54.f));
	body.setPoint(29, sf::Vector2f(30.f, -52.f));
	body.setPoint(30, sf::Vector2f(30.f, -51.f));
	body.setPoint(31, sf::Vector2f(30.f, -50.f));
	body.setPoint(32, sf::Vector2f(11.f, 15.f));
	body.setPoint(33, sf::Vector2f(9.f, 30.f));
	body.setPoint(34, sf::Vector2f(7.f, 30.f));
	body.setPoint(35, sf::Vector2f(7.f, 45.f));

	body.setOutlineThickness(3.f);
	body.setFillColor(sf::Color::Black);
	body.scale(0.5f, 0.5f);
}



// Sets points for blue ship 
// Ship body #2
void Ship::setBlueShipPoints() {
	body.setPointCount(14);
	body.setPoint(0, sf::Vector2f(0.f, 0.f));
	body.setPoint(1, sf::Vector2f(-7.f, 0.f));
	body.setPoint(2, sf::Vector2f(-13.f, -8.f));
	body.setPoint(3, sf::Vector2f(-19.f, 4.f));
	body.setPoint(4, sf::Vector2f(-19.f, 12.f));
	body.setPoint(5, sf::Vector2f(-13.f, 17.f));
	body.setPoint(6, sf::Vector2f(-13.f, 38.f));
	body.setPoint(7, sf::Vector2f(0.f, 62.f));
	body.setPoint(8, sf::Vector2f(13.f, 38.f));
	body.setPoint(9, sf::Vector2f(13.f, 17.f));
	body.setPoint(10, sf::Vector2f(19.f, 12.f));
	body.setPoint(11, sf::Vector2f(19.f, 4.f));
	body.setPoint(12, sf::Vector2f(13.f, -8.f));
	body.setPoint(13, sf::Vector2f(7.f, 0.f));
	


	body.setOutlineThickness(3.f);
	body.setFillColor(sf::Color::Blue);
	body.scale(0.75f, 0.75f);
}



// Sets points for blue ship hitbox
// Ship body #2
void Ship::setBlueShipHitbox() {
	hitbox.setPointCount(14);
	hitbox.setPoint(0, sf::Vector2f(0.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(-7.f, 0.f));
	hitbox.setPoint(2, sf::Vector2f(-13.f, -8.f));
	hitbox.setPoint(3, sf::Vector2f(-19.f, 4.f));
	hitbox.setPoint(4, sf::Vector2f(-19.f, 12.f));
	hitbox.setPoint(5, sf::Vector2f(-13.f, 17.f));
	hitbox.setPoint(6, sf::Vector2f(-13.f, 38.f));
	hitbox.setPoint(7, sf::Vector2f(0.f, 62.f));
	hitbox.setPoint(8, sf::Vector2f(13.f, 38.f));
	hitbox.setPoint(9, sf::Vector2f(13.f, 17.f));
	hitbox.setPoint(10, sf::Vector2f(19.f, 12.f));
	hitbox.setPoint(11, sf::Vector2f(19.f, 4.f));
	hitbox.setPoint(12, sf::Vector2f(13.f, -8.f));
	hitbox.setPoint(13, sf::Vector2f(7.f, 0.f));
	


	hitbox.setOutlineThickness(1.f);
	hitbox.setFillColor(sf::Color::Transparent);
	// hitbox.setOutlineColor(sf::Color::Red);
	hitbox.scale(0.75f, 0.75f);
}



// Overridden draw function
void Ship::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(body, states); 
    target.draw(hitbox, states); 
}



// Move or rotate the ship when keys are pressed
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



// Move the ship
// Overrides Transformable move function to allow storage of movement as Ship class data member
void Ship::move(sf::Time dt){
    sf::Transformable::move(movement * dt.asSeconds());
}
