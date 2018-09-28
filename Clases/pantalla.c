#include "pantalla.h"

static int getNuevoIdPantalla(void);

int pantalla_inicializarArray(Pantalla* pantallas, int longitud)
{
    int retorno = -1;
    int i;

    if(pantallas != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            (pantallas+i)->pantallaID = PANTALLA_INICIALIZADOR;
            (pantallas+i)->isEmpty = EMPTY;
        }
        retorno = 0;
    }

    return retorno;
}

int pantalla_buscarLugarLibre(Pantalla* pantallas, int longitud)
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

int pantalla_buscarPantallaPorId(Pantalla* pantallas, int longitud, int idPantalla)
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

int pantalla_altaPantalla(Pantalla* pantallas, int indice)
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
            && utn_getFloat(&pantallaAuxiliar.precioPorDia, REINTENTOS, 1.0f, 1000000.0f, "Ingrese el precio por dia: ", "Rango del valor no aceptado. ") == 0)
        {
            if(pantallas[indice].isEmpty == EMPTY)
            {
                pantallas[indice] = pantallaAuxiliar;
                (pantallas + indice)->isEmpty = FULL;
                retorno = 0;
            }
        }
        else
            printf("Error de carga de la Pantalla.\n");
    }

    return retorno;
}

void pantalla_altaHardCode(Pantalla* pantallas, int longitud, int indice, int id, int tipo, char* nombre, char* direccion, float precio)
{
    if(pantallas != NULL && longitud > 0 && indice >= 0 && nombre != NULL && direccion != NULL && precio > 0 && (tipo == LED || tipo == LCD))
    {
        (pantallas+indice)->pantallaID = id;
        (pantallas+indice)->tipo = tipo;
        strncpy((pantallas+indice)->nombre, nombre, NOMBRE_MAX);
        strncpy((pantallas+indice)->direccion, direccion, DIRECCION_MAX);
        (pantallas+indice)->precioPorDia = precio;
        (pantallas+indice)->isEmpty = FULL;
    }
}

int pantalla_eliminarPantallaPorIndice(Pantalla* pantalla, int indicePantalla)
{
    int retorno = -1;

    if(pantalla != NULL && pantalla[indicePantalla].isEmpty == FULL)
    {
        pantalla[indicePantalla].isEmpty = EMPTY;
        retorno = 0;
    }

    return retorno;
}

int pantalla_modificarValorPantalla(Pantalla* pantalla, int indicePantalla, int modificarValor)
{
    int retorno = -1;
    Pantalla pantallaAuxiliar;
    char error[] = "Valor incorrecto. ";
    char cancelar[] = "Modificacion cancelada.\n";

    if(pantalla != NULL && indicePantalla >= 0 && indicePantalla < PANTALLAS)
    {
        pantallaAuxiliar = pantalla[indicePantalla];
        switch(modificarValor)
            {
                case 1:
                    if(utn_getInt(&pantallaAuxiliar.tipo, REINTENTOS, LED, LCD, "Ingrese 1 para LED, 2 para LCD: ", error) == 0)
                    {
                        pantalla[indicePantalla] = pantallaAuxiliar;
                        retorno = 0;
                    }
                    else
                        printf(cancelar);
                    break;
                case 2:
                    if(utn_getString(pantallaAuxiliar.nombre, NOMBRE_MAX, REINTENTOS, "Ingrese el nombre de la pantalla: ", error, ALL_CHARACTERES) == 0)
                    {
                        pantalla[indicePantalla] = pantallaAuxiliar;
                        retorno = 0;
                    }
                    else
                        printf(cancelar);
                    break;
                case 3:
                    if(utn_getString(pantallaAuxiliar.direccion, DIRECCION_MAX, REINTENTOS, "Ingrese la direccion: ", error, ALL_CHARACTERES) == 0)
                    {
                        pantalla[indicePantalla] = pantallaAuxiliar;
                        retorno = 0;
                    }
                    else
                        printf(cancelar);
                    break;
                case 4:
                    if(utn_getFloat(&pantallaAuxiliar.precioPorDia, REINTENTOS, 1.0f, 1000000.0f, "Ingrese el precio por dia: ", "Rango del valor no aceptado. ") == 0)
                    {
                        pantalla[indicePantalla] = pantallaAuxiliar;
                        retorno = 0;
                    }
                    else
                        printf(cancelar);
                    break;
                case 5:
                    retorno = 0;
                    break;
            }
    }

    return retorno;
}

static int getNuevoIdPantalla(void)
{
    static int contadorIdPantalla = PANTALLA_INICIAL - 1;
    contadorIdPantalla++;
    return contadorIdPantalla;
}
