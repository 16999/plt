#include "Bullet.h"
#include <math.h>
#include <cmath>
using namespace state;
using namespace std;
/*
BUllet::Bullet(){

}

Bullet::~Bullet(){

}
 */

sf::float positionBullet (float t)
{
    //vitesse en m.s-1, position en m, angle en radians et temps en secondes
    //opération efectuée dans le plan 2D xy
    //float Vinit, float RADinit,
    //positionFin = CalculPosition (Vinit, RADinit, t, positionInit);
    float g = 9.8;   //m.s-2
    float x,y;
    x = Element::getX() const;

    for(t=0;t<2;t+=0.1)
    {
        Element::positionFin.x = Vinit * cos(RADinit) * t + positionInit.x;
        Element::positionFin.y = Vinit * sin(RADinit) * t - 0.5 * g * pow(t,2);
        std::cout << "La position finale à " << t << "s soit ("<< positionFin.x << "," << positionFin.y << ")" << endl;
    }


    return positionFin;
}

/*
 * float float Bullet::getPositionInit(){
    return x,y;
}
*/
float Bullet::getVandRAD() {
    float Vinit = 10;
    float RADinit = M_PI/4;
    float t;

    return Vinit, RADinit;
}

