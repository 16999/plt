#include "Moving.h"
#include <iostream>
#include <math.h>
using namespace engine;
using namespace std;
#define RAD_TO_DEG 57.2958



void Moving::handle(state::State& currentState, Action action)
{
  //record.addAction(action);
  if (action == MOVE_LEFT && currentState.getCurrentPlayer().getTank().getBlocType(currentState.getMap()) != state::LEFT_BORDER)
    currentState.getCurrentPlayer().getTank().place(-currentState.getSpeed()/2,0,0);
  else if (action == MOVE_RIGHT && currentState.getCurrentPlayer().getTank().getBlocType(currentState.getMap()) != state::RIGHT_BORDER)
    currentState.getCurrentPlayer().getTank().place(currentState.getSpeed()/2,0,0);
  else if (action == TURN_ANTICLOCKWISE && currentState.getCurrentPlayer().getTank().getTurret().getPhi() > -180)
    currentState.getCurrentPlayer().getTank().getTurret().place(0,0,-currentState.getSpeed()/2);
  else if (action == TURN_CLOCKWISE && currentState.getCurrentPlayer().getTank().getTurret().getPhi() < 0)
    currentState.getCurrentPlayer().getTank().getTurret().place(0,0,currentState.getSpeed()/2);
  else if (action == FIRE)
  {
    //record.addTurn();
    currentState.setDx(currentState.getSpeed()*cos(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi()/RAD_TO_DEG));
    currentState.setDy(currentState.getSpeed()*sin(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getPhi()/RAD_TO_DEG));
    new(this) Shooting;
  }
}
