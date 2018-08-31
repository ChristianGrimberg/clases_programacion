#include <stdio_ext.h> /**< Biblioteca Estandar de Entrada y Salida extendida */
#include <stdlib.h>

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

int getInt(int* pEdad, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int edadAux;
    int retorno = -1;
    int ingreso;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            ingreso = scanf("%d", &edadAux);
            if(ingreso == 1 && edadAux >= minimo && edadAux <= maximo)
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
