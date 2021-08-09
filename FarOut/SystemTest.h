#include "FarOut.h"

// Scene Testing 
class DummyScene : public Scene {
public:
    DummyScene(int id):Scene(id) {};
	void update(sf::Time dt) {};
	void draw(sf::RenderWindow &window) {};
};
