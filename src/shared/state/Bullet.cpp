#include "Bullet.h"
#include "state.h"
#include <math.h>
#include <cmath>
using namespace state;
using namespace std;

float getV() {
    float Vinit = 10;

    return Vinit;
}

float getRAD() {
    float RADinit = M_PI/4;

    return RADinit;
}

float positionBullet (float t)
{
    //vitesse en m.s-1, position en m, angle en radians et temps en secondes
    //opération efectuée dans le plan 2D xy
    //float Vinit, float RADinit,
    //positionFin = CalculPosition (Vinit, RADinit, t, positionInit);
    float g = 9.8;   //m.s-2
    float Vinit;
    float RADinit;

    //state::Element xinit,yinit;
    state::Element elem;


    float Vx,Vy;

    Vinit = getV();

    for(t=0;t<2;t+=0.1)
    {
        Vx = Vinit * cos(RADinit);
        Vy = Vinit * sin(RADinit) - g*t;

        //x = xinit + Vinit * cos(RADinit) * t;
        //y = yinit + Vinit * sin(RADinit) * t - 0.5 * g * pow(t,2);
        //std::cout << "La position finale à " << t << "s soit ("<< Element::positionFin.x << "," << Element::positionFin.y << ")" << endl;
    }

    return dx,dy;
}



