#include "Asteroid.h"

Ship::Ship() {
	// Check movementSpeed setting when star background is working
	movementSpeed = 363.0;

	// Create the asteroid
	// Can be exchanged with other functions to create other ships
	setMercuryPoints();

	setPosition(0, 0);
}




// Sets points for the asteroid
void Ship::setMercuryPoints() {
	Body.setPointCount();
	Body.setPoint(0, sf::Vector2f(0.f, 0.f));
	Body.setPoint(1, sf::Vector2f(0.f, 6.f));
	Body.setPoint(2, sf::Vector2f(0.6.f, 6.f));
	Body.setPoint(3, sf::Vector2f(0.6.f, 5.8.f));
	Body.setPoint(4, sf::Vector2f(1.7.f, 5.8.f));
	Body.setPoint(5, sf::Vector2f(1.7.f, 5.6.f));
	Body.setPoint(6, sf::Vector2f(3.2.f, 5.6.f));
	Body.setPoint(7, sf::Vector2f(3.2.f, 5.4.f));
	Body.setPoint(8, sf::Vector2f(3.4.f, 5.4.f));
	Body.setPoint(9, sf::Vector2f(3.4.f, 5.2.f));
	Body.setPoint(10, sf::Vector2f(3.6.f, 5.2.f));
	Body.setPoint(11, sf::Vector2f(3.6.f, 5.f));
	Body.setPoint(12, sf::Vector2f(3.8.f, 5.f));
	Body.setPoint(13, sf::Vector2f(3.8.f, 4.8.f));
	Body.setPoint(14, sf::Vector2f(3.9.f, 4.8.f));
	Body.setPoint(15, sf::Vector2f(3.9.f, 4.6.f));
	Body.setPoint(16, sf::Vector2f(4.1.f, 4.6.f));
	Body.setPoint(17, sf::Vector2f(4.1.f, 4.4.f));
	Body.setPoint(18, sf::Vector2f(4.3.f, 4.4.f));
	Body.setPoint(19, sf::Vector2f(4.3.f, 4.1.f));
	Body.setPoint(20, sf::Vector2f(4.5.f, 4.1.f));
	Body.setPoint(21, sf::Vector2f(4.5.f, 3.7.f));
	Body.setPoint(22, sf::Vector2f(4.7.f, 3.7.f));
	Body.setPoint(23, sf::Vector2f(4.7.f, 1.4.f));
	Body.setPoint(24, sf::Vector2f(4.8.f, 1.4.f));
	Body.setPoint(25, sf::Vector2f(4.8.f, 0.5.f));
	Body.setPoint(26, sf::Vector2f(5.f, 0.5.f));
	Body.setPoint(27, sf::Vector2f(5.f, 0,1.f));
	Body.setPoint(28, sf::Vector2f(5.2.f, 0.1.f));
	Body.setPoint(29, sf::Vector2f(5.2.f, -0.3.f));
	Body.setPoint(30, sf::Vector2f(5.4.f, -0.3.f));
	Body.setPoint(31, sf::Vector2f(5.4.f, -1.f));
	Body.setPoint(32, sf::Vector2f(5.6.f, -1.f));
	Body.setPoint(33, sf::Vector2f(5.6.f, -1.8.f));
	Body.setPoint(34, sf::Vector2f(5.8.f, -1.8.f));
	Body.setPoint(35, sf::Vector2f(5.8.f, -2.2.f));
	Body.setPoint(36, sf::Vector2f(6.f, -2.2.f));
	Body.setPoint(37, sf::Vector2f(6.f, -3.3.f));
	Body.setPoint(38, sf::Vector2f(5.8.f, -3.3.f));
	Body.setPoint(39, sf::Vector2f(5.8.f, -3.5.f));
	Body.setPoint(40, sf::Vector2f(5.6.f, -3.5.f));
	Body.setPoint(41, sf::Vector2f(5.6.f, -3.7.f));
	Body.setPoint(42, sf::Vector2f(5.4.f, -3.7.f));
	Body.setPoint(43, sf::Vector2f(5.4.f, -3.9.f));
	Body.setPoint(44, sf::Vector2f(5.2.f, -3.9.f));
	Body.setPoint(45, sf::Vector2f(5.2.f, -4.6.f));
	Body.setPoint(46, sf::Vector2f(5.f, -4.6.f));
	Body.setPoint(47, sf::Vector2f(5.f, -4.8.f));
	Body.setPoint(48, sf::Vector2f(4.7.f, -4.8.f));
	Body.setPoint(49, sf::Vector2f(4.7.f, -5.f));
	Body.setPoint(50, sf::Vector2f(4.3.f, -5.f));
	Body.setPoint(51, sf::Vector2f(4.3.f, -4.8.f));
	Body.setPoint(52, sf::Vector2f(3.8.f, -4.8.f));
	Body.setPoint(53, sf::Vector2f(3.8.f, -5.f));
	Body.setPoint(54, sf::Vector2f(1.8.f, -5.f));
	Body.setPoint(55, sf::Vector2f(1.8.f, -5.2.f));
	Body.setPoint(56, sf::Vector2f(1.6.f, -5.2.f));
	Body.setPoint(57, sf::Vector2f(1.6.f, -5.6.f));
	Body.setPoint(58, sf::Vector2f(1.f, -5.6.f));
	Body.setPoint(59, sf::Vector2f(1.f, -6.f));
	Body.setPoint(60, sf::Vector2f(-0.2.f, -6.f));
	Body.setPoint(61, sf::Vector2f(-0.2.f, -5.8.f));
	Body.setPoint(62, sf::Vector2f(-1.f, -5.8.f));
	Body.setPoint(63, sf::Vector2f(-1.f, -5.4.f));
	Body.setPoint(64, sf::Vector2f(-1.4.f, -5.4.f));
	Body.setPoint(65, sf::Vector2f(-1.4.f, -5.f));
	Body.setPoint(66, sf::Vector2f(-1.7.f, -5.f));
	Body.setPoint(67, sf::Vector2f(-1.7.f, -4.f));
	Body.setPoint(68, sf::Vector2f(-2.f, -4.f));
	Body.setPoint(69, sf::Vector2f(-2.f, -3.2.f));
	Body.setPoint(70, sf::Vector2f(-2.3.f, -3.2.f));
	Body.setPoint(71, sf::Vector2f(-2.3.f, -2.6.f));
	Body.setPoint(72, sf::Vector2f(-4.3.f, -2.6.f));
	Body.setPoint(73, sf::Vector2f(-4.3.f, -2.2.f));
	Body.setPoint(74, sf::Vector2f(-5.f, -2.2.f));
	Body.setPoint(75, sf::Vector2f(-5.f, -1.8.f));
	Body.setPoint(76, sf::Vector2f(-5.5.f, -1.8.f));
	Body.setPoint(77, sf::Vector2f(-5.5.f, -1.6.f));
	Body.setPoint(78, sf::Vector2f(-5.7.f, -1.6.f));
	Body.setPoint(79, sf::Vector2f(-5.7.f, -0.6.f));
	Body.setPoint(80, sf::Vector2f(-5.6.f, -0.6.f));
	Body.setPoint(81, sf::Vector2f(-5.6.f, 1.2.f));
	Body.setPoint(82, sf::Vector2f(-5.7.f, 1.2.f));
	Body.setPoint(83, sf::Vector2f(-5.7.f, 1.6.f));
	Body.setPoint(84, sf::Vector2f(-5.9.f, 1.6.f));
	Body.setPoint(85, sf::Vector2f(-5.9.f, 2.4.f));
	Body.setPoint(86, sf::Vector2f(-5.7.f, 2.4.f));
	Body.setPoint(87, sf::Vector2f(-5.7.f, 3.9.f));
	Body.setPoint(88, sf::Vector2f(-5.4.f, 3.9.f));
	Body.setPoint(89, sf::Vector2f(-5.4.f, 4.4.f));
	Body.setPoint(90, sf::Vector2f(-5.f, 4.4.f));
	Body.setPoint(91, sf::Vector2f(-5.f, 4.8.f));
	Body.setPoint(92, sf::Vector2f(-4.6.f, 4.8.f));
	Body.setPoint(93, sf::Vector2f(-4.6.f, 5.2.f));
	Body.setPoint(94, sf::Vector2f(-4.1.f, 5.2.f));
	Body.setPoint(95, sf::Vector2f(-4.1.f, 5.8.f));
	Body.setPoint(96, sf::Vector2f(-3.f, 5.8.f));
	Body.setPoint(97, sf::Vector2f(-3.f, 5.4.f));
	Body.setPoint(98, sf::Vector2f(-1.f, 5.4.f));
	Body.setPoint(99, sf::Vector2f(-1.f, 5.6.f));
	Body.setPoint(100, sf::Vector2f(-0.6.f, 5.6.f));
	Body.setPoint(101, sf::Vector2f(-0.6.f, 5.8.f));
	Body.setPoint(102, sf::Vector2f(0.f, 5.8.f));






	Body.setOutlineThickness(3.f);
	Body.setFillColor(sf::Color::Blue);
	Body.scale(0.75f, 0.75f);
}



// Overridden draw function
void Ship::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(Body, states);
}






// Move the asteroid
// Overrides Transformable move function to allow storage of movement as asteroid class data member
void Ship::move(sf::Time dt) {
	sf::Transformable::move(movement * dt.asSeconds());
}
