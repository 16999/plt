#include "Engine.h"
using namespace engine;


Engine::Engine()
{

}

Engine::~Engine()
{

}

const state::State& Engine::getCurrentState() const
{
  return this->currentState;
}
