#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <string.h>
#include <iostream>
using namespace std;

engine::Engine ngine;
sf::RenderWindow window;
render::Scene scene(ngine.getCurrentState(),window);

void loop(void)
{
  while (window.isOpen())
  {
      sf::Event event;  // handle events
      while (window.pollEvent(event))
        if(event.type == sf::Event::Closed)
          window.close();

      ngine.getCurrentState();
      scene.draw(window);
  }
}

int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumb_AI\n- heuristic_AI\n- advanced_AI" << endl;
  else if (argc == 2 && strcmp(argv[1],"render") == 0)
    loop();
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
