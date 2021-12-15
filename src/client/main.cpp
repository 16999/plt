#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <../shared/ai/DumbAI.h>
#include <../shared/ai/HeuristicAI.h>
#include <string.h>
#include <iostream>
using namespace std;


sf::RenderWindow window;
sf::Event event;
state::State currentState;
render::Scene scene(window);
engine::Engine ngine;
ai::DumbAI dumbAI;
ai::HeuristicAI heuristicAI;



void playEngine(void)   //player vs player
{
  while (window.isOpen())
  {

    ngine.setAction(engine::NOTHING);
    if (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
      if(event.type == sf::Event::KeyPressed)
        ngine.setAction(ngine.convert(event));
    }

    ngine.update(currentState,ngine.getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}

void playAI(ai::AI* selectedAI)   //player vs AI
{
  while (window.isOpen())
  {

    ngine.setAction(engine::NOTHING);
    if (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
      if(event.type == sf::Event::KeyPressed && currentState.getTurnID() == currentState.getPlayerID())
        ngine.setAction(ngine.convert(event));
    }

    if(currentState.getTurnID() != currentState.getPlayerID() && ngine.getStatus() != engine::SHOOTING)
      ngine.setAction(selectedAI->run(currentState));

    ngine.update(currentState,ngine.getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}

void AIvsAI(ai::AI* selectedAI1,ai::AI* selectedAI2)  //AI vs AI
{
  while (window.isOpen())
  {

    if (window.pollEvent(event))
      if(event.type == sf::Event::Closed)
        window.close();
    if(currentState.getTurnID() == 0 && ngine.getStatus() == engine::MOVING)
      ngine.setAction(selectedAI1->run(currentState));
    else if(currentState.getTurnID() == 1 && ngine.getStatus() == engine::MOVING)
      ngine.setAction(selectedAI2->run(currentState));
    else if (ngine.getStatus() == engine::GAMEOVER)
      ngine.setAction(engine::FIRE);
    else
      ngine.setAction(engine::NOTHING);

    ngine.update(currentState,ngine.getAction());
    scene.setCurrentState(currentState);
    scene.checkCollision(currentState);
    scene.draw(window);
  }
}




int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumbAI\n- heuristicAI\n- advancedAI" << endl;
  else if (argc == 2 && strcmp(argv[1],"engine") == 0)
    playEngine();
  else if (argc == 2 && strcmp(argv[1],"dumbAI") == 0)
    playAI(&dumbAI);
  else if (argc == 2 && strcmp(argv[1],"heuristicAI") == 0)
    playAI(&heuristicAI);
  else if (argc == 2 && strcmp(argv[1],"AIvsAI") == 0)
    AIvsAI(&dumbAI,&heuristicAI);
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
