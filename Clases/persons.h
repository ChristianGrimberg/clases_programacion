#ifndef persons_H_INCLUDED
#define persons_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NAME_LIMITS 50
#define DNI_LIMITS 11
#define PHONE_LIMITS 50 /**< Valor maximo de cantidad de caracteres para un telefono. */
#define REINTENTOS 2


typedef struct
{
    char nombre[NAME_LIMITS];
    int edad;
    char dni[DNI_LIMITS];
    float altura;
    char telefono[PHONE_LIMITS];
}Persona;

int persons_altaPersona(Persona* persona, int reintentos);
void persons_imprimirPersona(Persona* pPersona, int limite);

#endif // persons_H_INCLUDED
