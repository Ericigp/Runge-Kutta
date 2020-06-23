#ifndef RUNGE_KUTA_H_INCLUDED
#define RUNGE_KUTA_H_INCLUDED

#include <fstream>
#include <cmath>

using namespace std;

static const double G = 6.67e-11;//Constante de gravitacion
static const double Mt = 5.9736e24;//Masa de la tierra
static const double Ml = 0.07349e24;//Masa de la luna
static const double dtl = 3.844e8;//Distancia tierra luna
static const double w = 2.6617e-6;//Velocidad angular de la tierra
static const double Rt = 6.378160e6;//Radio de la tierra
static const double Rl = 1.7374e6;//Radio de la luna
static const double delta = G*Mt/(dtl*dtl*dtl);
static const double mu = Ml/Mt;

void actualizak (double f[],double h, double t ,double Y[], double k1[],double k2[],double k3[],double k4[]);
void actualizay (double Y[],double k1[],double k2[],double k3[],double k4[]);
void actualizaf (double f[],double r,double phi, double pr,double pphi,double t);
double rprima (double r,double phi,double t);
double rpunto (double t,double pr);
double phipunto (double t,double pphi, double r);
double prprima (double t, double r, double pphi,double phi,double rp );
double pphiprima (double t, double r,double phi, double rp);
double polaresx (double r, double ang);
double polaresy (double r, double ang);


#endif // RUNGE_KUTA_H_INCLUDED
