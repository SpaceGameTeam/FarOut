// Sun class implementation

#include "SolarSystem.h"



////////////////////////////////////////////////////////////////////////////
///  Sun Class 
////////////////////////////////////////////////////////////////////////////



Sun::Sun(){

    mass.setRadius(10);
    mass.setOutlineColor(sf::Color(28, 57, 5));
    mass.setOutlineThickness(3); 

    hitbox.setRadius(10);
	hitbox.setOutlineThickness(3.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);

    setPosition(300, 0);
}