#include "PrototypeMenu.h"

MenuBox::MenuBox()
{
    // Set Dimentions 
    // Set Transparentcy 
    // Set Wallpaper
    // Set Font
    // Set Sound

}



void MenuBox::update(sf::Time dt)
{

}



void MenuBox::draw(sf::RenderTarget& target, sf::RenderStates state) const
{

}


Option::Option()
{

}



PrototypeMenu::PrototypeMenu()
{
	// Change to reletive coordinants when available
	int x = 0;
	int y = 0;

	int xSize = 200;
	int ySize = 400;

	int xPos = (x / 2) - (xSize / 2);
	int yPos = (y / 2) - (ySize / 2);


	// Create a menu box
	// Position is set centered in the view
	menuBox.setPosition(xPos, yPos);
	menuBox.setSize(sf::Vector2f(xSize, ySize));
	menuBox.setFillColor(sf::Color(0, 0, 0, 220));
	menuBox.setOutlineThickness(3.f);
	menuBox.setOutlineColor(sf::Color(100, 149, 237));

	// Draw the text options

}



void PrototypeMenu::update(sf::Time dt)
{

}


void PrototypeMenu::draw(sf::RenderWindow& window)
{
	window.draw(menuBox);	

}



OptStart::OptStart()
{

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

}



bool OptQuit::onSelection()
{
  while (System.popScene()) ;

  System.quit();

  return true;
}
