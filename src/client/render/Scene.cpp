#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;


/*Scene::Scene(int width, int height, std::string title)
{
  this->width = width;
  this->height = height;
  this->title = title;
}*/

void Scene::init()
{
  std::cout << "-- Welcome to " << this->title << endl;
  //window.create(sf::VideoMode(this->width,this->height), this->title);
}

void Scene::refresh(void)
{
  //window.clear(sf::Color::Blue);
  //window.display();
}

void Scene::load(std::string tileset, sf::Vector2u tileSize, const int* tiles, int width, int height)
{

  m_tileset.loadFromFile(tileset);        // load the tileset texture
  m_vertices.setPrimitiveType(sf::Quads); // resize the vertex array to fit the level size
  m_vertices.resize(width * height * 4);

  // populate the vertex array, with one quad per tile
  for (int i = 0; i < width; i++)
      for (int j = 0; j < height; j++)
      {
          // get the current tile number
          int tileNumber = tiles[i + j * width];

          // find its position in the tileset texture
          int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
          int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

          // get a pointer to the current tile's quad
          sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

          // define its 4 corners
          quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
          quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
          quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
          quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

          // define its 4 texture coordinates
          quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
          quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
          quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
          quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
      }

}


void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &m_tileset;          // apply the tileset texture
  target.draw(m_vertices, states);      // draw the vertex array
}
