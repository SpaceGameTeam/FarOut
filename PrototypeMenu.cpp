#include "PrototypeMenu.h"



Menu::Menu()
{
	// Change to reletive coordinants when available
	int x = 0;
	int y = 0;

	int xSize = 200;
	int ySize = 400;
<<<<<<< HEAD

	int xPos = (x / 2) - (xSize / 2);
	int yPos = (y / 2) - (ySize / 2);


=======

	int xPos = (x / 2) - (xSize / 2);
	int yPos = (y / 2) - (ySize / 2);


>>>>>>> b2771aa848b67a6fdb727147715620143750e7ba
	// Create a menu box
	// Position is set centered in the view
	menuBox.setPosition(xPos, yPos);
	menuBox.setSize(sf::Vector2f(xSize, ySize));
	menuBox.setFillColor(sf::Color(0, 0, 0, 220));
	menuBox.setOutlineThickness(3.f);
	menuBox.setOutlineColor(sf::Color(100, 149, 237));
}



void Menu::update(sf::Time dt)
{
  // Check for input to:
  // 1. Change cursor position
  // 2. Select and option
}



void Menu::draw(sf::RenderWindow& window)
{
	window.draw(menuBox);	
  // draw options
  // draw cursor position
}



StartMenu::StartMenu()
{
  //Option * start = new OptStart(); 
  //Option * quit = new OptQuit(); 
  options.push_back(std::unique_ptr<Option>(new OptStart));
  options.push_back(std::unique_ptr<Option>(new OptQuit));
}



PauseMenu::PauseMenu()
{
  //Option * cont = new OptCont(); 
  //Option * quit = new OptQuit(); 
  options.push_back(std::unique_ptr<Option>(new OptCont));
  options.push_back(std::unique_ptr<Option>(new OptQuit));
}



// Does this need to be here?
Option::Option()
{

}



OptStart::OptStart()
{
<<<<<<< HEAD
  if (!menuFont.loadFromFile("AreaKilometer50.otf")) {
    // error
  }
  lable.setFont(menuFont);
  lable.setString("Start");
  lable.setCharacterSize(24);
  lable.setFillColor(sf::Color::White);
}

=======
  // Set the text object
>>>>>>> b2771aa848b67a6fdb727147715620143750e7ba


void OptStart::draw(sf::RenderWindow& window)
{
  window.draw(lable);
}



bool OptStart::onSelection()
{
  bool success = false;

  System.popScene();
  System.pushScene(System.getScene(1));

  return success; 
}



OptCont::OptCont()
{
  // Set the text object

}



bool OptCont::onSelection()
{  
  bool success = false;

  System.popScene();
  System.pushScene(System.getScene(1));

  return success; 

}



OptQuit::OptQuit()
{
  // Set the text object

}



bool OptQuit::onSelection()
{
  // Pop all of the scenes off of the stack
  while (System.popScene()) ;

  // Quit the program
  System.quit();

  return true;
}