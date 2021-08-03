// Prototype Menu
#include "Scene.h"
#include "GameObject.h"
#include <string>
#include <vector>

class MenuBox : public GameObject {
    public:
        MenuBox(); 
        ~MenuBox(); 

        void update(sf::Time dt);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Texture texture;

};



class PrototypeMenu : public Scene {
    public:
        PrototypeMenu();
        ~PrototypeMenu();

        void update(sf::Time dt);
        void draw(sf::RenderWindow& window);

    private:
        MenuBox mb;
        std::vector<std::string> options;

};