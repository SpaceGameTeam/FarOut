#include "PrototypeMenu.h"

MenuBox::MenuBox()
{

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

}



void PrototypeMenu::update(sf::Time dt)
{

}


void PrototypeMenu::draw(sf::RenderWindow& window)
{

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

  // System.quit()?

  return true;
}