#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;


Scene::Scene(state::State& state, sf::RenderWindow& window) : window(window), etat(state)
{
  this->window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"TANKS GAME");
  this->surface.initTileset("../res/tileset.png");
  this->surface.initFont("../res/arial.ttf");
  this->surface.initTank(0,"../res/tank0.png");
  this->surface.initTank(1,"../res/tank2.png");
}

Scene::~Scene ()
{

}

void Scene::draw(sf::RenderWindow& window)
{
  this->surface.loadMap(this->etat.getMap().getVector());
  this->surface.loadText(this->etat.getPlayer()[0].getTextData(),0,sf::Color(64,64,64));
  this->surface.loadText(this->etat.getPlayer()[1].getTextData(),1,sf::Color(64,0,0));
  this->surface.loadTank(0,this->etat.getPlayer()[0].getTank().getX(),this->etat.getPlayer()[0].getTank().getY());
  this->surface.loadTank(1,this->etat.getPlayer()[1].getTank().getX(),this->etat.getPlayer()[1].getTank().getY());

  window.draw(this->surface);
}
