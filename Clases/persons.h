#ifndef persons_H_INCLUDED
#define persons_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NOMBRE_LIMITE 25
#define DNI_LIMITE 11
#define REINTENTOS 2

typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
}Persona;

int persons_altaPersona(Persona *persona);
void persons_imprimirPersona(Persona* persona);

#endif // persons_H_INCLUDED
