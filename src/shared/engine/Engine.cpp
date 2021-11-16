#include "Engine.h"
using namespace engine;

Engine::Engine()
{

}

Engine::~Engine()
{

}

state::State& Engine::getCurrentState()
{
  return this->currentState;
}
