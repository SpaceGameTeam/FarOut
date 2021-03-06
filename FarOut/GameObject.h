// FarOut - GameObject Class

#ifndef GAMEOBJ
#define GAMEOBJ
#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable, public sf::Transformable {
public:
	GameObject();

	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif