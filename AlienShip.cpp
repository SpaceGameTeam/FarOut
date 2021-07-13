#include "AlienShip.h"



EllipseShape::EllipseShape(const sf::Vector2f & radius = sf::Vector2f(0, 0)) : m_radius(radius), pointCount(NUMPOINTS) {
	update();
}



void EllipseShape::setRadius(const sf::Vector2f& radius) {
	m_radius = radius;
	update();
}



const sf::Vector2f& EllipseShape::getRadius() const {
	return m_radius;
}



std::size_t EllipseShape::getPointCount() const {
	return pointCount; 
}



sf::Vector2f EllipseShape::getPoint(std::size_t index) const {
	static const float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount() - pi / 2;
	float x = std::cos(angle) * m_radius.x;
	float y = std::sin(angle) * m_radius.y;

	return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}




AlienShip::AlienShip(){
    // Check movementSpeed setting when star background is working
    movementSpeed = 363.0;

	// Make the dome
    sf::Vector2f domeRadius(20.f, 50.f);	
	dome.setRadius(domeRadius);

    // Create the ship
    // Can be exchanged with other functions to create other ships
	setAlienShipPoints(&body);
	body.setOutlineThickness(3.f);
	body.setFillColor(sf::Color::Blue);
	body.scale(0.75f, 0.75f);

	setAlienShipPoints(&hitbox);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.scale(0.75f, 0.75f);

    setPosition(0, 0);
}



// Sets points for Alien ship 
void AlienShip::setAlienShipPoints(sf::ConvexShape * shape) {
	shape->setPointCount(14);
	shape->setPoint(0, sf::Vector2f(0.f, 0.f));
	shape->setPoint(1, sf::Vector2f(-7.f, 0.f));
	shape->setPoint(2, sf::Vector2f(-13.f, -8.f));
	shape->setPoint(3, sf::Vector2f(-19.f, 4.f));
	shape->setPoint(4, sf::Vector2f(-19.f, 12.f));
	shape->setPoint(5, sf::Vector2f(-13.f, 17.f));
	shape->setPoint(6, sf::Vector2f(-13.f, 38.f));
	shape->setPoint(7, sf::Vector2f(0.f, 62.f));
	shape->setPoint(8, sf::Vector2f(13.f, 38.f));
	shape->setPoint(9, sf::Vector2f(13.f, 17.f));
	shape->setPoint(10, sf::Vector2f(19.f, 12.f));
	shape->setPoint(11, sf::Vector2f(19.f, 4.f));
	shape->setPoint(12, sf::Vector2f(13.f, -8.f));
	shape->setPoint(13, sf::Vector2f(7.f, 0.f));
}



// Overridden draw function
void AlienShip::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(body, states); 
    // target.draw(hitbox, states); 
	// target.draw(dome, states);
}



// Move or rotate the ship when keys are pressed
void AlienShip::update(sf::Time dt){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		rotate(-230.f * dt.asSeconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		rotate(230.f * dt.asSeconds());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		movement = sf::Vector2f(0.f, 0.f);
		setPosition(0, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		movement += movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180))); 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		movement -= movementSpeed * dt.asSeconds() * sf::Vector2f(-sin(getRotation() * (3.1415 / 180)), 
			cos(getRotation() * (3.1415 / 180)));
	}


}



// Move the ship
// Overrides Transformable move function to allow storage of movement as AlienShip class data member
void AlienShip::move(sf::Time dt){
    sf::Transformable::move(movement * dt.asSeconds());
}
