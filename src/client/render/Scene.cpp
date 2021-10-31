#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;


Scene::Scene(int width, int height, std::string title)
{
  this->width = width;
  this->height = height;
  this->title = title;
}

void Scene::init()
{
  std::cout << "-- Welcome to TANKS GAME ! --" << endl;
  window.create(sf::VideoMode(this->width,this->height), this->title);
}

void Scene::refresh(void)
{
  window.clear(sf::Color::Blue);
  window.display();
}
