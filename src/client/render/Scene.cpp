#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;


Scene::Scene(state::State& state, sf::RenderWindow& window) : window(window), etat(state)
{
  std::cout << "Welcome to " << this->title << endl;
  this->window.create(sf::VideoMode(this->width,this->height), this->title);
}


void Scene::draw(sf::RenderWindow& window)
{
  this->surface.loadMap("../res/tileset.png", sf::Vector2u(36, 36), this->etat.getMap(), 20, 15);
  window.draw(this->surface);
}
