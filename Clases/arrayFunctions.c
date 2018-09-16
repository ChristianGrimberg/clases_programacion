#include "arrayFunctions.h"

/** \brief
 *  Funcion que realiza un swap de un array de enteros entre los indices indicados.
 *  \param pArray int* Array de enteros.
 *  \param i int Indice de entero a cambiar.
 *  \param j int Indice de entero a cambiar.
 *  \return 0 si pudo alternar los valores del array de los indices indicados, -1 si hubo un error.
 */
static int swapIntArrayElements(int* pArray, int i, int j);

/** \brief
 *  Funcion que realiza un swap de un array de flotantes entre los indices indicados.
 *  \param pArray float* Array de flotantes.
 *  \param i int Indice de flotante a cambiar.
 *  \param j int Indice de flotante a cambiar.
 *  \return 0 si pudo alternar los valores del array de los indices indicados, -1 si hubo un error.
 */
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

int getMaxIntArray(int* pArray, int limit, int* pMaxInt)
{
    int returnValue = -1;
    int maxAux;
    int flagFirstMax = false;
    int i;

    if(pArray != NULL && limit > 0)
    {
        for(i=0; i < limit; i++)
        {
            if(pArray[i] != INITIALIZER)
            {
                if(flagFirstMax == true && pArray[i] > maxAux)
                    maxAux = pArray[i];
                else if(flagFirstMax == false)
                {
                    maxAux = pArray[i];
                    flagFirstMax = true;
                }
            }
        }

        if(flagFirstMax == false)
            returnValue = -2;
        else if(flagFirstMax == true)
        {
            returnValue = 0;
            *pMaxInt = maxAux;
        }
    }

    return returnValue;
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
    int j = 0;
    int value = 0;
    int i;

    if(limit > 0 && pArray != NULL && (ascOrDesc == ASC || ascOrDesc == DESC))
    {
        for(i = 1; i < limit; i++)
        {
            value = pArray[i];
            j = i;
            while((j > 0)
                && ((pArray[j-1] > value && ascOrDesc == ASC)
                || (pArray[j-1] < value && ascOrDesc == DESC)))
            {
                pArray[j] = pArray[j-1]; /**< Move values to the right. */
                j--;
            }
            pArray[j] = value; /**< Insertion action. */
        }
        returnValue = 0;
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
