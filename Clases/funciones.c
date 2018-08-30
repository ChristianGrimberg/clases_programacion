#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"

int getEdad(int* pEdad)
{
    int edadAux;
    int retorno = -1;
    int ingreso;

    do
    {
        printf("Ingrese la edad: ");
        //setbuf(stdin, NULL);
        ingreso = scanf("%d", &edadAux);

        if(ingreso == 1 && edadAux >= 0 && edadAux <= 199)
        {
            *pEdad = edadAux;
            retorno = 0;
            break;
        }
        else
            /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
            __fpurge(stdin);
    } while(ingreso != 1);

    return retorno;
}
