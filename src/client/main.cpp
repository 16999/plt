#include <render/Scene.h>
#include <../shared/engine/Engine.h>

engine::Engine ngine;
sf::RenderWindow window;
render::Scene scene(ngine.getCurrentState(),window);
//state::State thisState;
//render::Scene scene(thisState,window);


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
