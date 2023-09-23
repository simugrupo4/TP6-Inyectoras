#include <time.h>
#include <stdlib.h>
#include "init.h"

//genera random entre 0.0 y 1.0
double generarRandom(){
    
    //setear semilla en TIEMPO ACTUAL para rand()
    srand(time(NULL));

    return (double)rand() / RAND_MAX;
}

//intervalo entre arribos
double ia(){
    //cargar FDP
    return generarRandom();
}

//REPARACION FALLO DE MAQUINA
double drbd(){
    //cargar FDP
    return generarRandom();
}

//REPARACION FUERZA MAYOR
double drfm(){
    //cargar FDP
    return generarRandom();
}

//
double drpm(){
    //cargar FDP
    return generarRandom();
}

//devuelve 1 si alguna maquina funciona
int algunaMaquinaEnfuncionamiento(){
    int i = 0;
    while (i < cm){
        if (tr[i] <= t){
            return 1;
        }
        else{
            i++;
        }
    }
    return 0;
}

int asignarMaquina(){
    while(1){
        double random = generarRandom();
        for(int i = 0; i < 15 ; i++)
        {
            //maquina i
            if(random <= trPor[i])
            {
                if(tr[i] <= t)
                {
                    return i;
                }else{
                    i=15;
                }
            }
        }
    }
}

int empleadoDisponible(){
    int menor = tc[0];
    int persona = 0;
    for(int j = 1; j < pmd; j++){
        if(tc[j] < menor){
            menor = tc[j];
            persona = j;
        }
    }
    return persona;
}

int duracionAverio(){
    double random = generarRandom(1,100);
    if (random <= 0.83){
        return drbd();
    } else {
        if(random <= 0.96){
            return drpm();
        }
        else {
            return drfm();
        }
    }
}
