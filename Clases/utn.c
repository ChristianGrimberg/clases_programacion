#include <stdio_ext.h>
#include <stdlib.h>

static int getInt(int* number); /**< Prototipo de funcion privada interno al source */

int utn_getInt(int* pEdad, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int edadAux;
    int retorno = -1;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            if(getInt(&edadAux) == 0 && edadAux >= minimo && edadAux <= maximo)
            {
                *pEdad = edadAux;
                retorno = 0;
                break;
            }
            else
            {
                /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
                __fpurge(stdin);
                printf(error);
            }
        }

        if(reintentos == 0)
            printf("Cantidad de intentos superada.");
    }

    return retorno;
}

/**< Implementacion de funcion privada */
static int getInt(int* number)
{
    int returnValue = -1;
    int numberAux;

    if(scanf("%d", &numberAux) == 1)
    {
        *number = numberAux;
        returnValue = 0;
    }

    return returnValue;
}
