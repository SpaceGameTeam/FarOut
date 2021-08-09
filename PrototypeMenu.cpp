#include "PrototypeMenu.h"



Menu::Menu()
{
	// Change to reletive coordinants when available
	int viewXpos = 0;
	int viewYpos = 0;

	xSize = 200;
	ySize = 400;

	xPos = (viewXpos / 2) - (xSize / 2);
	yPos = (viewYpos / 2) - (ySize / 2);

	// Create a menu box
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
  for(currentOption = options.begin(); currentOption != options.end(); ++currentOption)
      (*currentOption)->draw(window);
  // draw cursor position

}



StartMenu::StartMenu()
{
  options.push_back(std::unique_ptr<Option>(new OptStart));
  options.push_back(std::unique_ptr<Option>(new OptQuit));

  // Position all of the options
  for(currentOption = options.begin(); currentOption != options.end(); ++currentOption) {
      // Replace 0 with cursor size
      float optXpos = ((xPos + xSize) / 2) - (((*currentOption)->getXSize() + 0) / 2);
      float optYpos = (((yPos - ySize) / options.size()) * (currentOption - options.begin()));
      (*currentOption)->setPos(optXpos, optYpos);
  }
}



PauseMenu::PauseMenu()
{
  options.push_back(std::unique_ptr<Option>(new OptCont));
  options.push_back(std::unique_ptr<Option>(new OptQuit));
}



void Option::setPos(float xPos, float yPos)
{
  this->xPos = xPos;
  this->yPos = yPos;
}


float Option::getXSize() 
{
  return xSize;
}



float Option::getYSize() 
{
  return ySize;
}



OptStart::OptStart()
{
  if (!menuFont.loadFromFile("AreaKilometer50.otf")) {
    // error
  }
  lable.setFont(menuFont);
  lable.setString("Start");
  lable.setCharacterSize(24);
  lable.setFillColor(sf::Color::White);
  lable.setPosition(xPos, 100);
}



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
  if (!menuFont.loadFromFile("AreaKilometer50.otf")) {
    // error
  }
  lable.setFont(menuFont);
  lable.setString("Continue");
  lable.setCharacterSize(24);
  lable.setFillColor(sf::Color::White);
  lable.setPosition(50, 150);
}



void OptCont::draw(sf::RenderWindow& window)
{
  window.draw(lable);
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
  if (!menuFont.loadFromFile("AreaKilometer50.otf")) {
    // error
  }
  lable.setFont(menuFont);
  lable.setString("Continue");
  lable.setCharacterSize(24);
  lable.setFillColor(sf::Color::White);
  lable.setPosition(100, 100);


}



void OptQuit::draw(sf::RenderWindow& window)
{
  window.draw(lable);
}



bool OptQuit::onSelection()
{
  // Pop all of the scenes off of the stack
  while (System.popScene()) ;

  // Quit the program
  System.quit();

  return true;
}