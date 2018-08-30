#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int getEdad(int* edad)
{
    int edadAux;
    int retorno = -1;
    int ingreso;

    do
    {
        printf("Ingrese la edad: ");
        setbuf(stdin, NULL);
        ingreso = scanf("%d", &edadAux);
        if(ingreso == 1)
        {
            *edad = edadAux;
            retorno = 0;
            break;
        }
    } while(ingreso != 1);

    return retorno;
}
