#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/State.h"
#include "../../src/shared/engine/Engine.h"
#include "../../src/shared/state/Element.h"
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state/Bullet.h"


using namespace ::state;
using namespace ::engine;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestState)
{
  {
    State currentState {};
    currentState.setPlayerID(1);
    BOOST_CHECK_EQUAL(currentState.getPlayerID(), 1);
    currentState.startGame();
  }
}
BOOST_AUTO_TEST_CASE(TestElement)
{
  {
    Element currentElement {};
    currentElement.setX(1);
    BOOST_CHECK_EQUAL(currentElement.getX(), 1);
    currentElement.setY(6);
    BOOST_CHECK_EQUAL(currentElement.getY(),6);
    currentElement.setPhi(35.5);
    BOOST_CHECK_EQUAL(currentElement.getPhi(),35.5);
  }
}


BOOST_AUTO_TEST_CASE(TestPlayer)
{
  {
    Player currentPlayer {};
    currentPlayer.setLife(1);
    BOOST_CHECK_EQUAL(currentPlayer.getLife(), 1);
    currentPlayer.setTankType(GREEN_TANK);
    BOOST_CHECK_EQUAL(currentPlayer.getTankType(),GREEN_TANK);
    currentPlayer.setStatus(MOVING);
    BOOST_CHECK_EQUAL(currentPlayer.getStatus(),MOVING);
    currentPlayer.setDamage(20);
    BOOST_CHECK_EQUAL(currentPlayer.getDamage(),20);

  }
}

/*
BOOST_AUTO_TEST_CASE(TestEngine)
{
  {
    Engine ngine {};
    ngine.setDx(2.5);
    BOOST_CHECK_EQUAL(ngine.getDx(),2.5);
    ngine.setDy(4.0);
    BOOST_CHECK_EQUAL(ngine.getDy(),4.0);
    ngine.setAction(FIRE);
    BOOST_CHECK_EQUAL(ngine.getAction(),FIRE);
  }
}*/
