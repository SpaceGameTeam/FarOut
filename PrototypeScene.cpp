#include "PrototypeScene.h"
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
	// a = new Planet(5, 100, sf::Color::Green, sun, 0.01);
	// b = new Planet(8, 140, sf::Color::Blue, 0.001);
	c = new Planet(10, 180, sf::Color::Magenta, 0.005);
	/*
	d = new Planet(4, 200, sf::Color::Yellow, sun, 0.001);
	e = new Planet(50, 350, sf::Color::Cyan, sun, 0.0009);
	f = new Planet(25, 460, sf::Color::Green, sun, 0.0008);
	g = new Planet(10, 500, sf::Color::Blue, sun, 0.0009);
	h = new Planet(10, 540, sf::Color::Yellow, sun, 0.002);
	i = new Planet(3, 600, sf::Color::Yellow, sun, 0.003);
	j = new Planet(2, 15, sf::Color::White, g, 0.001);
	k = new Planet(2, 10, sf::Color::Yellow, d, 0.03);
	l = new Planet(2, 30, sf::Color::Yellow, i, 0.013);
	m = new Planet(1, 17, sf::Color::Yellow, l, 0.05);
	*/
}



PrototypeScene::~PrototypeScene() {
	delete alien;
	delete sun;
	// delete a;
	// delete b;
	delete c;
	/*
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
	*/
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
	// a->update(dt);
	// b->update(dt);
	c->update(dt, sun->getPosition());
	/*
	d->update(dt);
	e->update(dt);
	f->update(dt);
	g->update(dt);
	h->update(dt);
	i->update(dt);
	j->update(dt);
	k->update(dt);
	l->update(dt);
	m->update(dt);
	*/
}



// Draw all the objects in the scene
void PrototypeScene::draw(sf::RenderWindow& window) {
	window.draw(bg);
	window.draw(ship);
	window.draw(*alien);
	window.draw(*sun);
	// window.draw(*a);
	// window.draw(*b);
	window.draw(*c);
	/*
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
	*/
	window.draw(asteroid);
}



// Here so the system class can call something to know where the ship is for window.setCenter()
sf::Vector2f PrototypeScene::getCenter(){
	return ship.getPosition();
}