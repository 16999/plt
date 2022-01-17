#include "Record.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace engine;
using namespace std;

std::ofstream outfile;

Record::Record()
{

}

Record::~Record()
{

}

void Record::addAction(Action action)
{
  if (action != NO_ACTION)
    this->actionRecord["action_"+to_string(this->actionNumber++)] = action;
}

void Record::addTurn()
{
  this->turnRecord["turn_"+to_string(this->turnNumber++)] = this->actionRecord;
  this->actionRecord.clear();
  this->actionNumber = 0;
}

void Record::addGame()
{
  this->gameRecord.clear();
  this->gameRecord["game_"+to_string(this->gameNumber++)] = this->turnRecord;
  this->turnRecord.clear();
  this->turnNumber = 0;

  outfile.open("test.json",ios::app);
  outfile << this->writer.write(this->gameRecord);  //écrit l'action effectuée dans le fichier json
  outfile.close();
}

int Record::getTurnNumber() const
{
  return this->turnNumber;
}

void Record::setTurnNumber(int turnNumber)
{
  this->turnNumber = turnNumber;
}

int Record::getActionNumber() const
{
  return this->actionNumber;
}

void Record::setActionNumber(int actionNumber)
{
  this->actionNumber = actionNumber;
}

int Record::getGameNumber() const
{
  return this->gameNumber;
}

void Record::setGameNumber(int gameNumber)
{
  this->gameNumber = gameNumber;
}
