#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <string.h>
#include <iostream>
using namespace std;

engine::Engine ngine;
sf::RenderWindow window;
render::Scene scene(window);
state::State currentState;
sf::Event event;
bool val;


void display(void)
{
  while (window.isOpen())
  {

      ngine.setAction(engine::NOTHING);
      while (window.pollEvent(event))
      {
        switch(event.type)
        {
          case sf::Event::Closed : window.close();  break;
          case sf::Event::KeyPressed :
            ngine.setAction(ngine.convert(event));
          break;
          default : break;
        }
      }

      ngine.update(currentState,ngine.getAction());
      scene.setCurrentState(currentState);
      scene.draw(window);
  }
}




int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumb_AI\n- heuristic_AI\n- advanced_AI" << endl;
  else if (argc == 2 && strcmp(argv[1],"render") == 0)
    display();
  else if (argc == 2 && strcmp(argv[1],"engine") == 0)
    display();
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
