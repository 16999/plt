#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <../shared/ai/DumbAI.h>
#include <string.h>
#include <iostream>
using namespace std;


sf::RenderWindow window;
sf::Event event;
state::State currentState;
render::Scene scene(window);
engine::Engine ngine;
ai::DumbAI dumbAI;




void playRender(void)
{
  while (window.isOpen())
  {
      if (window.pollEvent(event))
        if(event.type == sf::Event::Closed)
          window.close();
      scene.draw(window);
  }
}

void playEngine(void)
{
  while (window.isOpen())
  {

    ngine.getCommand().setAction(engine::NOTHING);
    if (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
      if(event.type == sf::Event::KeyPressed)
        ngine.getCommand().setAction(ngine.getCommand().convert(event));
    }

    ngine.update(currentState,ngine.getCommand().getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}

void playAI(ai::DumbAI selectedAI)
{
  while (window.isOpen())
  {

    ngine.getCommand().setAction(engine::NOTHING);
    if (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
      if(event.type == sf::Event::KeyPressed && currentState.getPlayerID() == currentState.getTurnID())
        ngine.getCommand().setAction(ngine.getCommand().convert(event));
    }

    if(currentState.getPlayerID() != currentState.getTurnID())
      ngine.getCommand().setAction(selectedAI.run(currentState));

    ngine.update(currentState,ngine.getCommand().getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}

void DumbAIvsDumbAI(ai::DumbAI selectedAI)
{
  while (window.isOpen())
  {

    ngine.getCommand().setAction(engine::NOTHING);
    if (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }
    ngine.getCommand().setAction(selectedAI.run(currentState));
    ngine.update(currentState,ngine.getCommand().getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}




int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumbAI\n- heuristicAI\n- advancedAI" << endl;
  else if (argc == 2 && strcmp(argv[1],"render") == 0)
    playRender();
  else if (argc == 2 && strcmp(argv[1],"engine") == 0)
    playEngine();
  else if (argc == 2 && strcmp(argv[1],"dumbAI") == 0)
    playAI(dumbAI);
  else if (argc == 2 && strcmp(argv[1],"dumbAI2") == 0)
    DumbAIvsDumbAI(dumbAI);
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
