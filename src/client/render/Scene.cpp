#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 540

Scene::Scene(sf::RenderWindow& window) : window(window)
{
  this->window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"TANKS GAME");
  this->window.setFramerateLimit(60);
  this->mapSurface.initTileset("../res/tileset.png");
  this->playerSurface.resize(2);
  this->playerSurface[0].initText("../res/arial.ttf");
  this->playerSurface[1].initText("../res/arial.ttf");
  this->playerSurface[0].initPlayer({"../res/tank0.png","../res/turret0.png","../res/bullet0.png"});
  this->playerSurface[1].initPlayer({"../res/tank1.png","../res/turret0.png","../res/bullet0.png"});
}

Scene::~Scene ()
{

}

void Scene::draw(sf::RenderWindow& window)
{
  this->window.clear(sf::Color(0,0,64));
  this->mapSurface.loadTileset(this->currentState.getMap().getBloc());
  window.draw(this->mapSurface);
  this->playerSurface[0].loadText(this->currentState.getPlayer()[0]);
  this->playerSurface[1].loadText(this->currentState.getPlayer()[1]);
  this->playerSurface[0].loadPlayer(this->currentState.getPlayer()[0]);
  this->playerSurface[1].loadPlayer(this->currentState.getPlayer()[1]);
  this->playerSurface[0].draw(window);
  this->playerSurface[1].draw(window);
  this->window.display();
}

const state::State& Scene::getCurrentState() const
{
  return this->currentState;
}

void Scene::setCurrentState(const state::State& currentState)
{
  this->currentState = currentState;
}
