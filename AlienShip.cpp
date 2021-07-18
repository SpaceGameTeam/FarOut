#include "AlienShip.h"




////////////////////////////////////////////////////////////////////////////
///  Ellipse Shape Class 
////////////////////////////////////////////////////////////////////////////



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



// Takes a GameObject pointer as an argument, but this could also be a
// data structure of GameObjects to facilitate communication
AlienShip::AlienShip(GameObject * commObject){
	ship = commObject;
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

	midline.setSize(sf::Vector2f(140, 0));
	midline.setOutlineColor(sf::Color::White);
	midline.setOutlineThickness(1.f);
	dome.setPosition(-50, -45);
	dome.setFillColor(sf::Color(255, 255, 255, 150));
	midline.setPosition(-70, -15);

	setAlienShipPoints(&hitbox);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

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
}



// Overridden draw function
void AlienShip::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
	target.draw(dome, states);
    target.draw(saucer, states); 
    target.draw(midline, states); 
    // target.draw(hitbox, states); 
}



// Chase the ship! A momentum term would help here
void AlienShip::update(sf::Time dt){
	sf::Vector2f diff = ship->getPosition() + sf::Vector2f(300, 500) - getPosition();
	if (abs(diff.x) > 10 || abs(diff.y) > 10) {
		float magnitude = sqrt (diff.x * diff.x + diff.y * diff.y);
		movementSpeed += 0.01 * (magnitude - (distanceFromShip - 300));
		movement += movementSpeed * dt.asSeconds() * diff / magnitude;
	}
}



// Move the ship
// Overrides Transformable move function to allow storage of movement as AlienShip class data member
void AlienShip::move(sf::Time dt){
    sf::Transformable::move(movement * dt.asSeconds());
}
