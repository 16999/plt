#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <string.h>
#include <iostream>
using namespace std;

sf::RenderWindow window;
sf::Event event;
engine::Engine ngine;
render::Scene scene(window);
state::State currentState;



void playEngine(void)
{
  while (window.isOpen())
  {

      ngine.getCommand().setAction(engine::NOTHING);
      while (window.pollEvent(event))
      {
        switch(event.type)
        {
          case sf::Event::Closed : window.close();  break;
          case sf::Event::KeyPressed :
            ngine.getCommand().setAction(ngine.getCommand().convert(event));
          break;
          default : break;
        }
      }

      ngine.update(currentState,ngine.getCommand().getAction());
      scene.setCurrentState(currentState);
      scene.checkCollision(currentState);
      scene.draw(window);
  }
}




int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumb_AI\n- heuristic_AI\n- advanced_AI" << endl;
  else if (argc == 2 && strcmp(argv[1],"render") == 0)
    playEngine();
  else if (argc == 2 && strcmp(argv[1],"engine") == 0)
    playEngine();
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
