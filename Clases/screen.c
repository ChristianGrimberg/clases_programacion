#include "screen.h"

static int getNuevoIdPantalla(void);

int screen_inicializarArray(Pantalla* pantallas, int longitud)
{
    int retorno = -1;
    int i;

    if(pantallas != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
            pantallas[i].isEmpty = EMPTY;
        retorno = 0;
    }

    return retorno;
}

int screen_buscarLugarLibre(Pantalla* pantallas, int longitud)
{
    int retorno = -1;
    int i;

    if(pantallas != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if((pantallas + i)->isEmpty == EMPTY)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int screen_altaPantalla(Pantalla* pantallas, int indice)
{
    int retorno = -1;
    Pantalla pantallaAuxiliar;
    char error[] = "Valor incorrecto. ";

    if(pantallas != NULL && indice >= 0)
    {
        pantallaAuxiliar.pantallaID = getNuevoIdPantalla();
        if(utn_getInt(&pantallaAuxiliar.tipo, REINTENTOS, LED, LCD, "Ingrese 1 para LED, 2 para LCD: ", error) == 0
            && utn_getString(pantallaAuxiliar.nombre, NOMBRE_MAX, REINTENTOS, "Ingrese el nombre de la pantalla: ", error, ALL_CHARACTERES) == 0
            && utn_getString(pantallaAuxiliar.direccion, DIRECCION_MAX, REINTENTOS, "Ingrese la direccion: ", error, ALL_CHARACTERES) == 0
            && utn_getFloat(&pantallaAuxiliar.precioPorDia, REINTENTOS, 1.0f, 1000000.0f, "Ingrese el precio: ", "Rango del valor no aceptado. ") == 0)
        {
            if(pantallas[indice].isEmpty == EMPTY)
            {
                pantallas[indice] = pantallaAuxiliar;
                (pantallas + indice)->isEmpty = FULL;
                retorno = 0;
            }
        }
    }

    return retorno;
}

int screen_buscarPantallaPorId(Pantalla* pantallas, int longitud, int idPantalla)
{
    int retorno = -1;
    int i;
    if(pantallas != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(pantallas[i].isEmpty == FULL && pantallas[i].pantallaID == idPantalla)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int screen_eliminarPantallaPorId(Pantalla* pantalla, int idPantalla)
{
    int retorno = -1;

    if(pantalla != NULL && pantalla[idPantalla].isEmpty == FULL)
    {
        pantalla[idPantalla].isEmpty = EMPTY;
        retorno = 0;
    }

    return retorno;
}

static int getNuevoIdPantalla(void)
{
    static int contadorID = 0;
    contadorID++;
    return contadorID;
}
