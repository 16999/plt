#include "Surface.h"
using namespace render;




void Surface::loadMap(std::string path, sf::Vector2u size, std::vector<int> tiles, int width, int height)
{

  this->m_tileset.loadFromFile(path);        // load the tileset texture
  this->m_vertices.setPrimitiveType(sf::Quads); // resize the vertex array to fit the level size
  this->m_vertices.resize(width * height * 4);

  for (int i = 0; i < width; i++)   // populate the vertex array, with one quad per tile
      for (int j = 0; j < height; j++)
      {

          int tileNumber = tiles[i + j * width];    // get the current tile number
          int tu = tileNumber % (this->m_tileset.getSize().x / size.x); // find its position in the tileset texture
          int tv = tileNumber / (this->m_tileset.getSize().x / size.x); // find its position in the tileset texture
          sf::Vertex* quad = &this->m_vertices[(i + j * width) * 4];  // get a pointer to the current tile's quad

          // define its 4 corners
          quad[0].position = sf::Vector2f(i * size.x, j * size.y);
          quad[1].position = sf::Vector2f((i + 1) * size.x, j * size.y);
          quad[2].position = sf::Vector2f((i + 1) * size.x, (j + 1) * size.y);
          quad[3].position = sf::Vector2f(i * size.x, (j + 1) * size.y);

          // define its 4 texture coordinates
          quad[0].texCoords = sf::Vector2f(tu * size.x, tv * size.y);
          quad[1].texCoords = sf::Vector2f((tu + 1) * size.x, tv * size.y);
          quad[2].texCoords = sf::Vector2f((tu + 1) * size.x, (tv + 1) * size.y);
          quad[3].texCoords = sf::Vector2f(tu * size.x, (tv + 1) * size.y);
      }
}


void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &this->m_tileset;          // apply the tileset texture
  target.draw(this->m_vertices, states);      // draw the vertex array
}
