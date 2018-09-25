#include "contratacion.h"

static int getNuevoIdContratacion(void);

int contratacion_inicializarArray(Contratacion* contrataciones, int longitud)
{
    int retorno = -1;
    int i;

    if(contrataciones != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
            contrataciones[i].isEmpty = EMPTY;
        retorno = 0;
    }

    return retorno;
}

static int getNuevoIdContratacion(void)
{
    static int contadorID = CONTRATACION_INICIAL - 1;
    contadorID++;
    return contadorID;
}