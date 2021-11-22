#include "Bullet.h"
#include <math.h>
#include <cmath>
using namespace state;
using namespace std;


float Bullet::positionInit(){
    return x,y;
}

float Bullet::positionFin(){
    return x,y;
}


void Bullet::positionBullet() {
    float Vinit = 10;
    float RADinit = M_PI/4;
    float t;
    for(t=0;t<2;t+=0.1)
    {
    positionFin = CalculPosition (Vinit, RADinit, t, positionInit);
    std::cout << "La position finale à " << t << "s soit ("<< positionFin.x << "," << positionFin.y << ")" << endl;
    }
    return 0;
}

Bullet::positionFin CalculPosition (float Vinit, float RADinit, float t, Element::positionInit)
{
    //vitesse en m.s-1, position en m, angle en radians et temps en secondes
    //opération efectuée dans le plan 2D xy


float g = 9.8;   //m.s-2
    Position positionFin;

    positionFin.x = Vinit * cos(RADinit) * t + positionInit.x;
    positionFin.y = Vinit * sin(RADinit) * t - 0.5 * g * pow(t,2);
    return positionFin;
}