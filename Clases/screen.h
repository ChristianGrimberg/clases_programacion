#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define LED 1
#define LCD 2
#define NOMBRE_MAX 64
#define DIRECCION_MAX 128
#define EMPTY 1
#define FULL 0

#include "utn.h"

typedef struct
{
    int pantallaID;
    int tipo;
    char nombre[NOMBRE_MAX];
    char direccion[DIRECCION_MAX];
    int isEmpty;
}Pantalla;

int screen_inicializarArray(Pantalla* pantallas, int longitud);
int screen_buscarLugarLibre(Pantalla* pantallas, int longitud);
int screen_altaPantalla(Pantalla* pantallas, int indice);

#endif // SCREEN_H_INCLUDED
