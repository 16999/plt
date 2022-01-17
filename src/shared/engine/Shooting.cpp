#include "Shooting.h"
#include <iostream>
using namespace engine;
using namespace std;



void Moving::handle(state::State currentState&, Action action)
{
  if(currentState.getCurrentPlayer().getTank().getTurret().getBullet().getBlocType(currentState.getMap()) == state::NOTHING && currentState.getCurrentPlayer().getTank().getTurret().getBullet().intersects(currentState.getAdversePlayer().getTank()) == false)
  {
    currentState.setDy(currentState.getDy()+currentState.getG());
    currentState.getCurrentPlayer().getTank().getTurret().getBullet().setPhi(RAD_TO_DEG*atan(dy/dx)+180*(dx<0));
    currentState.getCurrentPlayer().getTank().getTurret().getBullet().place(dx,dy,0);
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
      this = new Moving;
      currentState.nextTurnID();
    }
    else
    {
      this = new Gameover;
      //record.addGame();
      currentState.endGame();
    }
  }
}
