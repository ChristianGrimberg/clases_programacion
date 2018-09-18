#ifndef persons_H_INCLUDED
#define persons_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NOMBRE_LIMITE 50
#define DNI_LIMITE 11
#define REINTENTOS 2
#define PHONE_CHARACTERS 50 /**< Valor maximo de cantidad de caracteres para un telefono. */

typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
    char telefono[50];
}Persona;

int persons_altaPersona(Persona* persona, int reintentos);
void persons_imprimirPersona(Persona* persona);

#endif // persons_H_INCLUDED
