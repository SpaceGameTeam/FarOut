#include "PrototypeScene.h"
#include "SystemClass.h"
#include <string>



//Background stuff

Background::Background() {

	// These should be adjusted to use system wide constants when those are implemented
	int x = 1920;
	int y = 1080;
	int universeSize = 1000;
	texture.loadFromFile("Assets/pixelated_halo_starfield_by_necro_skeletal_d56he85.png");
	texture.setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, universeSize * x, universeSize * y));
	sprite.setTexture(texture, false);
	setPosition(-(universeSize * x / 2), -(universeSize * y / 2));
}

void Background::update(sf::Time dt) {}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(sprite, states);
}




//Scene stuff
// Some of the data members are dynamically allocated because constructors with arguments were written
PrototypeScene::PrototypeScene() {
	alien = new AlienShip(&ship);
	sun = new Star(30, sf::Color(219, 57, 5), 3, sf::Color(255, 154, 1), sf::Vector2f(-700, 200));
	a = new Planet(5, 100, sf::Color::Green, 0.5);
	b = new Planet(8, 140, sf::Color::Blue, 0.05);
	c = new Planet(10, 180, sf::Color::Magenta, 0.25);
	d = new Planet(4, 200, sf::Color::Yellow, 0.04);
	e = new Planet(50, 350, sf::Color::Cyan, 0.045);
	f = new Planet(25, 460, sf::Color::Green, 0.06);
	g = new Planet(10, 500, sf::Color::Blue, 0.03);
	h = new Planet(10, 540, sf::Color::Yellow, 0.1);
	i = new Planet(3, 600, sf::Color::Yellow, 0.15);
	j = new Planet(2, 15, sf::Color::White, 0.5);
	k = new Planet(2, 10, sf::Color::Yellow, 0.15);
	l = new Planet(2, 30, sf::Color::Yellow, 0.6);
	m = new Planet(1, 17, sf::Color::Yellow, 0.9);
	
	//extern SystemClass System;
	view.setSize(System.getData("DesktopX"), System.getData("DesktopY"));
}



PrototypeScene::~PrototypeScene() {
	delete alien;
	delete sun;
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
	delete i;
	delete j;
	delete k;
	delete l;
	delete m;
}




// Move anything that move gets called on
//void PrototypeScene::move(sf::Time dt){
//	//ship.move(dt);
//	//alien->move(dt);
//	//asteroid.move(dt);
//	// a->move(dt);
//	// b->move(dt);
//	//c->move(dt);
//}



// Update data members that get updated
void PrototypeScene::update(sf::Time dt) {
	bg.update(dt);
	ship.update(dt);
	alien->update(dt);
	asteroid.update(dt);
	sun->update(dt);
	a->update(dt, sun->getPosition());
	b->update(dt, sun->getPosition());
	c->update(dt, sun->getPosition());
	d->update(dt, sun->getPosition());
	e->update(dt, sun->getPosition());
	f->update(dt, sun->getPosition());
	g->update(dt, sun->getPosition());
	h->update(dt, sun->getPosition());
	i->update(dt, sun->getPosition());
	j->update(dt, g->getPosition());
	k->update(dt, d->getPosition());
	l->update(dt, i->getPosition());
	m->update(dt, l->getPosition());
	view.setCenter(ship.getPosition());
}



// Draw all the objects in the scene
void PrototypeScene::draw(sf::RenderWindow& window) {
	window.setView(view);
	window.draw(bg);
	window.draw(ship);
	window.draw(*alien);
	window.draw(*sun);
	window.draw(*a);
	window.draw(*b);
	window.draw(*c);
	window.draw(*d);
	window.draw(*e);
	window.draw(*f);
	window.draw(*g);
	window.draw(*h);
	window.draw(*i);
	window.draw(*j);
	window.draw(*k);
	window.draw(*l);
	window.draw(*m);
	window.draw(asteroid);
}



// Here so the system class can call something to know where the ship is for window.setCenter()
sf::Vector2f PrototypeScene::getCenter(){
	return ship.getPosition();
}