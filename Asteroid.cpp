#include "Asteroid.h"

Asteroid::Asteroid() {
	// Check movementSpeed setting when star background is working
	movementSpeed = 363.0;

	// Create the asteroid
	// Can be exchanged with other functions to create other ships
	setMercuryPoints();
	setHitboxPoints();
	setPosition(200, 200);

	//circle anchor is at pi rads on circumference (instead of center)
	// origin is thus offset by radius and height of gameobject to center around the object
	hitradius.setPosition(getPosition().x - radius, getPosition().y-100);
	hitradius.setRadius(radius);
	hitradius.setFillColor(sf::Color::Transparent);
	hitradius.setOutlineColor(sf::Color::Green);
	hitradius.setOutlineThickness(3.f);
	
}




// Sets points for the asteroid
void Asteroid::setMercuryPoints() {
	Body.setPointCount(103);
	Body.setPoint(0, sf::Vector2f(0.f, 60.f));
	Body.setPoint(1, sf::Vector2f(0.f, 60.f));
	Body.setPoint(2, sf::Vector2f(6.f, 60.f));
	Body.setPoint(3, sf::Vector2f(6.f, 58.f));
	Body.setPoint(4, sf::Vector2f(17.f, 58.f));
	Body.setPoint(5, sf::Vector2f(17.f, 56.f));
	Body.setPoint(6, sf::Vector2f(32.f, 56.f));
	Body.setPoint(7, sf::Vector2f(32.f, 54.f));
	Body.setPoint(8, sf::Vector2f(34.f, 54.f));
	Body.setPoint(9, sf::Vector2f(34.f, 52.f));
	Body.setPoint(10, sf::Vector2f(36.f, 52.f));
	Body.setPoint(11, sf::Vector2f(36.f, 50.f));
	Body.setPoint(12, sf::Vector2f(38.f, 50.f));
	Body.setPoint(13, sf::Vector2f(38.f, 48.f));
	Body.setPoint(14, sf::Vector2f(39.f, 48.f));
	Body.setPoint(15, sf::Vector2f(39.f, 46.f));
	Body.setPoint(16, sf::Vector2f(41.f, 46.f));
	Body.setPoint(17, sf::Vector2f(41.f, 44.f));
	Body.setPoint(18, sf::Vector2f(43.f, 44.f));
	Body.setPoint(19, sf::Vector2f(43.f, 41.f));
	Body.setPoint(20, sf::Vector2f(45.f, 41.f));
	Body.setPoint(21, sf::Vector2f(45.f, 37.f));
	Body.setPoint(22, sf::Vector2f(47.f, 37.f));
	Body.setPoint(23, sf::Vector2f(47.f, 14.f));
	Body.setPoint(24, sf::Vector2f(48.f, 14.f));
	Body.setPoint(25, sf::Vector2f(48.f, 5.f));
	Body.setPoint(26, sf::Vector2f(50.f, 5.f));
	Body.setPoint(27, sf::Vector2f(50.f, 1.f));
	Body.setPoint(28, sf::Vector2f(52.f, 1.f));
	Body.setPoint(29, sf::Vector2f(52.f, -3.f));
	Body.setPoint(30, sf::Vector2f(54.f, -3.f));
	Body.setPoint(31, sf::Vector2f(54.f, -10.f));
	Body.setPoint(32, sf::Vector2f(56.f, -10.f));
	Body.setPoint(33, sf::Vector2f(56.f, -18.f));
	Body.setPoint(34, sf::Vector2f(58.f, -18.f));
	Body.setPoint(35, sf::Vector2f(58.f, -22.f));
	Body.setPoint(36, sf::Vector2f(60.f, -22.f));
	Body.setPoint(37, sf::Vector2f(60.f, -33.f));
	Body.setPoint(38, sf::Vector2f(58.f, -33.f));
	Body.setPoint(39, sf::Vector2f(58.f, -35.f));
	Body.setPoint(40, sf::Vector2f(56.f, -35.f));
	Body.setPoint(41, sf::Vector2f(56.f, -37.f));
	Body.setPoint(42, sf::Vector2f(54.f, -37.f));
	Body.setPoint(43, sf::Vector2f(54.f, -39.f));
	Body.setPoint(44, sf::Vector2f(52.f, -39.f));
	Body.setPoint(45, sf::Vector2f(52.f, -46.f));
	Body.setPoint(46, sf::Vector2f(50.f, -46.f));
	Body.setPoint(47, sf::Vector2f(50.f, -48.f));
	Body.setPoint(48, sf::Vector2f(47.f, -48.f));
	Body.setPoint(49, sf::Vector2f(47.f, -50.f));
	Body.setPoint(50, sf::Vector2f(43.f, -50.f));
	Body.setPoint(51, sf::Vector2f(43.f, -48.f));
	Body.setPoint(52, sf::Vector2f(38.f, -48.f));
	Body.setPoint(53, sf::Vector2f(38.f, -50.f));
	Body.setPoint(54, sf::Vector2f(18.f, -50.f));
	Body.setPoint(55, sf::Vector2f(18.f, -52.f));
	Body.setPoint(56, sf::Vector2f(16.f, -52.f));
	Body.setPoint(57, sf::Vector2f(16.f, -56.f));
	Body.setPoint(58, sf::Vector2f(10.f, -56.f));
	Body.setPoint(59, sf::Vector2f(10.f, -60.f));
	Body.setPoint(60, sf::Vector2f(-2.f, -60.f));
	Body.setPoint(61, sf::Vector2f(-2.f, -58.f));
	Body.setPoint(62, sf::Vector2f(-10.f, -58.f));
	Body.setPoint(63, sf::Vector2f(-10.f, -54.f));
	Body.setPoint(64, sf::Vector2f(-14.f, -54.f));
	Body.setPoint(65, sf::Vector2f(-14.f, -50.f));
	Body.setPoint(66, sf::Vector2f(-17.f, -50.f));
	Body.setPoint(67, sf::Vector2f(-17.f, -40.f));
	Body.setPoint(68, sf::Vector2f(-20.f, -40.f));
	Body.setPoint(69, sf::Vector2f(-29.f, -32.f));
	Body.setPoint(70, sf::Vector2f(-23.f, -32.f));
	Body.setPoint(71, sf::Vector2f(-23.f, -26.f));
	Body.setPoint(72, sf::Vector2f(-43.f, -26.f));
	Body.setPoint(73, sf::Vector2f(-43.f, -22.f));
	Body.setPoint(74, sf::Vector2f(-50.f, -22.f));
	Body.setPoint(75, sf::Vector2f(-50.f, -18.f));
	Body.setPoint(76, sf::Vector2f(-55.f, -18.f));
	Body.setPoint(77, sf::Vector2f(-55.f, -16.f));
	Body.setPoint(78, sf::Vector2f(-57.f, -16.f));
	Body.setPoint(79, sf::Vector2f(-57.f, -6.f));
	Body.setPoint(80, sf::Vector2f(-56.f, -6.f));
	Body.setPoint(81, sf::Vector2f(-56.f, 12.f));
	Body.setPoint(82, sf::Vector2f(-57.f, 12.f));
	Body.setPoint(83, sf::Vector2f(-57.f, 16.f));
	Body.setPoint(84, sf::Vector2f(-59.f, 16.f));
	Body.setPoint(85, sf::Vector2f(-59.f, 24.f));
	Body.setPoint(86, sf::Vector2f(-57.f, 24.f));
	Body.setPoint(87, sf::Vector2f(-57.f, 39.f));
	Body.setPoint(88, sf::Vector2f(-54.f, 39.f));
	Body.setPoint(89, sf::Vector2f(-54.f, 44.f));
	Body.setPoint(90, sf::Vector2f(-50.f, 44.f));
	Body.setPoint(91, sf::Vector2f(-50.f, 48.f));
	Body.setPoint(92, sf::Vector2f(-46.f, 48.f));
	Body.setPoint(93, sf::Vector2f(-46.f, 52.f));
	Body.setPoint(94, sf::Vector2f(-41.f, 52.f));
	Body.setPoint(95, sf::Vector2f(-41.f, 58.f));
	Body.setPoint(96, sf::Vector2f(-30.f, 58.f));
	Body.setPoint(97, sf::Vector2f(-30.f, 54.f));
	Body.setPoint(98, sf::Vector2f(-10.f, 54.f));
	Body.setPoint(99, sf::Vector2f(-10.f, 56.f));
	Body.setPoint(100, sf::Vector2f(-6.f, 56.f));
	Body.setPoint(101, sf::Vector2f(-6.f, 58.f));
	Body.setPoint(102, sf::Vector2f(0.f, 58.f));


	Body.setOutlineThickness(3.f);
	Body.setFillColor(sf::Color(184,115,52,255));
	Body.scale(0.3f, 0.3f);
}

void Asteroid::setHitboxPoints() {
	hitbox.setPointCount(6);
	hitbox.setPoint(0, sf::Vector2f(-60.f, 0.f));
	hitbox.setPoint(1, sf::Vector2f(-30.f, 50.f));
	hitbox.setPoint(2, sf::Vector2f(30.f, 50.f));
	hitbox.setPoint(3, sf::Vector2f(60.f, 0.f));
	hitbox.setPoint(4, sf::Vector2f(30.f, -50.f));
	hitbox.setPoint(5, sf::Vector2f(-30.f, -50.f));

	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
}



// Overridden draw function
void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(Body, states);
	target.draw(hitbox, states);
	target.draw(hitradius);
}


void Asteroid::update(sf::Time dt) {
	sf::Transformable::move(movement * dt.asSeconds());
}



// Move the asteroid
// Overrides Transformable move function to allow storage of movement as asteroid class data member
//void Asteroid::move(sf::Time dt) {
//	sf::Transformable::move(movement * dt.asSeconds());
//}
