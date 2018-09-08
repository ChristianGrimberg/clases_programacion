#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int getInt(int* number); /**< Prototipo de funcion privada interno al source */
static int getFloat(float* decimal);
static int isNumber(char* stringValue);
static int isFloat(char* stringValue);

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int numeroAux;
    int retorno = -1;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            if(getInt(&numeroAux) == 0 && numeroAux >= minimo && numeroAux <= maximo)
            {
                *pNumero = numeroAux;
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

int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error)
{
    int retorno = -1;
    float floatAux;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            if(getFloat(&floatAux) == 0 && floatAux >= minimo && floatAux <= maximo)
            {
                *pNumero = floatAux;
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
    char stringAux[CHARACTERS_INT_64];
    int numberAux;

    if(fgets(stringAux, CHARACTERS_INT_64, stdin) != NULL)
    {
        if(isNumber(stringAux) == 0)
        {
            numberAux = atoi(stringAux);
            if(numberAux != INIT_INT_ARRAY)
            {
                *number = numberAux;
                returnValue = 0;returnValue = 0;
            }
        }
    }
    else
        __fpurge(stdin);

    return returnValue;
}

static int getFloat(float* decimal)
{
    int returnValue = -1;
    float numberAux;

    if(scanf("%f", &numberAux) == 1)
    {
        *decimal = numberAux;
        returnValue = 0;
    }
    else
        __fpurge(stdin);

    return returnValue;
}

static int isNumber(char* stringValue)
{
    int returnValue = 0;
    int i = 0;

    while(stringValue[i] != (int)BUFFER_SCAPE)
    {
        if(i == 0 && (stringValue[0] == (int)'-' || stringValue[0] == (int)'+'))
            i = 1;

        if((int)stringValue[i] < (int)'0' || (int)stringValue[i] > (int)'9')
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}

static int isFloat(char* stringValue)
{
    int returnValue = 0;
    int pointerCounter = 0;
    int i = 0;

    while(stringValue[i] != (int)BUFFER_SCAPE)
    {
        if(i == 0 && (stringValue[0] == (int)'-' || stringValue[0] == (int)'+'))
            i = 1;

        if(stringValue[i] == '.')
            pointerCounter++;
        else if((int)stringValue[i] < (int)'0' || (int)stringValue[i] > (int)'9' || pointerCounter > 1)
        {
            returnValue = -1;
            break;
        }
    }

    return returnValue;
}
