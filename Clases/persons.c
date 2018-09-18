#include "persons.h"

int persons_altaPersona(Persona* persona, int reintentos)
{
    int retorno = -1;
    char nombreAux[NAME_LIMITS];
    int edadAux;
    char dniAux[DNI_LIMITS];
    float alturaAux;
    char telefonoAux[PHONE_LIMITS];
    char error[] = "Error de ingreso.\n";

    if(persona != NULL)
    {
        if(utn_getString(nombreAux, NAME_LIMITS, reintentos, "Ingrese el nombre: ", error) == 0
            && utn_getInt(&edadAux, reintentos, 0, 200, "Ingrese la edad: ", error) == 0
            && utn_getString(dniAux, DNI_LIMITS, reintentos, "Ingrese el DNI con separador de miles: ", error) == 0
            && utn_getFloat(&alturaAux, reintentos, 0, 3, "Ingrese su altura en metros: ", error) == 0
            && utn_getPhone(telefonoAux, PHONE_LIMITS, reintentos, "Ingrese el numero de telefono: ", error) == 0)
        {
            strncpy(persona->nombre, nombreAux, NAME_LIMITS);
            persona->edad = edadAux;
            strncpy(persona->dni, dniAux, DNI_LIMITS);
            persona->altura = alturaAux;
            strncpy(persona->telefono, telefonoAux, PHONE_LIMITS);
            retorno = 0;
        }
    }
    return retorno;
}

void persons_imprimirPersona(Persona* persona)
{
    printf("Nombre: %s\nEdad: %d\nDNI: %s\nAltura: %.2f\nTelefono: %s\n", persona->nombre, persona->edad, persona->dni, persona->altura, persona->telefono);
}
