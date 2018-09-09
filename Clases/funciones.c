#include <stdio_ext.h> /**< Biblioteca Estandar de Entrada y Salida extendida */
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

int getEntero(int* pEdad, int reintentos, int minimo, int maximo, char* mensaje, char* error)
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

int debugIntArray(int* pArray, int limit)
{
    int retorno = 0;
    int i;

    for(i=0; i<limit; i++)
    {
        printf("\nIndex: %d, Value: %d, Add: %p.", i, pArray[i], pArray+i);
    }

    return retorno;
}

int debugFloatArray(float* pArray, int limit)
{
    int retorno = 0;
    int i;

    for(i=0; i<limit; i++)
    {
        printf("\nIndex: %d, Value: %.2f, Add: %p.", i, pArray[i], pArray+i);
    }

    return retorno;
}

int getMaxIntArray(int* pArray, int limit, int* pMaximo)
{
    int retorno = -1;
    int maximo = 0;
    int flagPrimerMaximo = false;
    int i;

    if(pArray != NULL && limit > 0)
    {
        for(i=0; i < limit; i++)
        {
            if(pArray[i] != INITIALIZER)
            {

                if(flagPrimerMaximo == true && pArray[i] > maximo)
                    maximo = pArray[i];
                else if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
            }
        }

        if(flagPrimerMaximo == false)
        {
            retorno = -2;
        }
        else if(flagPrimerMaximo == true)
        {
            retorno = 0;
            *pMaximo = maximo;
        }
    }

    return retorno;
}

int initIntArrayInt(int* pArray, int limit, int value)
{
    int returnValue = -1;
    int i;

    if(pArray != NULL && limit > 0)
    {
        returnValue = 0;
        for(i=0; i < limit; i++)
        {
            pArray[i] = value;
            //*(pArray + 1) = valor;
        }
    }

    return returnValue;
}

int initFloatArrayInt(float* pArray, int limit, int value)
{
    int returnValue = -1;
    int i;

    if(pArray != NULL && limit > 0)
    {
        returnValue = 0;
        for(i=0; i < limit; i++)
        {
            pArray[i] = value;
            //*(pArray + 1) = valor;
        }
    }

    return returnValue;
}

int intBubbleSort(int* pArray, int limit, int ascOrDesc)
{
    int returnValue = -1;
    int i;
    int flagToOrder = 1;
    int valueAux;

    if(limit > 0 && pArray != NULL && (ascOrDesc == ASC || ascOrDesc == DESC))
    {
        while(flagToOrder == 1)
        {
            flagToOrder = 0;
            for(i = 0; i < limit-1; i++)
            {
                if((ascOrDesc == ASC && pArray[i] > pArray[i+1])
                || (ascOrDesc == DESC && pArray[i] < pArray[i+1]))
                {
                    valueAux = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = valueAux;
                    flagToOrder = 1;
                }
            }
        }
        returnValue = 0;
    }

    return returnValue;
}

int floatBubbleSort(float* pArray, int limit, int ascOrDesc)
{
    int returnValue = -1;
    int i;
    int flagToOrder = 1;
    float valueAux;

    if(limit > 0 && pArray != NULL && (ascOrDesc == ASC || ascOrDesc == DESC))
    {
        while(flagToOrder == 1)
        {
            flagToOrder = 0;
            for(i = 0; i < limit-1; i++)
            {
                if((ascOrDesc == ASC && pArray[i] > pArray[i+1])
                || (ascOrDesc == DESC && pArray[i] < pArray[i+1]))
                {
                    valueAux = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = valueAux;
                    flagToOrder = 1;
                }
            }
        }
        returnValue = 0;
    }

    return returnValue;
}
