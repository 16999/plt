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
    //currentState.setCollision(true);
	//BOOST_CHECK_EQUAL(currentState.getCollision(),true);
    currentState.startGame();
  }
}
BOOST_AUTO_TEST_CASE(TestElement)
{
  {
    /*Element currentElement {};
    currentElement.setX(1);
    BOOST_CHECK_EQUAL(currentElement.getX(), 1);
    currentElement.setY(1);
    BOOST_CHECK_EQUAL(currentElement.getY(),true);
    currentElement.setPhi(35.5);
    BOOST_CHECK_EQUAL(currentElement.getPhi(),35.5);
    currentElement.move(2.2,3.3);
    currentElement.turn(35.5);*/
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
    currentPlayer.setDamage(20);
    BOOST_CHECK_EQUAL(currentPlayer.getDamage(),20);

  }
}

BOOST_AUTO_TEST_CASE(TestBullet)
{
  {
    Engine ngine {};

    ngine.setInc(3);
    BOOST_CHECK_EQUAL(ngine.getInc(), 3);
    ngine.setV0(5);
    BOOST_CHECK_EQUAL(ngine.getV0(), 5);
    ngine.setVx(2.5);
    BOOST_CHECK_EQUAL(ngine.getVx(),2.5);
    ngine.setVy(3.25);
    BOOST_CHECK_EQUAL(ngine.getVy(), 3.25);
    ngine.setG(9.75);
    BOOST_CHECK_EQUAL(ngine.getG(), 9.75);
    ngine.setT(15);
    BOOST_CHECK_EQUAL(ngine.getT(), 15);
    ngine.setTheta(68.25);
    BOOST_CHECK_EQUAL(ngine.getTheta(), 68.25);
  }
}
