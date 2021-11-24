#ifndef STATE__PLAYER__H
#define STATE__PLAYER__H
#include "Player.h"

void Player :: setState(int state){
     this->state = state;

}

void Player::getState(){
      return this->state=state;

}
void Player :: drawPlayer(){

}

void Player::setPlayer (int type, float x, float y){
     this-> type = type;
     this-> x = x;
     this-> y = y;
}