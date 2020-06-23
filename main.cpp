#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Runge kuta.h"

#define N 4 //Dimensiones del vector
#define h 500

//Para que funcione se han dado las condiciones iniciales: phi=0, theta=0.128, v=1.1*Vescape

using namespace std;

int main()
{
    int i=0,j;//Contador de pasos
    int pasos;//Numero de pasos
    double Y[N];//Vector que contiene los 4 valores de las ecuaciones diferenciales ordenados como: r,phi,pr y pphy
    double f[4];//Venctor que contiene los resultados de las funciones
    double k1[N],k2[N],k3[N],k4[N];//Vectores para las ks
    double v,theta;//Este valor nos facilitara el calculo de las condiciones iniciales
    double t=0.0;

    ofstream fich, fich2;

    fich.open("y.txt");
    fich2.open("Tierra-luna.txt");


    //Introduzco y calculo las condiciones iniciales de las ecuaciones diferenciales
    Y[0]=Rt/dtl;//El unico valor que conocemos
    cout<<"Introduzca el valor inicial del angulo Phi"<<endl;
    cin>>Y[1];

    cout<<"Introduzca el valor inicial del angulo theta"<<endl;
    cin>>theta;

    cout<<"Introduzca una velocidad inicial. Idealmente que sea mayor que la velocidad de escape: " << sqrt(2*G*Mt/Rt)<<endl;
    cin>>v;

    cout<<"Introduzca el numero de pasos para el algoritmo"<<endl;
    cin>>pasos;

    Y[2]=(v/dtl)*cos(theta-Y[1]);//Calculo de los momentos conjugados
    Y[3]=Y[0]*(v/dtl)*sin(theta-Y[1]);


    //Implemento el algoritmo
    while (i<pasos)
    {
        actualizak(f,h,t,Y,k1,k2,k3,k4);
        actualizay(Y,k1,k2,k3,k4);

        for(j=0;j<4;j++)
        {
            fich<<Y[j]<<"\t";
        }
        fich<<endl;

        if (i%10==0)
        {
            fich2<<polaresx(Y[0],Y[1])<<" "<<polaresy(Y[0],Y[1])<<" ";
            fich2<<cos(w*t)<<" "<<sin(w*t)<<endl;
        }

        t=t+h;

        i++;
    }

    fich.close();
    fich2.close();

    return 0;
}
