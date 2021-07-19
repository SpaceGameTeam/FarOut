#include "SystemClass.h"


#ifndef GAMEOBJ
#define GAMEOBJ
class GameObject : public sf::Drawable, public sf::Transformable {
public:
	GameObject();

	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif