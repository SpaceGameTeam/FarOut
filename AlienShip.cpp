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

	std::cout << "Point " << index << " : (" << x << ", " << y << ")\n"; 
	return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}




////////////////////////////////////////////////////////////////////////////
///  Ellipse Shape Class 
////////////////////////////////////////////////////////////////////////////



AlienShip::AlienShip(){
    // Check movementSpeed setting when star background is working
    movementSpeed = 363.0;

    // Create the ship
    // Can be exchanged with other functions to create other ships
	// setAlienShipPoints(&body);
	body.setOutlineThickness(2.f);
	body.setFillColor(sf::Color::Blue);
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
	// saucer.position = sf::Vector2f(50.f, 50.f);
	// body.setPosition(50, 50);
	midline.setPosition(-70, -15);
	// body.scale(0.75f, 0.75f);

    /*
	setAlienShipPoints(&hitbox);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.scale(0.75f, 0.75f);
	*/

    // setPosition(0, 0);
}



// Sets points for Alien ship 
void AlienShip::setAlienShipPoints(sf::ConvexShape * shape) {
	shape->setPointCount(7);
	shape->setPoint(0, sf::Vector2f(-50.f, 0.f));
	shape->setPoint(1, sf::Vector2f(-70.f, -15.f));
	shape->setPoint(2, sf::Vector2f(-50.f, -30.f));
	shape->setPoint(3, sf::Vector2f(50.f, -30.f));
	shape->setPoint(4, sf::Vector2f(70.f, -15.f));
	shape->setPoint(5, sf::Vector2f(50.f, 0.f));
}



// Overridden draw function
void AlienShip::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
	target.draw(dome, states);
    // target.draw(body, states); 
    target.draw(saucer, states); 
    target.draw(midline, states); 
    // target.draw(hitbox, states); 
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
