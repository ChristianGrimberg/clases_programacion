#include "utn.h"

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

/** \brief
 *  Funcion que obtiene un puntero a un array de caracteres y valida su ingreso por teclado.
 *  \param imputString char* Array de caracteres para almacenar el valor ingreso por teclado.
 *  \param limit int Longitud del array de caracteres.
 *  \return 0 si pudo obtener el valor de manera correcta, -1 si hubo un error.
 *
 */
static int getString(char* imputString, int limit);

/** \brief
 *  Funcion que valida si la cadena ingresada es numerica entera o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es un entero, -1 si no lo es.
 *
 */
static int isNumber(char* stringValue);

/** \brief
 *  Funcion que valida si la cadena ingresada es numerica flotante o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es un flotante, -1 si no lo es.
 *
 */
static int isFloat(char* stringValue);

/** \brief
 *  Funcion que valida si la cadena ingresada es alfanumerica o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es alfanumerica, -1 si no lo es.
 *
 */
static int isAlphaNumeric(char* stringValue);

/** \brief
 *  La funcion obtiene un cadena por teclado y si es solo letras la referencia al parametro ingresado.
 *  \param imputString char* Array de caracteres para almacenar el valor ingreso por teclado.
 *  \param limit int Longitud del array de caracteres.
 *  \return 0 si pudo obtener el valor de manera correcta, -1 si hubo un error.
 *
 */
static int getStringOnlyLetters(char* imputString, int limit);

/** \brief
 *  La funcion obtiene un cadena por teclado y si es numerica la referencia al parametro ingresado.
 *  \param imputString char* Array de caracteres para almacenar el valor ingreso por teclado.
 *  \param limit int Longitud del array de caracteres.
 *  \return 0 si pudo obtener el valor de manera correcta, -1 si hubo un error.
 *
 */
static int getStringOnlyNumbers(char* imputString, int limit);

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
                printf(error);
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

int utn_getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char stringAux[STRING_MAX];

    if(pNombre != NULL && mensaje != NULL && mensajeError != NULL && limite > 0 && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getStringOnlyLetters(stringAux, limite) == 0)
            {
                strncpy(pNombre, stringAux, limite);
                retorno = 0;
                break;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getPhone(char* pTelefono, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char stringAux[cantDeNumerosMax];
    int cantGuiones = 0;
    int cantPositivos = 0;
    int i = 0;

    if(pTelefono != NULL && cantDeNumerosMax > 0 && reintentos >= 0)
    {
        if(getString(stringAux, cantDeNumerosMax) == 0)
        {
            while(stringAux[i] != EXIT_BUFFER)
            {
                if(stringAux[i] == '-')
                {
                    cantGuiones++;
                    continue;
                }
                else if(stringAux[i] == '-')
                {
                    cantPositivos++;
                    continue;
                }
                else if(isNumber(&stringAux[i]) == -1 || cantGuiones > 2 || cantPositivos > 1)
                {
                    retorno = -1;
                    break;
                }
                else
                    retorno = 0;
                i++;
            }
            if(retorno == 0)
                strncpy(pTelefono, stringAux, cantDeNumerosMax);
        }
    }

    return retorno;
}

static int getInt(int* number)
{
    int returnValue = -1;
    char stringAux[CHARACTERS_NUMBERS];
    char stringAtoi[CHARACTERS_NUMBERS];
    int numberAux;

    if(getStringOnlyNumbers(stringAux, CHARACTERS_NUMBERS) == 0 && isNumber(stringAux) == 0)
    {
        numberAux = atoi(stringAux);
        /**< Validating conversion functions in interger limits. */
        sprintf(stringAtoi, "%d", numberAux);
        if(strncmp(stringAux, stringAtoi, sizeof(stringAux)) == 0)
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

    if(getStringOnlyNumbers(stringAux, CHARACTERS_NUMBERS) == 0)
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

static int getString(char* imputString, int limit)
{
    int returnValue = -1;
    char stringAux[STRING_MAX];

    if(imputString != NULL && limit > 0)
    {
        __fpurge(stdin);
        fgets(stringAux, sizeof(stringAux), stdin);
        if(stringAux[(strlen(stringAux))-1] == '\n')
            stringAux[(strlen(stringAux))-1] = '\0';
        if(strlen(stringAux) <= limit)
        {
            sprintf(imputString, "%s", stringAux);
            returnValue = 0;
        }

    }

    return returnValue;
}

static int isNumber(char* stringValue)
{
    int returnValue = -1;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(i == 0 && ((int)stringValue[0] == (int)'-' || (int)stringValue[0] == (int)'+'))
            i = 1;

        if((int)stringValue[i] >= (int)'0' && (int)stringValue[i] <= (int)'9')
            returnValue = 0;
        else
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
    int returnValue = -1;
    int pointerCounter = 0;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(i == 0 && ((int)stringValue[0] == (int)'-' || (int)stringValue[0] == (int)'+'))
            i = 1;

        if(stringValue[i] == '.')
            pointerCounter++;
        else if((int)stringValue[i] >= (int)'0' && (int)stringValue[i] <= (int)'9' && pointerCounter <= 1)
            returnValue = 0;
        else
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}

static int isAlphaNumeric(char* stringValue)
{
    int returnValue = -1;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(((int)stringValue[i] >= (int)'0' && (int)stringValue[i] <= (int)'9')
        || ((int)stringValue[i] >= (int)'a' && (int)stringValue[i] <= (int)'z')
        || ((int)stringValue[i] >= (int)'A' && (int)stringValue[i] <= (int)'Z'))
            returnValue = 0;
        else
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}

static int getStringOnlyLetters(char* imputString, int limit)
{
    int returnValue = -1;
    char stringAux[limit];

    if(imputString != NULL && limit > 0)
    {
        if(getString(stringAux, limit) == 0 && isNumber(stringAux) == -1)
        {
            strncpy(imputString, stringAux, limit);
            returnValue = 0;
        }
    }

    return returnValue;
}

static int getStringOnlyNumbers(char* imputString, int limit)
{
    int returnValue = -1;
    char stringAux[limit];

    if(imputString != NULL && limit > 0)
    {
        if(getString(stringAux, limit) == 0 && isFloat(stringAux) == 0)
        {
            strncpy(imputString, stringAux, limit);
            returnValue = 0;
        }
    }

    return returnValue;
}
