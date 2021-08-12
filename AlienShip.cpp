// Alien ship implementation

#include "AlienShip.h"



////////////////////////////////////////////////////////////////////////////
///  Ellipse Shape Class 
////////////////////////////////////////////////////////////////////////////



// Ellipse class modeled after https://www.sfml-dev.org/tutorials/2.0/graphics-shape.php
EllipseShape::EllipseShape(const sf::Vector2f & radius = DOMERADIUS) : m_radius(radius), pointCount(NUMPOINTS) {
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




////////////////////////////////////////////////////////////////////////////
///  AlienShip Shape Class 
////////////////////////////////////////////////////////////////////////////

AlienShip::AlienShip() {
    movementSpeed = 0.0;
	distanceFromShip = 500;

    // Create the ship
	saucer.setPrimitiveType(sf::TriangleStrip);
	saucer.resize(8);
	saucer[0].position = sf::Vector2f(-70.f, -15.f);
	saucer[1].position = sf::Vector2f(-50.f, 0.f);
	saucer[2].position = sf::Vector2f(-50.f, -30.f);
	saucer[3].position = sf::Vector2f(20.f, 0.f);
	saucer[4].position = sf::Vector2f(20.f, -30.f);
	saucer[5].position = sf::Vector2f(50.f, 0.f);
	saucer[6].position = sf::Vector2f(50.f, -30.f);
	saucer[7].position = sf::Vector2f(70.f, -15.f);
	saucer[3].color = sf::Color::White;
	saucer[1].color = sf::Color(60, 60, 60, 255);
	saucer[2].color = sf::Color(60, 60, 60, 255);
	saucer[0].color = sf::Color(60, 60, 60, 255);
	saucer[4].color = sf::Color::White;
	saucer[5].color = sf::Color(60, 60, 60, 255);
	saucer[6].color = sf::Color(60, 60, 60, 255);
	saucer[7].color = sf::Color(60, 60, 60, 255);

    // Make the horizontal line across the middle
	midline.setSize(sf::Vector2f(140, 0));
	midline.setOutlineColor(sf::Color::White);
	midline.setOutlineThickness(1.f);

	// Make the dome
	dome.setPosition(-50, -45);
	dome.setFillColor(sf::Color(255, 255, 255, 150));
	midline.setPosition(-70, -15);

    // Make the hitbox
	// This will change to be simpler for collision detection
	setAlienShipPoints(&hitbox);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

    // Set its position relative to the ship
    setPosition(300, distanceFromShip);
}



// Sets points for Alien ship, just used for the hitbox 
void AlienShip::setAlienShipPoints(sf::ConvexShape * shape) {
	shape->setPointCount(7);
	shape->setPoint(0, sf::Vector2f(-50.f, 0.f));
	shape->setPoint(1, sf::Vector2f(-70.f, -15.f));
	shape->setPoint(2, sf::Vector2f(-50.f, -30.f));
	shape->setPoint(3, sf::Vector2f(0.f, -45.f));
	shape->setPoint(4, sf::Vector2f(50.f, -30.f));
	shape->setPoint(5, sf::Vector2f(70.f, -15.f));
	shape->setPoint(6, sf::Vector2f(50.f, 0.f));
	shape->scale(0.25f, 0.25f);
}



// Overridden draw function
void AlienShip::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
	target.draw(dome, states);
    target.draw(saucer, states); 
    target.draw(midline, states); 
}



// Chase the ship! 
void AlienShip::update(sf::Time dt, sf::Vector2f shipPosition){
	sf::Vector2f diff = shipPosition + sf::Vector2f(300, 500) - getPosition();
	if (abs(diff.x) > 10 || abs(diff.y) > 10) {
		movement = diff;
	}
    sf::Transformable::move(movement * dt.asSeconds());
}



// To overload the base class update function
void AlienShip::update(sf::Time dt) {}