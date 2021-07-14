#pragma once
#include "Scene.h"
#include "GameObject.h"



class Background : public GameObject {
public:
	Background();

	void update(sf::Time dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;

private:
	sf::Texture texture;
	sf::Sprite sprite;
};




class PrototypeScene : public Scene {
public:
	PrototypeScene();

	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);

private:
	Background bg;

};




