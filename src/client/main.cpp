#include <render/Scene.h>
#include <../shared/engine/KeyboardCommand.h>
#include <../shared/engine/Engine.h>
#include <../shared/ai/DumbAI.h>
#include <../shared/ai/HeuristicAI.h>
#include <../shared/ai/AdvancedAI.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
using namespace this_thread;
using namespace chrono;
using namespace render;
using namespace engine;
using namespace ai;



Scene scene;
Engine ngine;

DumbAI dumbAI(0);
HeuristicAI heuristicAI(1);
AdvancedAI advancedAI(0);
KeyboardCommand realPlayer0(0);
KeyboardCommand realPlayer1(1);

thread playerThread[2];
thread displayThread;




void display()
{
  while (scene.getWindow().isOpen())
  {
    ngine.mute.lock();
    scene.setCurrentState(ngine.getCurrentState());
    scene.draw();
    ngine.mute.unlock();
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
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&realPlayer0);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&realPlayer1);
    }
    else if (strcmp(argv[1],"dumbAI") == 0)
    {
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&dumbAI);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&realPlayer1);
    }
    else if (strcmp(argv[1],"heuristicAI") == 0)
    {
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&realPlayer0);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&heuristicAI);
    }
    else if (strcmp(argv[1],"advancedAI") == 0)
    {
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&advancedAI);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&realPlayer1);
    }
    else if (strcmp(argv[1],"AIvsAI") == 0)
    {
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&dumbAI);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&heuristicAI);
    }
    else if (strcmp(argv[1],"AIvsAI2") == 0)
    {
      playerThread[0] = std::thread(&Engine::update,ref(ngine),&heuristicAI);
      playerThread[1] = std::thread(&Engine::update,ref(ngine),&advancedAI);
    }
    displayThread = std::thread(&display);
    displayThread.join();
    playerThread[0].join();
    playerThread[1].join();
  }
  else
    std::cout << "ERROR : Invalid arguments !!!" << endl;
}
