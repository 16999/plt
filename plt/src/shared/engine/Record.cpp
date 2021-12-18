#include "Record.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace engine;
using namespace std;

std::ofstream outfile;

Record::Record()
{
  //outfile.open(filename.c_str());
}

Record::~Record()
{
  //outfile.close();
}

void Record::addAction(Action action)
{
  if (action != NOTHING)
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
  outfile << this->writer.write(this->gameRecord);
  outfile.close();
}
