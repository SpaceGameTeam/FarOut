// Prototype Menu
#include "Scene.h"
#include "GameObject.h"
#include <string>
#include <vector>

class MenuBox : public GameObject {
    public:
        MenuBox(); 

        void update(sf::Time dt);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Texture texture;

};

class Option {
    public:
        Option();
    
        virtual bool onSelection() = 0;

    private:

        sf::Vector2f lablePos;
        sf::Vector2f curPos;
        sf::Text lable;
};



class PrototypeMenu : public Scene {
    public:
        PrototypeMenu();

        void update(sf::Time dt);
        void draw(sf::RenderWindow& window);

    private:
        MenuBox mb;
        std::vector<std::string> options;

};



class OptStart : public Option {
    public:
        OptStart();

        bool onSelection();
};



class OptQuit : public Option {
    public:
        OptQuit();

        bool onSelection();
};



class OptCont : public Option {
    public:
        OptCont();

        bool onSelection();
};