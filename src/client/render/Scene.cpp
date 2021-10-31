#include <iostream>
#include "Scene.h"
using namespace std;
using namespace render;
using namespace state;


Scene::Scene()
{

}

void Scene::init(void)
{
  std::cout << "---- Welcome to TANKS GAME ! ----" << endl;
  window.create(sf::VideoMode(960, 540), "Tanks game");
}

void Scene::refresh(void)
{
  window.clear(sf::Color::Blue);
  window.display();
}
