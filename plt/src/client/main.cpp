#include <render/Scene.h>
#include <../shared/engine/KeyboardCommand.h>
#include <../shared/ai/DumbAI.h>
#include <../shared/ai/HeuristicAI.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;


sf::Event event;
render::Scene scene;
engine::Engine ngine;
ai::DumbAI dumbAI;
ai::HeuristicAI heuristicAI;
engine::KeyboardCommand player;

mutex myMutex;


void play(engine::Command* player1,engine::Command* player2)  //AI vs AI
{
  while (1)
  {
    myMutex.lock();
    if(ngine.getCurrentState().getTurnID() == ngine.getCurrentState().getPlayerID())
      player1->run(ngine);
    else
      player2->run(ngine);
    ngine.update();
    myMutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(10));
  }
}

void display()
{
  while (scene.getWindow().isOpen())
  {
    myMutex.lock();
    if (scene.getWindow().pollEvent(event))
      if(event.type == sf::Event::Closed)
        scene.getWindow().close();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
    myMutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(10));
  }
}



thread playThread;
thread displayThread(&display);

int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumbAI\n- heuristicAI\n- advancedAI" << endl;
  else if (argc == 2)
  {
    if (strcmp(argv[1],"engine") == 0)
      playThread = std::thread(&play,&player,&player);
    else if (strcmp(argv[1],"dumbAI") == 0)
      playThread = std::thread(&play,&player,&dumbAI);
    else if (strcmp(argv[1],"heuristicAI") == 0)
      playThread = std::thread(&play,&player,&heuristicAI);
    else if (strcmp(argv[1],"AIvsAI") == 0)
      playThread = std::thread(&play,&dumbAI,&heuristicAI);
    displayThread.join();
    playThread.join();
  }
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
