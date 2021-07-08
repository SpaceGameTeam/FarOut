#include "Ship.h"

Ship::Ship(){
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
}