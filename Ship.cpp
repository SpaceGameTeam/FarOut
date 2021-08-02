#include "Ship.h"

Ship::Ship(){
    // Check movementSpeed setting when star background is working
    movementSpeed = 363.0;

    // Create the ship
	// setBlueShipPoints(&body);
	// body.setOutlineThickness(3.f);
	// body.setFillColor(sf::Color(22, 69, 149));
	// body.scale(0.75f, 0.75f);

	// Create the ship
	body.setPrimitiveType(sf::TriangleStrip);
	body.resize(15);
	
	// setBlueShipPoints(&hitbox);
	// hitbox.setOutlineThickness(3.f);
	// hitbox.setFillColor(sf::Color::Transparent);
	// hitbox.setOutlineColor(sf::Color::Red);
	// hitbox.scale(0.75f, 0.75f);
    	
	body[0].position = sf::Vector2f(0.f, 0.f);
	body[1].position = sf::Vector2f(-13.f, 0.f);
	body[2].position = sf::Vector2f(-13.f, 38.f);
	body[3].position = sf::Vector2f(0.f, 0.f);
	body[4].position = sf::Vector2f(0.f, 62.f);
	body[5].position = sf::Vector2f(13.f, 0.f);
	body[6].position = sf::Vector2f(13.f, 38.f);


	body[0].color = sf::Color::White;
	body[1].color = sf::Color(22, 69, 149, 255);
	body[2].color = sf::Color(22, 69, 149, 255);
	body[3].color = sf::Color::White;
	body[4].color = sf::Color::White;
	body[5].color = sf::Color(22, 69, 149, 255);
	body[6].color = sf::Color(22, 69, 149, 255);


    thruster1.setPrimitiveType(sf::TriangleStrip);
    thruster1.resize(6);
	thruster1[0].position = sf::Vector2f(-19.f, 4.f);
	thruster1[1].position = sf::Vector2f(-19.f, 12.f);
	thruster1[2].position = sf::Vector2f(-13.f, -8.f);
	thruster1[3].position = sf::Vector2f(-13.f, 17.f);
	thruster1[4].position = sf::Vector2f(-7.f, 4.f);
	thruster1[5].position = sf::Vector2f(-7.f, 12.f);


/*
	body[0].position = sf::Vector2f(-19.f, 4.f);
	body[1].position = sf::Vector2f(-19.f, 12.f);
	body[2].position = sf::Vector2f(0.f, 0.f);
	body[3].position = sf::Vector2f(-13.f, 17.f);
	body[4].position = sf::Vector2f(0.f, 38.f);
	body[5].position = sf::Vector2f(-13.f, 38.f);
	body[6].position = sf::Vector2f(0.f, 62.f);
	body[8].position = sf::Vector2f(13.f, 38.f);
	body[9].position = sf::Vector2f(0.f, 38.f);
	body[10].position = sf::Vector2f(13.f, 17.f);
	body[11].position = sf::Vector2f(0.f, 0.f);
	body[12].position = sf::Vector2f(19.f, 12.f);
	body[13].position = sf::Vector2f(19.f, 4.f);
	body[14].position = sf::Vector2f(0.f, 0.f);

	body[0].color = sf::Color(22, 69, 149, 255);
	body[1].color = sf::Color(22, 69, 149, 255);
	body[2].color = sf::Color::White;
	body[3].color = sf::Color(22, 69, 149, 255);
	body[4].color = sf::Color::White;
	body[5].color = sf::Color(22, 69, 149, 255);
	// body[6].color = sf::Color::White;
	body[7].color = sf::Color(22, 69, 149, 255);
	body[8].color = sf::Color(22, 69, 149, 255);
	// body[9].color = sf::Color::White;
	body[10].color = sf::Color(22, 69, 149, 255);
	// body[11].color = sf::Color::White;
	body[12].color = sf::Color(22, 69, 149, 255);
	body[13].color = sf::Color(22, 69, 149, 255);
	// body[14].color = sf::Color::White;
*/
	// body[1].position = sf::Vector2f(-7.f, 0.f);
	// body[2].position = sf::Vector2f(-13.f, -8.f);
	// body[12].position = sf::Vector2f(13.f, -8.f);
	// body[13].position = sf::Vector2f(7.f, 0.f);
	/*
	body[0].position = sf::Vector2f(0.f, 0.f);
	body[1].position = sf::Vector2f(-7.f, 0.f);
	body[2].position = sf::Vector2f(-13.f, -8.f);
	body[3].position = sf::Vector2f(-19.f, 4.f);
	body[4].position = sf::Vector2f(-19.f, 12.f);
	body[5].position = sf::Vector2f(-13.f, 17.f);
	body[6].position = sf::Vector2f(-13.f, 38.f);
	body[7].position = sf::Vector2f(0.f, 62.f);
	body[8].position = sf::Vector2f(13.f, 38.f);
	body[9].position = sf::Vector2f(13.f, 17.f);
	body[10].position = sf::Vector2f(19.f, 12.f);
	body[11].position = sf::Vector2f(19.f, 4.f);
	body[12].position = sf::Vector2f(13.f, -8.f);
	body[13].position = sf::Vector2f(7.f, 0.f);
	*/
    setScale(sf::Vector2f(4.f, 4.f));
    setPosition(0, 0);
	// setRotation(180);
	setOrigin(sf::Vector2f(0, 23));
}


