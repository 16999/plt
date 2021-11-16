#include "Command.h"
using namespace engine;


#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;



int Command::getLastCommand() const
{

  std::cout << "\nTEST ENGINE" << endl;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    std::cout << "\nKey pressed = left" << endl;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    std::cout << "\nKey pressed = right" << endl;
  }



    return 0;

}
