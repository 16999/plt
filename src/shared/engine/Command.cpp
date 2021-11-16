#include "Command.h"
using namespace engine;


#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;



int Command::getLastCommand() const
{

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    std::cout << "Key pressed = left" << endl;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    std::cout << "Key pressed = right" << endl;
  }



    return 0;

}
