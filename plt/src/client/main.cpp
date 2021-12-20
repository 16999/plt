#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <../shared/ai/DumbAI.h>
#include <../shared/ai/HeuristicAI.h>
#include <string.h>
#include <iostream>
using namespace std;


sf::Event event;
render::Scene scene;
engine::Engine ngine;
ai::DumbAI dumbAI;
ai::HeuristicAI heuristicAI;

//engine::Command command;


void playEngine(void)   //player vs player
{
  while (scene.getWindow().isOpen())
  {
    if (scene.getWindow().pollEvent(event))
      if(event.type == sf::Event::Closed)
        scene.getWindow().close();

    ngine.convert(event);
    ngine.update();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
  }
}

void playAI(ai::AI* selectedAI)   //player vs AI
{
  while (scene.getWindow().isOpen())
  {
    if (scene.getWindow().pollEvent(event))
      if(event.type == sf::Event::Closed)
        scene.getWindow().close();

    if(ngine.getCurrentState().getTurnID() == ngine.getCurrentState().getPlayerID())
      ngine.convert(event);
    else
      selectedAI->run(ngine);
    ngine.update();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
  }
}

void AIvsAI(ai::AI* selectedAI1,ai::AI* selectedAI2)  //AI vs AI
{
  while (scene.getWindow().isOpen())
  {
    if (scene.getWindow().pollEvent(event))
      if(event.type == sf::Event::Closed)
        scene.getWindow().close();

    if(ngine.getCurrentState().getTurnID() == ngine.getCurrentState().getPlayerID())
      selectedAI1->run(ngine);
    else
      selectedAI2->run(ngine);
    ngine.update();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
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
