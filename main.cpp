#include "PrototypeScene.h"

int main()
{

	std::shared_ptr<Scene> ps(new PrototypeScene);

	System.addScene(1, ps);

	System.pushScene(ps);

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
