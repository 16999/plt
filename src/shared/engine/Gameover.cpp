#include "Gameover.h"
#include <iostream>
using namespace engine;
using namespace std;



void Gameover::handle(state::State& currentState, Action action)
{
  if(action == START_GAME)
  {
      new(this) Moving;
      currentState.startGame();
  }
}
