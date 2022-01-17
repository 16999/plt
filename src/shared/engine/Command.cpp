#include "Command.h"
#include <iostream>
using namespace engine;
using namespace std;



int Command::getCommandID() const
{
  return this->commandID;
}

void Command::setCommandID(int commandID)
{
  this->commandID = commandID;
}
