#include <render/Scene.h>
#include <../shared/engine/Engine.h>
#include <../shared/engine/KeyboardCommand.h>
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
engine::KeyboardCommand player;

void play(engine::Command* player1,engine::Command* player2)  //AI vs AI
{
  while (scene.getWindow().isOpen())
  {
    if (scene.getWindow().pollEvent(event))
      if(event.type == sf::Event::Closed)
        scene.getWindow().close();

    if(ngine.getCurrentState().getTurnID() == ngine.getCurrentState().getPlayerID())
      player1->run(ngine);
    else
      player2->run(ngine);
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
    play(&player,&player);
  else if (argc == 2 && strcmp(argv[1],"dumbAI") == 0)
    play(&player,&dumbAI);
  else if (argc == 2 && strcmp(argv[1],"heuristicAI") == 0)
    play(&player,&heuristicAI);
  else if (argc == 2 && strcmp(argv[1],"AIvsAI") == 0)
    play(&dumbAI,&heuristicAI);
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
