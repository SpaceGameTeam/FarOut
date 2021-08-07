//#include <SFML/Graphics.hpp>
//#include "SystemClass.h"

// GameObject.h contains the above includes, left for posterity
// #include "GameObject.h"

// #include "SystemClass.h"
// #include "FarOut.h"
#include "PrototypeScene.h"
#include "PrototypeMenu.h"

int main()
{

	std::shared_ptr<Scene> ps(new PrototypeScene);
    std::shared_ptr<Scene> menu(new StartMenu);

	System.addScene(1, ps);
	System.addScene(2, menu);

	System.pushScene(ps);
    System.pushScene(menu);

    System.runWindow();



    // Here for posterity

    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/

    return 0;
}
