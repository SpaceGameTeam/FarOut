// Star class implementation

#include "PlanetarySystem.h"







////////////////////////////////////////////////////////////////////////////
///  Star Class 
////////////////////////////////////////////////////////////////////////////



// Default constructor makes a tiny star
Star::Star(){
    radius = 10;
    mass.setRadius(radius);
    mass.setOutlineColor(sf::Color(28, 57, 5));
    mass.setOutlineThickness(3); 
    mass.setFillColor(sf::Color(255, 154, 1));

    hitbox.setRadius(10);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

    setPosition(300, 0);
    setOrigin(radius, radius);
}



// Constructor with arguments 
Star::Star(int size, sf::Color outline, int outlineWidth, sf::Color fill, sf::Vector2f position){
    radius = size;
    mass.setRadius(size);
    mass.setOutlineColor(outline);
    mass.setOutlineThickness(outlineWidth); 
    mass.setFillColor(fill);

    hitbox.setRadius(size);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

    setPosition(position);
    setOrigin(radius, radius);
}



void Star::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(mass, states); 
    // target.draw(hitbox, states); 
}



void Star::update(sf::Time dt){}





////////////////////////////////////////////////////////////////////////////
///  Planet Class 
////////////////////////////////////////////////////////////////////////////



// Create a planet by passing in its size, distance from the center of the system, color, and speed or orbit
Planet::Planet(int radius, int dist, sf::Color color, float movementFactor=0.01): orbitDistance(dist), orbitAngle(0), angleChange(movementFactor) {
    // Make the planet with its size and color
    mass.setRadius(radius);
    mass.setFillColor(color);

    // Make the hitbox
    hitbox.setRadius(radius);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(3.f);

    // Set the origin of the planet to its center instead of the upper lefthand corner as is default
    setOrigin(radius, radius);
}



// Draw just the planet
void Planet::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    states.transform *= getTransform();
    target.draw(mass, states); 
}



// Move the planet 
void Planet::update(sf::Time dt, sf::Vector2f center) {
    orbitAngle += angleChange * dt.asSeconds();
    while (orbitAngle > 360){
        orbitAngle -= 360;
    }
    setPosition(sf::Vector2f(center.x + orbitDistance * cos(orbitAngle), center.y + orbitDistance * sin(orbitAngle)));
}



// Overload the update function from the abstract base class
void Planet::update(sf::Time dt) {
}





////////////////////////////////////////////////////////////////////////////
///  PlanetarySystem Class 
////////////////////////////////////////////////////////////////////////////



// Creates a system that's just an array, where systemObjects[0] is the star everything else orbits
// The array is created by the client and passed in as an argument
// The constructor also takes the position and number of objects total in the system as arguments
// (counting the star)
PlanetarySystem::PlanetarySystem(sf::Vector2f position, GameObject** systemObjects, int numObj){
    gravityBoundObjects = systemObjects; 
    numObjects = numObj;
    systemObjects[0]->setPosition(position);
}



// Draw each object in the planetary system 
void PlanetarySystem::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    for (int i = 0; i < numObjects; ++i){
        gravityBoundObjects[i]->draw(target, states);
    }
}



// Update each object. This doesn't seem to work -- maybe a timing issue???
void PlanetarySystem::update(sf::Time dt){
    for (int i = 0; i < numObjects; ++i){
        gravityBoundObjects[i]->update(dt);
    }

}