#include <render/Scene.h>
#include <string.h>
#include <iostream>
using namespace std;

state::State etat;
sf::RenderWindow window;
render::Scene scene(etat,window);


void loop(void)
{
  while (window.isOpen())
  {
      // handle events
      sf::Event event;
      while (window.pollEvent(event))
      {
          if(event.type == sf::Event::Closed)
              window.close();
      }

      window.clear(sf::Color(0,0,64));
      scene.draw(window);
      window.display();
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
