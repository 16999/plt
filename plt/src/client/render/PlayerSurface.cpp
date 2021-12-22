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

void PlayerSurface::initText(std::string path)
{
  this->font.loadFromFile(path);
  this->text.setFont(this->font);
}

void PlayerSurface::initPlayer(state::Player player,std::vector<std::string> path)
{
  this->playerTexture[TANK].loadFromFile(path[TANK]);
  this->playerTexture[TURRET].loadFromFile(path[TURRET]);
  this->playerTexture[BULLET].loadFromFile(path[BULLET]);
  this->playerSprite[TANK].setOrigin(player.getTank().getX0(),player.getTank().getY0());
  this->playerSprite[TURRET].setOrigin(player.getTank().getTurret().getX0(),player.getTank().getTurret().getY0());
  this->playerSprite[BULLET].setOrigin(player.getTank().getTurret().getBullet().getX0(),player.getTank().getTurret().getBullet().getY0());
  player.getTank().setWidth(this->playerTexture[TANK].getSize().x);
  player.getTank().setHeight(this->playerTexture[TANK].getSize().y);
  player.getTank().getTurret().setWidth(this->playerTexture[TURRET].getSize().x);
  player.getTank().getTurret().setHeight(this->playerTexture[TURRET].getSize().y);
  player.getTank().getTurret().getBullet().setWidth(this->playerTexture[BULLET].getSize().x);
  player.getTank().getTurret().getBullet().setHeight(this->playerTexture[BULLET].getSize().y);
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
