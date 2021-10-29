#include <string>
#include "Player.h"

namespace client {

  void Player::setPlayer(int type,float x,float y)
  {
    std::string typeVector[] = {"tankGreen3","tankNavy3","tankGrey3"};
    this->onePlayerTexture.loadFromFile("../res/"+typeVector[type]+".png");
    this->type = type;
    this->tank.x = x;
    this->tank.y = y;
  }

  void Player::drawPlayer(sf::RenderWindow &s)
  {
    this->onePlayer.setTexture(this->onePlayerTexture);
    this->onePlayer.setOrigin({this->onePlayer.getLocalBounds().width/2,this->onePlayer.getLocalBounds().height});
    this->onePlayer.setPosition(this->tank.x,this->tank.y);
    s.draw(this->onePlayer);
  }

}
