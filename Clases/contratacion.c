#include "contratacion.h"

/** \brief
 *  Funcion que obtiene un numero identificador incremental desde el 1 en adelante.
 *  \return Retorna el numero ID incremental.
 *
 */
static int getNuevoIdContratacion(void);

static int contratacion_buscarContratacionPorIdPantallaMasCuit(Contratacion* contrataciones, int longitud, int idPantalla, char* cuitCliente);

int contratacion_inicializarArray(Contratacion* contrataciones, int longitud)
{
    int retorno = -1;
    int i;

    if(contrataciones != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            (contrataciones+i)->contratacionID = CONTRATACION_INICIALIZADOR;
            (contrataciones+i)->isEmpty = EMPTY;
        }
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
    char mensajeDias[64];

    sprintf(mensajeDias, "Ingrese la cantidad de dias (%d~%d): ", DIAS_MIN, DIAS_MAX);
    if(contrataciones != NULL && indiceContratacion >= 0 && pantallas != NULL && longitudPantallas > 0)
    {
        contratacionAuxiliar.contratacionID = getNuevoIdContratacion();
        if(utn_getInt(&contratacionAuxiliar.pantallaID, REINTENTOS, 1, longitudPantallas, "Elija el ID de pantalla a cargar: ", error) == 0
            && pantalla_buscarPantallaPorId(pantallas, PANTALLAS, contratacionAuxiliar.pantallaID) != -1
            && utn_getCUIT(contratacionAuxiliar.CUIT, CUIT_MAX, REINTENTOS, "Ingrese el CUIT del Cliente: ", error) == 0
            && utn_getString(contratacionAuxiliar.video, VIDEO_MAX, REINTENTOS, "Ingrese el nombre del archivo de video: ", error, ALL_CHARACTERES) == 0
            && utn_getInt(&contratacionAuxiliar.diasPublicacion, REINTENTOS, DIAS_MIN, DIAS_MAX, mensajeDias, error) == 0)
        {
            if(contratacion_buscarContratacionPorIdPantallaMasCuit(contrataciones, CONTRATACIONES, contratacionAuxiliar.pantallaID, contratacionAuxiliar.CUIT) == -1
                && contrataciones[indiceContratacion].isEmpty == EMPTY)
            {
                contrataciones[indiceContratacion] = contratacionAuxiliar;
                (contrataciones + indiceContratacion)->isEmpty = FULL;
                retorno = 0;
            }
            else
                printf("Error: Ya existe una Contratacion de pantalla del Cliente ingresado.\n");
        }
        else
            printf("Valores ingresados incorrectos para una Contratacion de Pantalla.\n");
    }

    return retorno;
}

void contratacion_altaHardCode(Contratacion* contrataciones, int longitud, int indice, int id, char* cuit, char* video, int dias, int pantallaId)
{
    if(contrataciones != NULL && longitud > 0 && indice >= 0 && cuit != NULL && video != NULL && dias >= DIAS_MIN)
    {
        (contrataciones+indice)->contratacionID = id;
        strncpy((contrataciones+indice)->CUIT, cuit, CUIT_MAX);
        strncpy((contrataciones+indice)->video, video, VIDEO_MAX);
        (contrataciones+indice)->diasPublicacion = dias;
        (contrataciones+indice)->pantallaID = pantallaId;
        (contrataciones+indice)->isEmpty = FULL;
    }
}

int contratacion_modificarDiasPorIdPantallaMasCuit(Contratacion* contrataciones, int longitud, int idPantalla, char* cuitCliente)
{
    int retorno = -1;
    int indice;
    int dias;
    char mensajeDias[64];

    sprintf(mensajeDias, "Ingrese la cantidad de dias a modificar (%d~%d): ", DIAS_MIN, DIAS_MAX);
    indice = contratacion_buscarContratacionPorIdPantallaMasCuit(contrataciones, longitud, idPantalla, cuitCliente);   
    if(indice != -1 && utn_getInt(&dias, REINTENTOS, DIAS_MIN, DIAS_MAX, mensajeDias, "Valor fuera de rango. ") == 0)
    {
        (contrataciones+indice)->diasPublicacion = dias;
        retorno = 0;
    }
    else
        printf("El id de pantalla no corresponde.\n");

    return retorno;
}

static int getNuevoIdContratacion(void)
{
    static int contadorIdContratacion = CONTRATACION_INICIAL - 1;
    contadorIdContratacion++;
    return contadorIdContratacion;
}

static int contratacion_buscarContratacionPorIdPantallaMasCuit(Contratacion* contrataciones, int longitud, int idPantalla, char* cuitCliente)
{
    int retorno = -1;
    int i;

    if(contrataciones != NULL && longitud > 0 && cuitCliente != NULL)
    {
        for(i = 0; i < longitud; i++)
        {
            if(contrataciones[i].isEmpty == FULL
                && contrataciones[i].pantallaID == idPantalla
                && strncmp(contrataciones[i].CUIT, cuitCliente, CUIT_MAX) == 0)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}