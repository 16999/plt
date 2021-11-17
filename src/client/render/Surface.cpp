#include "Surface.h"
#include <iostream>
using namespace render;
using namespace std;

Surface::Surface()
{

}

Surface::~Surface()
{

}

void Surface::initTileset(std::string path)
{
  this->mapTileset.loadFromFile(path);
}

void Surface::initFont(std::string path)
{
  this->font.loadFromFile(path);
  this->text[0].setFont(this->font);
  this->text[1].setFont(this->font);
}

void Surface::initTank(int ID, std::string path)
{
  this->tankTexture[ID].loadFromFile(path);
}

void Surface::loadMap(std::string tiles)
{
  this->mapVertices.setPrimitiveType(sf::Quads); // resize the vertex array to fit the level size
  this->mapVertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);

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

void Surface::loadText(std::string data, int ID, sf::Color color)
{
  this->panel[ID].setFillColor(color);
  this->panel[ID].setSize(sf::Vector2f(PANEL_WIDTH,WINDOW_HEIGHT/2));
  this->panel[ID].setPosition(WINDOW_WIDTH-PANEL_WIDTH,ID*WINDOW_HEIGHT/2);
  this->text[ID].setString(data);
  this->text[ID].setCharacterSize(16);
  this->text[ID].setFillColor(sf::Color(255,255,255));
  this->text[ID].setPosition(WINDOW_WIDTH-PANEL_WIDTH+8,(ID*WINDOW_HEIGHT/2)+8);
}

void Surface::loadTank(int ID,state::Element element)
{
  this->tankSprite[ID].setTexture(this->tankTexture[ID]);
  this->tankSprite[ID].setPosition(element.getX(),element.getY());
  this->tankSprite[ID].setOrigin((float)(this->tankTexture[ID].getSize().x)/2,(float)(this->tankTexture[ID].getSize().y));
  this->tankSprite[ID].rotate(element.getAngle());
}

void Surface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &this->mapTileset;          // apply the tileset texture
  target.draw(this->mapVertices, states);      // draw the vertex array
  target.draw(this->panel[0], states);
  target.draw(this->panel[1], states);
  target.draw(this->text[0], states);
  target.draw(this->text[1], states);
  target.draw(this->tankSprite[0], states);
  target.draw(this->tankSprite[1], states);
}
