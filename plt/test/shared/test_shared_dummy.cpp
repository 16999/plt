#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/State.h"
#include "../../src/shared/engine/Engine.h"

using namespace ::state;
using namespace ::engine;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestExemple)
{
  {
    State currentState {};
    currentState.setPlayerID(1);
    BOOST_CHECK_EQUAL(currentState.getPlayerID(), 1);
  }

  {
    /*Exemple ex {};
    ex.setX(21);
    BOOST_CHECK_LE(ex.x, 32); // Less than equal
    BOOST_CHECK_GT(ex.x, 11);*/ // Greater than equl
  }
}

/* vim: set sw=2 sts=2 et : */
