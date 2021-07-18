// Sun class implementation

#include "SolarSystem.h"



////////////////////////////////////////////////////////////////////////////
///  Sun Class 
////////////////////////////////////////////////////////////////////////////



Sun::Sun(){

    mass.setRadius(10);
    mass.setOutlineColor(sf::Color(28, 57, 5));
    mass.setOutlineThickness(3); 
    mass.setFillColor(sf::Color(255, 154, 1));

    hitbox.setRadius(10);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

    setPosition(300, 0);
}



void Sun::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(mass, states); 
    target.draw(hitbox, states); 
}



void Sun::update(sf::Time dt){}




////////////////////////////////////////////////////////////////////////////
///  Planet Class 
////////////////////////////////////////////////////////////////////////////



Planet::Planet(int radius, int dist, sf::Color color, Sun* systemCenter){
    sun = systemCenter;
    mass.setRadius(radius);
    mass.setFillColor(color);
    orbitDistance = dist;

    hitbox.setRadius(radius);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(3.f);

    sf::Vector2f startPosition = sf::Vector2f (sun->getPosition().x, sun->getPosition().y + orbitDistance);
    setPosition(startPosition);
}



void Planet::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(mass, states); 
    target.draw(hitbox, states); 
}



void Planet::update(sf::Time dt){
    // sf::Vector2f u = sf::Vector2f (sun->getPosition().x + orbitDistance, 0);
    // sf::Vector2f v = getPosition();
    // float dotProduct = u.x * v.x + u.y * v.y;
    // orbitAngle = dotProduct / (orbitDistance * orbitDistance);
    // float addAngle = dt.asSeconds() / 36000000000000;
    // orbitAngle += addAngle / 10000000000;
    orbitAngle += 0.01;
    if (orbitAngle > 360){
        orbitAngle -= 360;
    }
    // movement = sf::Vector2f (sun->getPosition().x + orbitDistance * cos(orbitAngle), sun->getPosition().y + orbitDistance * sin(orbitAngle)) - getPosition();
    setPosition(sf::Vector2f (sun->getPosition().x + orbitDistance * cos(orbitAngle), sun->getPosition().y + orbitDistance * sin(orbitAngle)));
}



// Move the planet 
// Overrides Transformable move function to allow storage of movement as AlienShip class data member
void Planet::move(sf::Time dt){
    // sf::Transformable::move(movement * dt.asSeconds());
}