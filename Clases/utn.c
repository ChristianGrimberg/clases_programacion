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
 *  Funcion que valida si una cadena ingresada no es un numero.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si no es numerico, -1 si lo es.
 *
 */
static int isNotNumber(char* stringValue);

/** \brief
 *  Funcion que valida si la cadena ingresada es numerica flotante o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es un flotante, -1 si no lo es.
 *
 */
static int isFloat(char* stringValue);

static int isFormatDNI(char* stringValue);

/** \brief
 *  Funcion que valida si la cadena ingresada es alfanumerica o no.
 *  \param stringValue char* Cadena de caracteres a validar.
 *  \return 0 si es alfanumerica, -1 si no lo es.
 *
 */
//static int isAlphaNumeric(char* stringValue);

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

int utn_getChar(char* pCaracter, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char charAux;

    if(pCaracter != NULL && reintentos >= 0 && mensaje != NULL && mensajeError != NULL)
    {
        printf(mensaje);
        __fpurge(stdin);
        fgets(&charAux, 2, stdin); /**< Por si esta el caracter \n en el buffer. */
        if(sizeof(charAux) == 1)
        {
            strncpy(pCaracter, &charAux, 1);
            retorno = 0;
        }
        else
            printf(mensajeError);
    }

    return retorno;
}

int utn_getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError, int isOnlyLetters)
{
    int retorno = -1;
    char stringAux[STRING_MAX];

    if(pNombre != NULL && limite > 0 && reintentos >= 0 && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if((isOnlyLetters == ALL_CHARACTERES && getString(stringAux, limite) == 0)
                || (isOnlyLetters = ONLY_LETTERS && getStringOnlyLetters(stringAux, limite) == 0))
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
    char valorActual[2];
    int cantGuiones;
    int i;

    if(pTelefono != NULL && cantDeNumerosMax > 0 && reintentos >= 0 && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getString(stringAux, cantDeNumerosMax) == 0)
            {
                i = 0;
                cantGuiones = 0;
                valorActual[1] = EXIT_BUFFER;
                while(stringAux[i] != EXIT_BUFFER)
                {
                    valorActual[0] = stringAux[i];
                    if(i > 0 && stringAux[i-1] == stringAux[i] && (stringAux[i] == '-' || stringAux[i] == '+'))
                    {
                        retorno = -1;
                        break;
                    }
                    else if(stringAux[i] == '-')
                    {
                        cantGuiones++;
                        i++;
                        continue;
                    }
                    else if(i == 0 && stringAux[i] == '+')
                    {
                        i++;
                        continue;
                    }


                    if((isNotNumber(valorActual) == 0 && stringAux[i] != '-') || cantGuiones > 2)
                    {
                        retorno = -1;
                        break;
                    }
                    else if(isNumber(valorActual) == 0)
                        retorno = 0;
                    i++;
                }
                if(valorActual[0] == '-')
                    retorno = -1;
            }
            if(retorno == 0)
            {
                strncpy(pTelefono, stringAux, cantDeNumerosMax);
                reintentos = -1;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getDNI(char* pDNI, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char dniAux[DNI_MAX];

    if(pDNI != NULL && reintentos > 0 && cantDeNumerosMax > 0 && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            reintentos--;
            printf(mensaje);
            if(getString(dniAux, DNI_MAX) == 0 && isFormatDNI(dniAux) == 0)
            {
                strncpy(pDNI, dniAux, cantDeNumerosMax);
                retorno = 0;
                break;
            }
            else
                printf(mensajeError);
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getCUIT(char* pCUIT, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    char auxiliarCUIT[cantDeNumerosMax];
    char cabeceraCUIT[3];
    char dniCUIT[DNI_MAX];
    char pieCUIT[2];
    int i;
    int j;
    int k;

    if(pCUIT != NULL && cantDeNumerosMax > 0 && reintentos > 0 && mensaje != NULL && mensajeError != NULL)
    {
         do
         {
             reintentos--;
             printf(mensaje);
             if(getString(auxiliarCUIT, cantDeNumerosMax) == 0)
             {
                 for(i = 0; i < 2; i++)
                {
                    cabeceraCUIT[i] = auxiliarCUIT[i];
                }
                cabeceraCUIT[2] = '\0';
                if(isNumber(cabeceraCUIT) == 0 && auxiliarCUIT[2] == '/')
                {
                    for(j = 3; auxiliarCUIT[j] != '-'; j++)
                    {
                        dniCUIT[j-3] = auxiliarCUIT[j];
                    }
                    k = j-3;
                    dniCUIT[k] = '\0';
                    pieCUIT[0] = auxiliarCUIT[k+4];
                    pieCUIT[1] = '\0';
                    if(isFormatDNI(dniCUIT) == 0 && auxiliarCUIT[k+3] == '-' && isNumber(pieCUIT) == 0)
                    {
                        retorno = 0;
                        strncpy(pCUIT, auxiliarCUIT, cantDeNumerosMax);
                        break;
                    }
                }
             }
         }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getEmail(char* pEmail, int limite, int reintentos, char* mensaje, char* mensajeError)
{
    int retorno = -1;
    printf("Sin implementacion.\n");
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
    char charAux;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        charAux = stringValue[i];
        if(i == 0 && (charAux == '-' || charAux == '+'))
            i = 1;

        if((int)charAux >= (int)'0' && (int)charAux <= (int)'9')
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

static int isNotNumber(char* stringValue)
{
    int returnValue = -1;
    char charAux;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        charAux = stringValue[i];
        if((int)charAux < (int)'0' || (int)charAux > (int)'9')
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

static int isFormatDNI(char* stringValue)
{
    int returnValue = -1;
    char dniAux[DNI_MAX];
    int pointCounter = 0;
    int pointSeparation = 0;
    char currentValue[2];
    int i =0;

    strncpy(dniAux, stringValue, DNI_MAX);
    currentValue[1] = EXIT_BUFFER;
    while(dniAux[i] != EXIT_BUFFER)
    {
        currentValue[0] = dniAux[i];
        if((i == 0 && isNotNumber(currentValue) == 0)
            || (i == 0 && isNumber(currentValue) == 0 && dniAux[i] == '0'))
        {
            returnValue = -1;
            break;
        }
        else if((dniAux[i] == '.' && pointSeparation%3 == 0)
            || (dniAux[i] == '.' && (pointSeparation > 0 && pointSeparation < 3) && pointCounter == 0))
        {
            pointCounter++;
            pointSeparation = 0;
            returnValue = 0;
        }
        else if(dniAux[i] == '.' && pointSeparation >= 3 && pointSeparation%3 != 0)
        {
            returnValue = -1;
            break;
        }
        else if(isNumber(currentValue) == 0)
        {
            pointSeparation++;
            returnValue = 0;
        }

        if(pointSeparation != 3)
        {
            returnValue = -1;
        }
        i++;
    }
    if(returnValue == 0)
        strncpy(stringValue, dniAux, DNI_MAX);

    return returnValue;
}

/*
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
*/

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
