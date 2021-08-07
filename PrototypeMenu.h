// Prototype Menu
// This is a simple demonstration of the menu system in its most basic form
// using two variations: a start menu and a pause menu.

#include "SystemClass.h"
#include "Scene.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include <memory>





class Option {
    public:
        // Constructor building the option
        Option();
    
        virtual void draw(sf::RenderWindow& window) = 0;
        
        // Actions taken when the option is selected (to be overloaded by dev)
        virtual bool onSelection() = 0;

    protected:
        // Position of the Lable reletive to the window
        sf::Vector2f lablePos;  
        // Position of the Curser when the option is selected reletive to
        // to the window box                     
        sf::Vector2f curPos;
        // Text representation of the option
        sf::Font menuFont;
        sf::Text lable;
        // Add any other representations of the object
};



class Menu : public Scene {
    public:
        Menu();

        void update(sf::Time dt);
        void draw(sf::RenderWindow& window);

    protected:
        // Menu box drawn behind the options 
        // I'm thinking of just integrating this into the menu
        // MenuBox mb;

        // Menu box drawn behind the options
	    sf::RectangleShape menuBox;
        // List of opti>ons availible in the menu
        std::vector<std::unique_ptr<Option>> options;
        // Position of the curser in the menu relitive to the window
        sf::Vector2f curPos;
};



// Add class Start Menu
class StartMenu : public Menu {
    public:
        StartMenu();
    private:
};



// Add class Pause Menu
class PauseMenu : public Menu {
    public:
        PauseMenu();

    private:
};



// Start option for the start menu
class OptStart : public Option {
    public:
        OptStart();

        void draw(sf::RenderWindow& window);

        // Pops the menu and pushes the main scene
        bool onSelection();
};



// Quit option for the start and pause menus
class OptQuit : public Option {
    public:
        OptQuit();

        void draw(sf::RenderWindow& window);

        // Pops all scenes from the stack and quits the menu
        bool onSelection();
};



// Continue option for the pause menu
class OptCont : public Option {
    public:
        OptCont();

        void draw(sf::RenderWindow& window);

        // Pops the menu, pushes the main scene and unpauses the game
        bool onSelection();
};