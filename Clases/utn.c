#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "limits.h"
#include "float.h"

/** \brief
 *  Funcion que obtiene y valida un valor entero por ingreso de teclado.
 *  \param number int* Posicion de memoria a almacenar el entero validado.
 *  \return Retorna 0 si obtuvo un numero entero, -1 si no es un valor valido.
 *
 */
static int getInt(int* number);

/** \brief
 *  Funcion que obtiene y valida un valor flotante por ingreso de teclado.
 *  \param decimal float* Posicion de memoria a almacenar el decimal validado.
 *  \return Retorna 0 si obtuvo un numero flotante, -1 si no es un valor valido.
 *
 */
static int getFloat(float* decimal);

static int getString(char* inputString, int limit);

/** \brief
 *  Funcion que valido si la cadena ingresada es numerica entera o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es un entero, -1 si no lo es.
 *
 */
static int isNumber(char* stringValue);

/** \brief
 *  Funcion que valido si la cadena ingresada es numerica flotante o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es un flotante, -1 si no lo es.
 *
 */
static int isFloat(char* stringValue);

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int numeroAux;
    int retorno = -1;

    if(maximo >= minimo && reintentos >= 0 && pNumero != NULL && mensaje != NULL && error != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getInt(&numeroAux) == 0 && numeroAux >= minimo && numeroAux <= maximo)
            {
                *pNumero = numeroAux;
                retorno = 0;
                break;
            }
            else
                printf("%s", error);
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error)
{
    int retorno = -1;
    float floatAux;

    if(maximo >= minimo && reintentos >= 0 && pNumero != NULL && mensaje != NULL && error != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getFloat(&floatAux) == 0 && floatAux >= minimo && floatAux <= maximo)
            {
                *pNumero = floatAux;
                retorno = 0;
                break;
            }
            else
                printf("%s", error);
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getNombre(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char stringAux[STRING_MAX];

    if(pNombre != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getString(stringAux, limite) == 0)
            {
                strcpy(pNombre, stringAux);
                retorno = 0;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

static int getInt(int* number)
{
    int returnValue = -1;
    char stringAux[CHARACTERS_NUMBERS];
    char stringAtoi[CHARACTERS_NUMBERS];
    int numberAux;

    if(getString(stringAux, CHARACTERS_NUMBERS) == 0  && isNumber(stringAux) == 0)
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


    return returnValue;
}

static int getFloat(float* decimal)
{
    int returnValue = -1;
    char stringAux[CHARACTERS_NUMBERS];
    float numberAux;
    int numberInt;

    if(getString(stringAux, CHARACTERS_NUMBERS) == 0 && isFloat(stringAux) == 0)
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

    return returnValue;
}

static int getString(char* inputString, int limit)
{
    int returnValue = -1;
    char stringAux[STRING_MAX];

    if(inputString != NULL && limit > 0)
    {
        __fpurge(stdin);
        fgets(stringAux, sizeof(stringAux), stdin);
        if(stringAux[(strlen(stringAux))-1] == '\n')
            stringAux[(strlen(stringAux))-1] = '\0';
        if(strlen(stringAux) <= limit)
        {
            sprintf(inputString, "%s", stringAux);
            returnValue = 0;
        }

    }

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
