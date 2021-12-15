#include "Record.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace engine;
using namespace std;

std::ofstream outfile;
//std::string filename = "test.json";

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
  {
    this->actionRecord["action_"+to_string(this->actionNumber)] = action;
    this->actionNumber++;
  }
}

void Record::addTurn()
{
  this->turnRecord["turn_"+to_string(this->turnNumber++)] = this->actionRecord;
  outfile.open("test.json");
  outfile << this->writer.write(this->turnRecord);
  outfile.close();
  this->actionRecord.clear();
  this->actionNumber = 0;
}
