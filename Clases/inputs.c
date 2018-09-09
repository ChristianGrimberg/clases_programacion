#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "limits.h"
#include "float.h"

static int getInt(int* number); /**< Prototipo de funcion privada interno al source */
static int getFloat(float* decimal);
static int isNumber(char* stringValue);
static int isFloat(char* stringValue);

int inputs_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
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
            printf("Cantidad de intentos superada.\n");
    }

    return retorno;
}

int inputs_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error)
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
            printf("Cantidad de intentos superada.\n");
    }

    return retorno;
}

/**< Implementacion de funcion privada */
static int getInt(int* number)
{
    int returnValue = -1;
    char stringAux[CHARACTERS_NUMBERS];
    char stringAtoi[CHARACTERS_NUMBERS];
    int numberAux;

    if(fgets(stringAux, CHARACTERS_NUMBERS, stdin) != NULL)
    {
        if(isNumber(stringAux) == 0)
        {
            numberAux = atoi(stringAux);
            /**< Validating conversion functions in interger limits. */
            sprintf(stringAtoi, "%d\n", numberAux);
            if(strcmp(stringAux, stringAtoi) == 0)
            {
                *number = numberAux;
                returnValue = 0;
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
    char stringAux[CHARACTERS_NUMBERS];
    float numberAux;
    int numberInt;

    if(fgets(stringAux, CHARACTERS_NUMBERS, stdin) != NULL)
    {
        if(isFloat(stringAux) == 0)
        {
            numberAux = atof(stringAux);
            /**< Validating conversion functions in float limits. */
            numberInt = atoi(stringAux);
            if((int)numberAux == numberInt)
            {
                *decimal = numberAux;
                returnValue = 0;
            }        
        }
    }
    else
        __fpurge(stdin);

    return returnValue;
}

static int isNumber(char* stringValue)
{
    int returnValue = 0;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
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

    while(stringValue[i] != (int)EXIT_BUFFER)
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
        i++;
    }
    
    return returnValue;
}
