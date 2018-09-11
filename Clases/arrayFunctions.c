#include <stdio_ext.h> /**< Biblioteca Estandar de Entrada y Salida extendida */
#include <stdlib.h>
#include "arrayFunctions.h"

static int swapIntArrayElements(int* pArray, int i, int j);
static int swapFloatArrayElements(float* pArray, int i, int j);

void debugIntArray(int* pArray, int limit, char* message)
{
    int i;

    printf(message);
    for(i=0; i<limit; i++)
    {
        printf("\nIndex: %d, Value: %d, Add: %p.", i, pArray[i], pArray+i);
    }
    printf("\n");
}

void debugFloatArray(float* pArray, int limit, char* message)
{
    int i;

    printf(message);
    for(i=0; i<limit; i++)
    {
        printf("\nIndex: %d, Value: %.2f, Add: %p.", i, pArray[i], pArray+i);
    }
    printf("\n");
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

static int swapIntArrayElements(int* pArray, int i, int j)
{
    int returnValue = -1;
    int valueAux;

    if(pArray != NULL && sizeof(pArray) > i && sizeof(pArray) > j)
    {
        valueAux = pArray[i];
        pArray[i] = pArray[j];
        pArray[j] = valueAux;
        returnValue = 0;
    }

    return returnValue;
}

static int swapFloatArrayElements(float* pArray, int i, int j)
{
    int returnValue = -1;
    float valueAux;

    if(pArray != NULL && sizeof(pArray) > i && sizeof(pArray) > j)
    {
        valueAux = pArray[i];
        pArray[i] = pArray[j];
        pArray[j] = valueAux;
        returnValue = 0;
    }

    return returnValue;
}

int intBubbleSort(int* pArray, int limit, int ascOrDesc)
{
    int returnValue = -1;
    int i;
    int flagToOrder = 1;

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
                    if(swapIntArrayElements(pArray, i, i+1) == 0)
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
                    if(swapFloatArrayElements(pArray, i, i+1) == 0)
                        flagToOrder = 1;
                }
            }
        }
        returnValue = 0;
    }

    return returnValue;
}

int intInsertionSort(int* pArray, int limit, int ascOrDesc)
{
    int returnValue = -1;
    int holeIndex = 0;
    int value = 0;
    int i;

    if(limit > 0 && pArray != NULL && (ascOrDesc == ASC || ascOrDesc == DESC))
    {
        for(i = 1; i < limit; i++)
        {
            value = pArray[i];
            holeIndex = i;
            while((holeIndex > 0)
            && ((pArray[holeIndex-1] > value && ascOrDesc == ASC)
            || (pArray[holeIndex-1] < value && ascOrDesc == DESC)))
            {
                pArray[holeIndex] = pArray[holeIndex-1];
                holeIndex--;
            }
            pArray[holeIndex] = value;
        }
        returnValue = 0;
    }

    return returnValue;
}
