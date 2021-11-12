#include <render/Scene.h>


sf::RenderWindow window;
state::State thisState;
render::Scene scene(thisState,window);

int main(int argc,char* argv[])
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

      // draw the map
      window.clear(sf::Color(128,160,255));
      scene.draw(window);
      window.display();
  }
  

}
