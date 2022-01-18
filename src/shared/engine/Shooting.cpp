#include "Shooting.h"
#include <iostream>
#include <math.h>
using namespace engine;
using namespace std;
#define RAD_TO_DEG 57.2958


void Moving::handle(state::State& currentState, Action action)
{
  if(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(currentState.getMap()) == state::NOTHING && currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(currentState.getAdversePlayer().getTank()) == false)
  {
    currentState.setDy(currentState.getDy()+currentState.getG());
    currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(RAD_TO_DEG*atan(currentState.getDy()/currentState.getDx())+180*(currentState.getDx()<0));
    currentState.getCurrentPlayer().getTank().getTurret().getBullet().place(currentState.getDx(),currentState.getDy(),0);
  }
  else
  {
    if (currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(currentState.getAdversePlayer().getTank()) == true)
    {
      std::cout << "HIT from player " << currentState.getTurnID() << "!" << endl;
      currentState.getAdversePlayer().setLife(currentState.getAdversePlayer().getLife()-currentState.getCurrentPlayer().getDamage());
    }
    currentState.getCurrentPlayer().getTank().getTurret().replace();    //replace le tir à la même position et au même angle que la tourette lorsqu'une cible est touchée
    if (currentState.getAdversePlayer().getLife() > 0)
    {
      new(this) Moving;
      currentState.nextTurnID();
    }
    else
    {
      new(this) Gameover;
      //record.addGame();
      currentState.endGame();
    }
  }
}
