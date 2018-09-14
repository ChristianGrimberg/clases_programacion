#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "utn.h"

int person_altaPersona(Persona* persona)
{
    int retorno = -1;
    char nombreAux[NOMBRE_LIMITE];
    int edadAux;
    char dniAux[DNI_LIMITE];
    float alturaAux;

    if(persona != NULL)
    {
        if(utn_getNombre(nombreAux, NOMBRE_LIMITE, REINTENTOS, "Ingrese el nombre: ", "Error de ingreso. ") == 0
            && utn_getInt(&edadAux, REINTENTOS, 0, 200, "Ingrese la edad: ", "Error de ingreso. ") == 0
            && utn_getNombre(dniAux, DNI_LIMITE, REINTENTOS, "Ingrese el DNI: ", "Error de ingreso. ") == 0
            && utn_getFloat(&alturaAux, REINTENTOS, 0, 500, "Ingrese su peso: ", "Error de ingreso. ") == 0)
        {
            strncpy(persona->nombre, nombreAux, NOMBRE_LIMITE);
            persona->edad = edadAux;
            strncpy(persona->dni, dniAux, DNI_LIMITE);
            persona->altura = alturaAux;
            retorno = 0;
        }
    }
    return retorno;
}

void person_imprimirPersona(Persona* persona)
{
    printf("Nombre: %s\nEdad: %d\nDNI: %s\nAltura: %.2f", persona->nombre, persona->edad, persona->dni, persona->altura);
}