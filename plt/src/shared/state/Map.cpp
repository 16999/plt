#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace state;
using namespace std;



Map::Map()
{

}

Map::~Map()
{

}

void Map::init (std::string path)  //charge une map externe présente dans un fichier au format hexadécimal
{
  std::ifstream file;
  std::stringstream strStream;
  file.open(path);
  strStream << file.rdbuf(); //read the file
  this->bloc = strStream.str(); //str holds the content of the file
  file.close();
}

const std::string& Map::getBloc() const
{
  return this->bloc;
}
