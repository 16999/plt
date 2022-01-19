#include "MapSurface.h"
#include <iostream>
using namespace render;

const int BLOC_SIZE = 36;
const int MAP_WIDTH = 25;
const int MAP_HEIGHT = 15;



void MapSurface::initTileset(std::string path)
{
  this->mapTileset.loadFromFile(path);
  this->mapVertices.setPrimitiveType(sf::Quads); // resize the vertex array to fit the level size
  this->mapVertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);
}

void MapSurface::loadTileset(std::string tiles)
{
  for (int i = 0; i < MAP_WIDTH; i++)   // populate the vertex array, with one quad per tile
      for (int j = 0; j < MAP_HEIGHT; j++)
      {
          int tileNumber = tiles[i + j * MAP_WIDTH];    // get the current tile number
          int tu = tileNumber % (this->mapTileset.getSize().x / BLOC_SIZE); // find its position in the tileset texture
          int tv = tileNumber / (this->mapTileset.getSize().x / BLOC_SIZE); // find its position in the tileset texture
          sf::Vertex* quad = &this->mapVertices[(i + j * MAP_WIDTH) * 4];  // get a pointer to the current tile's quad

          // define its 4 corners
          quad[0].position = sf::Vector2f(i * BLOC_SIZE, j * BLOC_SIZE);
          quad[1].position = sf::Vector2f((i + 1) * BLOC_SIZE, j * BLOC_SIZE);
          quad[2].position = sf::Vector2f((i + 1) * BLOC_SIZE, (j + 1) * BLOC_SIZE);
          quad[3].position = sf::Vector2f(i * BLOC_SIZE, (j + 1) * BLOC_SIZE);

          // define its 4 texture coordinates
          quad[0].texCoords = sf::Vector2f(tu * BLOC_SIZE, tv * BLOC_SIZE);
          quad[1].texCoords = sf::Vector2f((tu + 1) * BLOC_SIZE, tv * BLOC_SIZE);
          quad[2].texCoords = sf::Vector2f((tu + 1) * BLOC_SIZE, (tv + 1) * BLOC_SIZE);
          quad[3].texCoords = sf::Vector2f(tu * BLOC_SIZE, (tv + 1) * BLOC_SIZE);
      }
}


void MapSurface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &this->mapTileset;          // apply the tileset texture
  target.draw(this->mapVertices, states);      // draw the vertex array
}