// Sets points for a basic spacecraft outline
void Ship::setMercuryPoints(sf::ConvexShape * shape){
    shape->setPointCount(36);
	shape->setPoint(0, sf::Vector2f(0.f, 45.f));
	shape->setPoint(1, sf::Vector2f(-7.f, 45.f));
	shape->setPoint(2, sf::Vector2f(-7.f, 30.f));
	shape->setPoint(3, sf::Vector2f(-9.f, 30.f));
	shape->setPoint(4, sf::Vector2f(-11.f, 15.f));
	shape->setPoint(5, sf::Vector2f(-30.f, -50.f));
	shape->setPoint(6, sf::Vector2f(-30.f, -51.f));
	shape->setPoint(7, sf::Vector2f(-30.f, -52.f));
	shape->setPoint(8, sf::Vector2f(-22.f, -54.f));
	shape->setPoint(9, sf::Vector2f(-17.f, -56.f));
	shape->setPoint(10, sf::Vector2f(-13.f, -58.f));
	shape->setPoint(11, sf::Vector2f(-10.f, -60.f));
	shape->setPoint(12, sf::Vector2f(-10.f, -60.f));
	shape->setPoint(13, sf::Vector2f(-10.f, -70.f));
	shape->setPoint(14, sf::Vector2f(-7.f, -73.f));
	shape->setPoint(15, sf::Vector2f(-9.f, -75.f));
	shape->setPoint(16, sf::Vector2f(-6.f, -74.f));
	shape->setPoint(17, sf::Vector2f(-4.f, -72.f));
	shape->setPoint(18, sf::Vector2f(-2.f, -75.f));
	shape->setPoint(19, sf::Vector2f(2.f, -75.f));
	shape->setPoint(20, sf::Vector2f(4.f, -72.f));
	shape->setPoint(21, sf::Vector2f(6.f, -74.f));
	shape->setPoint(22, sf::Vector2f(9.f, -75.f));
	shape->setPoint(23, sf::Vector2f(7.f, -73.f));
	shape->setPoint(24, sf::Vector2f(10.f, -70.f));
	shape->setPoint(25, sf::Vector2f(10.f, -60.f));
	shape->setPoint(26, sf::Vector2f(13.f, -58.f));
	shape->setPoint(27, sf::Vector2f(17.f, -56.f));
	shape->setPoint(28, sf::Vector2f(22.f, -54.f));
	shape->setPoint(29, sf::Vector2f(30.f, -52.f));
	shape->setPoint(30, sf::Vector2f(30.f, -51.f));
	shape->setPoint(31, sf::Vector2f(30.f, -50.f));
	shape->setPoint(32, sf::Vector2f(11.f, 15.f));
	shape->setPoint(33, sf::Vector2f(9.f, 30.f));
	shape->setPoint(34, sf::Vector2f(7.f, 30.f));
	shape->setPoint(35, sf::Vector2f(7.f, 45.f));
}



// Sets points for blue ship 
// Ship body #2
void Ship::setBlueShipPoints(sf::ConvexShape * shape) {
	shape->setPointCount(14);
	shape->setPoint(0, sf::Vector2f(0.f, 0.f));
	shape->setPoint(1, sf::Vector2f(-7.f, 0.f));
	shape->setPoint(2, sf::Vector2f(-13.f, -8.f));
	shape->setPoint(3, sf::Vector2f(-19.f, 4.f));
	shape->setPoint(4, sf::Vector2f(-19.f, 12.f));
	shape->setPoint(5, sf::Vector2f(-13.f, 17.f));
	shape->setPoint(6, sf::Vector2f(-13.f, 38.f));
	shape->setPoint(7, sf::Vector2f(0.f, 62.f));
	shape->setPoint(8, sf::Vector2f(13.f, 38.f));
	shape->setPoint(9, sf::Vector2f(13.f, 17.f));
	shape->setPoint(10, sf::Vector2f(19.f, 12.f));
	shape->setPoint(11, sf::Vector2f(19.f, 4.f));
	shape->setPoint(12, sf::Vector2f(13.f, -8.f));
	shape->setPoint(13, sf::Vector2f(7.f, 0.f));
	shape->setOrigin(sf::Vector2f(0, 23));
}



// Overridden draw function
void Ship::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    target.draw(body, states); 
    target.draw(thruster1, states); 
    // target.draw(thruster2, states); 
}



// Move or rotate the ship when keys are pressed
void Ship::update(sf::Time dt){

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

    sf::Transformable::move(movement * dt.asSeconds());

}



// Move the ship
// Overrides Transformable move function to allow storage of movement as Ship class data member
//void Ship::move(sf::Time dt){
//    sf::Transformable::move(movement * dt.asSeconds());
//}
