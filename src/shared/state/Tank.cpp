#include "Tank.h"
#include "Element.h"
using namespace state;

int Tank::changeStatusTank (int statusTank){
     this->statusTank = statusTank;
}

void state::Tank::statusAttack (){
    this->statusAttack=statusAttack;

}

void Tank::statusDefend(){
    this->statusDefend=statusDefend;

}
int Tank::getPosition() const{
    return this->position

}

void setPosition(int position){
    this->postion=position;
}