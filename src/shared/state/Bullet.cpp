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

    float xinit = elem.getX();
    float yinit = elem.getY();
    float dx,dy;

    Vinit = getV();
    RADinit = getRAD();

    for(t=0;t<2;t+=0.1)
    {
        dx = Vinit * cos(RADinit) * t;
        dy = Vinit * sin(RADinit) * t - 0.5 * g * pow(t,2);

        //x = xinit + Vinit * cos(RADinit) * t;
        //y = yinit + Vinit * sin(RADinit) * t - 0.5 * g * pow(t,2);
        //std::cout << "La position finale à " << t << "s soit ("<< Element::positionFin.x << "," << Element::positionFin.y << ")" << endl;
    }

    return dx,dy;
}



