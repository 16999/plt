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
  this->playerTexture[0].loadFromFile(path[0]);
  this->playerTexture[1].loadFromFile(path[1]);
  this->playerTexture[2].loadFromFile(path[2]);
  this->playerSprite[0].setOrigin((float)(this->playerTexture[0].getSize().x)/2,(float)(this->playerTexture[0].getSize().y));
  this->playerSprite[1].setOrigin(0,(float)(this->playerTexture[1].getSize().y)/2);
  this->playerSprite[2].setOrigin((float)(this->playerTexture[2].getSize().x)/2,(float)(this->playerTexture[2].getSize().y)/2);
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
  this->playerSprite[0].setTexture(this->playerTexture[0]);
  this->playerSprite[1].setTexture(this->playerTexture[1]);
  this->playerSprite[2].setTexture(this->playerTexture[2]);
  this->playerSprite[0].setPosition(player.getTank().getX(),player.getTank().getY());
  this->playerSprite[1].setPosition(player.getTurret().getX(),player.getTurret().getY());
  this->playerSprite[2].setPosition(player.getBullet().getX(),player.getBullet().getY());
  this->playerSprite[0].setRotation(player.getTank().getAngle());
  this->playerSprite[1].setRotation(player.getTurret().getAngle());
  this->playerSprite[2].setRotation(player.getBullet().getAngle());
}

void PlayerSurface::draw(sf::RenderWindow& window)
{
  window.draw(this->text);
  window.draw(this->playerSprite[2]);
  window.draw(this->playerSprite[1]);
  window.draw(this->playerSprite[0]);
}
