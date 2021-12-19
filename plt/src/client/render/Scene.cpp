#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 540

Scene::Scene()
{
  std::cout << "Render launched" << endl;
  this->window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"TANKS GAME");
  this->window.setFramerateLimit(60);
  this->mapSurface.initTileset("../res/tileset.png");
  this->playerSurface.resize(2);
  for(int i=0;i<2;i++)
  {
    this->playerSurface[i].initText("../res/arial.ttf");
    this->playerSurface[i].initPlayer(this->currentState.getPlayer()[i],{"../res/tank"+to_string(this->currentState.getPlayer()[i].getTankType())+".png","../res/turret0.png","../res/bullet0.png"});
  }
}

Scene::~Scene()
{

}

void Scene::draw()
{
  this->window.clear(sf::Color(0,0,64));
  this->mapSurface.loadTileset(this->currentState.getMap().getBloc());
  this->window.draw(this->mapSurface);
  for(int i=0;i<2;i++)
  {
    this->playerSurface[i].loadText(this->currentState.getPlayer()[i]);
    this->playerSurface[i].loadPlayer(this->currentState.getPlayer()[i]);
    this->playerSurface[i].draw(this->window);
  }
  this->window.display();
}

sf::RenderWindow& Scene::getWindow()
{
  return this->window;
}

const state::State& Scene::getCurrentState() const
{
  return this->currentState;
}

void Scene::setCurrentState(const state::State& currentState)
{
  this->currentState = currentState;
}
