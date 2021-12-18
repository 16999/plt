#include "PlayerSurface.h"
#include <iostream>
using namespace render;
using namespace std;



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
  this->text.setPosition(2,2+16*player.getID());
}

void PlayerSurface::loadPlayer(state::Player player)
{
  this->playerSprite[TANK].setTexture(this->playerTexture[TANK]);
  this->playerSprite[TURRET].setTexture(this->playerTexture[TURRET]);
  this->playerSprite[BULLET].setTexture(this->playerTexture[BULLET]);
  this->playerSprite[TANK].setPosition(player.getTank().getX(),player.getTank().getY());
  this->playerSprite[TURRET].setPosition(player.getTank().getTurret().getX(),player.getTank().getTurret().getY());
  this->playerSprite[BULLET].setPosition(player.getTank().getTurret().getBullet().getX(),player.getTank().getTurret().getBullet().getY());
  this->playerSprite[TANK].setRotation(player.getTank().getPhi());
  this->playerSprite[TURRET].setRotation(player.getTank().getTurret().getPhi());
  this->playerSprite[BULLET].setRotation(player.getTank().getTurret().getBullet().getPhi());
}

void PlayerSurface::draw(sf::RenderWindow& window)
{
  window.draw(this->text);
  window.draw(this->playerSprite[BULLET]);
  window.draw(this->playerSprite[TURRET]);
  window.draw(this->playerSprite[TANK]);
}
