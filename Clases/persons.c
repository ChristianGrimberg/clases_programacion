#include "persons.h"

/** \brief
 *  Funcion que coloca una persona con valores por defecto.
 *  \param persona Persona* Puntero a Estructura Persona.
 *  \return 0 si pudo colocar los valores por defecto, -1 si hubo un error.
 * 
 */
static int nullPerson(Persona* persona);

/** \brief
 *  Funcion que da el Alta de una Persona.
 *  \param person Persona* Puntero a Estructura Persona.
 *  \param retry int Cantidad de reintentos en caso de error.
 *  \return 0 si pudo cargar la persona correctamente, -1 si hubo un error.
 * 
 */
static int newPerson(Persona* person, int retry);

int persons_inicializarArray(Persona* personas, int limite)
{
    int retorno = -1;
    Persona personaAux;
    int i;

    if(personas != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            personaAux = personas[i];
            if(nullPerson(&personaAux) == 0)
            {
                personas[i] = personaAux;
                retorno = 0;
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }

    return retorno;
}

int persons_altaPersonas(Persona* personas, int cantidad, int reintentos)
{
    int retorno = -1;
    Persona personaAux;
    int i;

    if(personas != NULL && cantidad > 0 && reintentos >= 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(newPerson(&personaAux, reintentos) == 0)
            {
                personas[i] = personaAux;
                retorno = 0;
            }
        }
    }

    return retorno;
}

void persons_imprimirPersonas(Persona* personas, int limite)
{
    int i;
    char edadAux[5];
    char alturaAux[15];

    if(personas != NULL && limite > 0)
    {
        printf("\n-------------------------------------------------------------------------------\n");
        printf("|%10s%10s|%5s%2s|%7s%7s|%7s%7s|%9s%9s|\n",
            "Nombre", "", "Edad", "", "DNI", "", "Altura", "", "Telefono", "");
        printf("===============================================================================\n");
        for(i = 0; i < limite; i++)
        {
            sprintf(edadAux, "%d", (personas[i]).edad);
            sprintf(alturaAux, "%.2f", (personas[i]).altura);
            printf("|%19s |%6s |%13s |%13s |%17s |\n",
                (personas[i]).nombre, edadAux, (personas[i]).dni, alturaAux, (personas[i]).telefono);
        }
        printf("-------------------------------------------------------------------------------\n\n");
    }
}

static int nullPerson(Persona* persona)
{
    int returnValue = -1;

    if(persona != NULL)
    {
        strncpy(persona->nombre, NULL_STRING, 8);
        persona->edad = NULL_EDAD;
        strncpy(persona->dni, "0", 2);
        persona->altura = NULL_ALTURA;
        strncpy(persona->telefono, NULL_STRING, 8);

        returnValue = 0;
    }

    return returnValue;
}

static int newPerson(Persona* person, int retry)
{
    int returnValue = -1;
    char nameAux[NAME_LIMITS];
    int ageAux;
    char dniAux[DNI_LIMITS];
    float heightAux;
    char phoneAux[PHONE_LIMITS];
    char error[] = "Error de ingreso.\n";

    if(person != NULL)
    {
        if(utn_getString(nameAux, NAME_LIMITS, retry, "Ingrese el nombre: ", error) == 0
            && utn_getInt(&ageAux, retry, 0, 200, "Ingrese la edad: ", error) == 0
            && utn_getString(dniAux, DNI_LIMITS, retry, "Ingrese el DNI con separador de miles: ", error) == 0
            && utn_getFloat(&heightAux, retry, 0, 3, "Ingrese su altura en metros: ", error) == 0
            && utn_getPhone(phoneAux, PHONE_LIMITS, retry, "Ingrese el numero de telefono: ", error) == 0)
        {
            strncpy(person->nombre, nameAux, NAME_LIMITS);
            person->edad = ageAux;
            strncpy(person->dni, dniAux, DNI_LIMITS);
            person->altura = heightAux;
            strncpy(person->telefono, phoneAux, PHONE_LIMITS);
            returnValue = 0;
        }
    }
    return returnValue;
}
