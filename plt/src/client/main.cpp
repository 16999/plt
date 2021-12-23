#include <render/Scene.h>
#include <../shared/engine/KeyboardCommand.h>
#include <../shared/engine/Engine.h>
#include <../shared/ai/DumbAI.h>
#include <../shared/ai/HeuristicAI.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
using namespace this_thread;
using namespace chrono;



render::Scene scene;
engine::Engine ngine;

ai::DumbAI dumbAI(0);
ai::HeuristicAI heuristicAI(1);
engine::KeyboardCommand realPlayer0(0);
engine::KeyboardCommand realPlayer1(1);

thread playerThread[2];
thread displayThread;
sf::Mutex myMutex;


void play(engine::Command* command)
{
  while (1)
  {
    myMutex.lock();
    ngine.update(command);
    myMutex.unlock();
    sleep_for(milliseconds(25));
  }
}

void display()
{
  while (scene.getWindow().isOpen())
  {
    myMutex.lock();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
    myMutex.unlock();
    sleep_for(milliseconds(10));
  }
}



int main(int argc,char* argv[])
{
  if (argc == 1)
    std::cout << "Arguments :\n- render\n- engine\n- dumbAI\n- heuristicAI\n- advancedAI" << endl;
  else if (argc == 2)
  {
    if (strcmp(argv[1],"engine") == 0)
    {
      playerThread[0] = std::thread(&play,&realPlayer0);
      playerThread[1] = std::thread(&play,&realPlayer1);
    }
    else if (strcmp(argv[1],"dumbAI") == 0)
    {
      playerThread[0] = std::thread(&play,&dumbAI);
      playerThread[1] = std::thread(&play,&realPlayer1);
    }
    else if (strcmp(argv[1],"heuristicAI") == 0)
    {
      playerThread[0] = std::thread(&play,&realPlayer0);
      playerThread[1] = std::thread(&play,&heuristicAI);
    }
    else if (strcmp(argv[1],"AIvsAI") == 0)
    {
      playerThread[0] = std::thread(&play,&dumbAI);
      playerThread[1] = std::thread(&play,&heuristicAI);
    }
    displayThread = std::thread(&display);
    displayThread.join();
    playerThread[0].join();
    playerThread[1].join();
  }
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
