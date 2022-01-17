#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/State.h"
#include "../../src/shared/state/Element.h"
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state/Bullet.h"

#include "../../src/shared/engine/Engine.h"
#include "../../src/shared/engine/KeyboardCommand.h"


using namespace ::state;
using namespace ::engine;
namespace utf = boost::unit_test;
namespace tt = boost::test_tools;

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
    currentState.setTurnID(1);
    BOOST_CHECK_EQUAL(currentState.getTurnID(), 1);
    currentState.setSpeed(8);
    BOOST_CHECK_EQUAL(currentState.getSpeed(), 8);
    currentState.setG(9.8);
    BOOST_TEST(currentState.getG() == 9.8, tt::tolerance(0.01)); 

    currentState.startGame();
  }
}

BOOST_AUTO_TEST_CASE(TestMap)
{
  {
	  Map map {};
	  map.setBloc("0123456789ABCDEF");
	  BOOST_CHECK_EQUAL(map.getBloc(), "0123456789ABCDEF");
  }
}


BOOST_AUTO_TEST_CASE(TestElement)
{
  {
    Element currentElement {};
    currentElement.setX(1);
    BOOST_CHECK_EQUAL(currentElement.getX(),1);
    currentElement.setY(6);
    BOOST_CHECK_EQUAL(currentElement.getY(),6);
    currentElement.setX0(9);
    BOOST_CHECK_EQUAL(currentElement.getX0(),9);
    currentElement.setY0(5);
    BOOST_CHECK_EQUAL(currentElement.getY0(),5);
    currentElement.setWidth(50);
    BOOST_CHECK_EQUAL(currentElement.getWidth(),50);
    currentElement.setHeight(40);
    BOOST_CHECK_EQUAL(currentElement.getHeight(),40);
    currentElement.setPhi(35.5);
    BOOST_CHECK_EQUAL(currentElement.getPhi(),35.5);
  }
}


BOOST_AUTO_TEST_CASE(TestPlayer)
{
  {
    Player currentPlayer {};
    currentPlayer.setLife(33);
    BOOST_CHECK_EQUAL(currentPlayer.getLife(), 33);
    currentPlayer.setTankType(GREEN_TANK);
    BOOST_CHECK_EQUAL(currentPlayer.getTankType(),GREEN_TANK);
    currentPlayer.setStatus(MOVING);
    BOOST_CHECK_EQUAL(currentPlayer.getStatus(),MOVING);
    currentPlayer.setDamage(20);
    BOOST_CHECK_EQUAL(currentPlayer.getDamage(),20);
    currentPlayer.setScore(78);
    BOOST_CHECK_EQUAL(currentPlayer.getScore(),78);

  }
}


BOOST_AUTO_TEST_CASE(TestEngine)
{
  {
    Engine ngine {};
    ngine.setDx(2.5);
    BOOST_CHECK_EQUAL(ngine.getDx(),2.5);
    ngine.setDy(4.25);
    BOOST_CHECK_EQUAL(ngine.getDy(),4.25);
    ngine.setPause(20);
    BOOST_CHECK_EQUAL(ngine.getPause(),20);
    ngine.setAction(FIRE);
    BOOST_CHECK_EQUAL(ngine.getAction(),FIRE);
  }
}


BOOST_AUTO_TEST_CASE(TestCommand)
{
  {
    Command* cmd = new KeyboardCommand(0);
    cmd->setCommandID(1);
	BOOST_CHECK_EQUAL(cmd->getCommandID(),1);
  }
}


BOOST_AUTO_TEST_CASE(TestRecord)
{
  {
    Record record {};
    record.setTurnNumber(11);
    BOOST_CHECK_EQUAL(record.getTurnNumber(),11);
    record.setActionNumber(23);
    BOOST_CHECK_EQUAL(record.getActionNumber(),23);
    record.setGameNumber(8);
    BOOST_CHECK_EQUAL(record.getGameNumber(),8);
  }
}

