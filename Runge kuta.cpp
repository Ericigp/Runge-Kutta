/***********************************************************************/
/** Archivo que contiene todas las funciones necesarias para          **/
/** la implementación del algoritmo de Runge kuta para el problema del**/
/** lanzamiento del cohete a la luna                                  **/
/***********************************************************************/

#include "Runge kuta.h"

using namespace std;

void actualizak (double f[],double h, double t ,double Y[], double k1[],double k2[],double k3[],double k4[])
{
    int i;

    actualizaf(f,Y[0],Y[1],Y[2],Y[3],t);
    for (i=0;i<4;i++)
    {
        k1[i]=h*f[i];
    }

    actualizaf(f,Y[0]+k1[0]*1.0/2.0,Y[1]+k1[1]*1.0/2.0,Y[2]+k1[2]*1.0/2,Y[3]+k1[3]*1.0/2,t+h/2);
    for (i=0;i<4;i++)
    {
        k2[i]=h*f[i];
    }

    actualizaf(f,Y[0]+k2[0]*1.0/2.0,Y[1]+k2[1]*1.0/2.0,Y[2]+k2[2]*1.0/2.0,Y[3]+k2[3]*1.0/2.0,t+h/2);
    for (i=0;i<4;i++)
    {
        k3[i]=h*f[i];
    }

    actualizaf(f,Y[0]+k3[0],Y[1]+k3[1],Y[2]+k3[2],Y[3]+k3[3],t+h);
    for (i=0;i<4;i++)
    {
        k4[i]=h*f[i];
    }

    return;
}

void actualizaf (double f[],double r,double phi, double pr,double pphi,double t)
{
    double rp;
    rp=rprima(r,phi,t);

    f[0]=rpunto(t,pr);
    f[1]=phipunto(t,pphi,r);
    f[2]=prprima(t,r,pphi,phi,rp);
    f[3]=pphiprima(t,r,phi,rp);
}

void actualizay (double Y[],double k1[],double k2[],double k3[],double k4[])
{
    int i;

    for(i=0;i<4;i++)
        Y[i]=Y[i]+(1.0/6.0)*(k1[i]+2.0*k2[i]+2.0*k3[i]+k4[i]);
}

double rprima (double r,double phi,double t)
{
    return sqrt(1.0+r*r-2.0*r*cos(phi-w*t));
}

double rpunto (double t,double pr)
{
    return pr;
}

double phipunto (double t,double pphi, double r)
{
    return pphi/(r*r);
}

double prprima (double t, double r, double pphi,double phi,double rp )
{
   return (pphi*pphi/(r*r*r))-delta*(1.0/(r*r)+(mu/(rp*rp*rp))*(r-cos(phi-w*t)));
}

double pphiprima (double t, double r,double phi, double rp)
{
    return -1.0*(delta*mu*r)/(rp*rp*rp)*sin(phi-w*t);
}

double polaresx (double r, double ang)
{
    return r*cos(ang);
}

double polaresy (double r, double ang)
{
    return r*sin(ang);
}

