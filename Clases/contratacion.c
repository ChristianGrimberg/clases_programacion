#include "contratacion.h"

/** \brief
 *  Funcion que obtiene un numero identificador incremental desde el 1 en adelante.
 *  \return Retorna el numero ID incremental.
 * 
 */
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

int contratacion_buscarLugarLibre(Contratacion* contrataciones, int longitud)
{
    int retorno = -1;
    int i;

    if(contrataciones != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if((contrataciones + i)->isEmpty == EMPTY)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int contratacion_altaContratacion(Contratacion* contrataciones, int indiceContratacion, Pantalla* pantallas, int longitudPantallas)
{
    int retorno = -1;
    Contratacion contratacionAuxiliar;
    char error[] = "Valor incorrecto. ";
    int cantidadPantallas;

    if(contrataciones != NULL && indiceContratacion >= 0 && pantallas != NULL && longitudPantallas > 0)
    {
        contratacionAuxiliar.pantallaID = getNuevoIdContratacion();
        cantidadPantallas = impresiones_imprimirListaPantallas(pantallas, PANTALLAS);
        if(cantidadPantallas != -1)
        {
            if(utn_getInt(&contratacionAuxiliar.pantallaID, REINTENTOS, 1, cantidadPantallas, "Elija el ID de pantalla a cargar: ", error) == 0
                && utn_getDNI(contratacionAuxiliar.CUIT, CUIT_MAX, REINTENTOS, "Ingrese el CUIT del Cliente: ", error) == 0
                && utn_getString(contratacionAuxiliar.video, VIDEO_MAX, REINTENTOS, "Ingrese el nombre del archivo de video: ", error, ALL_CHARACTERES) == 0
                && utn_getInt(&contratacionAuxiliar.diasPublicacion, REINTENTOS, 15, 365, "Ingrese la cantidad de dias (15~365): ", error) == 0)
            {
                if(contrataciones[indiceContratacion].isEmpty == EMPTY)
                {
                    contrataciones[indiceContratacion] = contratacionAuxiliar;
                    (contrataciones + indiceContratacion)->isEmpty = FULL;
                    retorno = 0;
                } 
            }
            else
                printf("Error de carga en la contratacion.\n");
        }
        else
            printf("No puede cargar una contratacion sin pantallas cargadas.\n");
    }

    return retorno;
}

static int getNuevoIdContratacion(void)
{
    static int contadorID = CONTRATACION_INICIAL - 1;
    contadorID++;
    return contadorID;
}