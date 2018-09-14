#include <stdio_ext.h>
#include <stdlib.h>
#include "person.h"
#include "utn.h"

int person_altaPersona(Persona* persona)
{
    int retorno = -1;

    if(persona != NULL)
    {
        if(utn_getNombre(persona->nombre, 25, 0, "Ingrese el nombre: ", "Error de ingreso. ") == 0
            && utn_getInt(&persona->edad, 0, 0, 200, "Ingrese la edad: ", "Error de ingreso. ") == 0
            && utn_getNombre(persona->dni, 9, 0, "Ingrese el DNI: ", "Error de ingreso. ") == 0
            && utn_getFloat(&persona->altura, 0, 0, 500, "Ingrese su peso: ", "Error de ingreso. ") == 0)
        {
            return 0;
        }
    }
    return retorno;
}

void person_imprimirPersona(Persona* persona)
{
    printf("Nombre: %s\nEdad: %d\nDNI: %s\nAltura: %.2f", persona->nombre, persona->edad, persona->dni, persona->altura);
}
