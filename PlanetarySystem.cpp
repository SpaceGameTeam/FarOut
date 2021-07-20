// Star class implementation

#include "PlanetarySystem.h"







////////////////////////////////////////////////////////////////////////////
///  Star Class 
////////////////////////////////////////////////////////////////////////////



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



Planet::Planet(int radius, int dist, sf::Color color, GameObject* systemCenter, float movementFactor=0.01){
    star = systemCenter;
    angleChange = movementFactor;
    mass.setRadius(radius);
    mass.setFillColor(color);
    orbitDistance = dist;

    hitbox.setRadius(radius);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(3.f);

    sf::Vector2f startPosition = sf::Vector2f (star->getPosition().x, star->getPosition().y + orbitDistance);
    setPosition(startPosition);
    setOrigin(radius, radius);
}



void Planet::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(mass, states); 
    // target.draw(hitbox, states); 
}



void Planet::update(sf::Time dt){
    orbitAngle += angleChange;
    if (orbitAngle > 360){
        orbitAngle -= 360;
    }
    setPosition(sf::Vector2f (star->getPosition().x + orbitDistance * cos(orbitAngle), star->getPosition().y + orbitDistance * sin(orbitAngle)));
}





////////////////////////////////////////////////////////////////////////////
///  PlanetarySystem Class 
////////////////////////////////////////////////////////////////////////////



PlanetarySystem::PlanetarySystem(sf::Vector2f position, GameObject** systemObjects, int numObj){
    gravityBoundObjects = systemObjects; 
    numObjects = numObj;
    systemObjects[0]->setPosition(position);
}



void PlanetarySystem::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    for (int i = 0; i < numObjects; ++i){
        gravityBoundObjects[i]->draw(target, states);
    }
}



void PlanetarySystem::update(sf::Time dt){
    for (int i = 0; i < numObjects; ++i){
        gravityBoundObjects[i]->update(dt);
    }

}