#include "PlayerSurface.h"
#include <iostream>
using namespace render;
using namespace std;

#define BLOC_SIZE 36
#define MAP_WIDTH 20
#define MAP_HEIGHT 15
#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540


PlayerSurface::PlayerSurface()
{
  this->playerSprite.resize(3);
  this->playerTexture.resize(3);
}

PlayerSurface::~PlayerSurface()
{

}

sf::Sprite PlayerSurface::getPlayerSprite(int elementID)
{
  return playerSprite[elementID];
}

void PlayerSurface::initText(std::string path)
{
  this->font.loadFromFile(path);
  this->text.setFont(this->font);
}

void PlayerSurface::initPlayer(std::vector<std::string> path)
{
  this->playerTexture[TANK].loadFromFile(path[TANK]);
  this->playerTexture[TURRET].loadFromFile(path[TURRET]);
  this->playerTexture[BULLET].loadFromFile(path[BULLET]);
  this->playerSprite[TANK].setOrigin((float)(this->playerTexture[TANK].getSize().x)/2,(float)(this->playerTexture[0].getSize().y));
  this->playerSprite[TURRET].setOrigin(0,(float)(this->playerTexture[TURRET].getSize().y)/2);
  this->playerSprite[BULLET].setOrigin((float)(this->playerTexture[BULLET].getSize().x)/2,(float)(this->playerTexture[BULLET].getSize().y)/2);
}

void PlayerSurface::loadText(state::Player player)
{
  this->text.setString(player.getTextData());
  this->text.setCharacterSize(14);
  this->text.setFillColor(sf::Color(255,255,255));
  this->text.setPosition((BLOC_SIZE*MAP_WIDTH)+8,(player.getID()*WINDOW_HEIGHT/2)+8);
}

void PlayerSurface::loadPlayer(state::Player player)
{
  this->playerSprite[TANK].setTexture(this->playerTexture[TANK]);
  this->playerSprite[TURRET].setTexture(this->playerTexture[TURRET]);
  this->playerSprite[BULLET].setTexture(this->playerTexture[BULLET]);
  this->playerSprite[TANK].setPosition(player.getTank().getX(),player.getTank().getY());
  this->playerSprite[TURRET].setPosition(player.getTurret().getX(),player.getTurret().getY());
  this->playerSprite[BULLET].setPosition(player.getBullet().getX(),player.getBullet().getY());
  this->playerSprite[TANK].setRotation(player.getTank().getAngle());
  this->playerSprite[TURRET].setRotation(player.getTurret().getAngle());
  this->playerSprite[BULLET].setRotation(player.getBullet().getAngle());
}

void PlayerSurface::draw(sf::RenderWindow& window)
{
  window.draw(this->text);
  window.draw(this->playerSprite[BULLET]);
  window.draw(this->playerSprite[TURRET]);
  window.draw(this->playerSprite[TANK]);
}
