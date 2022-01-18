#include "Engine.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace engine;
using namespace state;
using namespace std;
using namespace this_thread;
using namespace chrono;



Engine::Engine()
{
  this->pause = 25;
  std::cout << "Engine launched" << endl;
  this->status = new Gameover;
}

Engine::~Engine()
{
}

void Engine::setAction(Action action)
{
  this->action = action;
}

Action Engine::getAction() const
{
  return this->action;
}

void Engine::setPause(int pause)
{
  this->pause = pause;
}

int Engine::getPause() const
{
  return this->pause;
}

state::State Engine::getCurrentState()
{
  return this->currentState;
}

/*const Status*& Engine::getStatus() const
{
  return this->status;
}

void Engine::setStatus(const Status*& status)
{
  this->status = status;
}*/

void Engine::update(Command* command)
{
  while (1)
  {

    this->mute.lock();
    if(this->currentState.getTurnID() == command->getCommandID())
      this->action = command->run(this->currentState, *this->status);
    else
      this->action = NO_ACTION;

    this->status->handle(this->currentState, this->action);
    this->mute.unlock();
    sleep_for(milliseconds(this->pause));
  }

}
