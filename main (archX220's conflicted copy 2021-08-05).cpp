//#include <SFML/Graphics.hpp>
//#include "SystemClass.h"

// GameObject.h contains the above includes, left for posterity
// #include "GameObject.h"

#include "SystemClass.h"
#include "PrototypeScene.h"
#include "PrototypeMenu.h"

int main()
{

    std::shared_ptr<Scene> startmenu(new StartMenu);
    std::shared_ptr<Scene> pausemenu(new PauseMenu);
    std::shared_ptr<Scene> ps(new PrototypeScene);

    System.addScene(1, startmenu);
    System.addScene(2, pausemenu);
    System.addScene(3, ps);    	

    // Start the game
    // System.pushScene(startmenu);

    // Testing
    //System.pushScene(ps);
    System.pushScene(startmenu);

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
