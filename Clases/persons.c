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

void persons_imprimirPersona(Persona* pPersona, int limite)
{
    int i;
    char edadAux[5];
    char alturaAux[15];

    if(pPersona != NULL && limite > 0)
    {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("|%10s%10s|%5s%2s|%7s%7s|%7s%7s|%9s%9s|\n",
            "Nombre", "", "Edad", "", "DNI", "", "Altura", "", "Telefono", "");
        printf("===============================================================================\n");
        for(i = 0; i < limite; i++)
        {
            sprintf(edadAux, "%d", (pPersona[i]).edad);
            sprintf(alturaAux, "%.2f", (pPersona[i]).altura);
            printf("|%19s |%6s |%13s |%13s |%17s |\n",
                (pPersona[i]).nombre, edadAux, (pPersona[i]).dni, alturaAux, (pPersona[i]).telefono);
        }
        printf("-------------------------------------------------------------------------------\n\n");
    }
}
