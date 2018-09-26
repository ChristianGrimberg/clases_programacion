#include "impresiones.h"

static void clearScreen(void);
static void pauseScreen(char* mensaje);

int impresiones_menuPrincipal(void)
{
    int retorno = -1;
    int opcionAuxiliar;

    clearScreen();
    printf("==========VENTA DE PUBLICIDAD==========\n");
    printf("1. Alta de Pantalla.\n");
    printf("2. Modificar datos de Pantalla.\n");
    printf("3. Baja de Pantalla.\n");
    printf("4. Contratar una Publicidad.\n");
    printf("9. Informar Pantallas.\n");
    printf("%d. Salir del programa.\n", SALIR_PROGRAMA);
    printf("=======================================\n");
    if(utn_getInt(&opcionAuxiliar, REINTENTOS, 1, SALIR_PROGRAMA, "Indique la opcion deseada: ", "Seleccion no valida. ") == 0)
        retorno = opcionAuxiliar;

    return retorno;
}

int impresiones_menuModificarPantalla(Pantalla* pantalla, int indicePantalla)
{
    int retorno = -1;
    int opcionAuxiliar;

    if(pantalla != NULL && indicePantalla >= 0 && indicePantalla < PANTALLAS)
    {
        printf("==========MODIFICAR PANTALLA===========\n");
        printf("1. Modificar Tipo (1 para LED, 2 para LCD).\n");
        printf("2. Modificar Nombre de Pantalla.\n");
        printf("3. Modificar direccion de Pantalla.\n");
        printf("4. Modificar Precio por dia.\n");
        printf("5. Cancelar.\n");
        printf("=======================================\n");
        if(utn_getInt(&opcionAuxiliar, REINTENTOS, 1, 5, "Indique la opcion deseada: ", "Seleccion no valida. ") == 0)
            retorno = opcionAuxiliar;
    }

    return retorno;
}

void impresiones_imprimirPantalla(Pantalla* pantalla, int indice, int tabla)
{
    char idAux[6];
    char tipoAux[4];
    char precioAux[12];

    if(pantalla != NULL && indice >= 0)
    {
        if((pantalla+indice)->tipo == LED)
            strncpy(tipoAux, "LED", 4);
        else if((pantalla+indice)->tipo == LCD)
            strncpy(tipoAux, "LCD", 4);
        sprintf(idAux, "%d", (pantalla+indice)->pantallaID);
        sprintf(precioAux, "%.2f", (pantalla+indice)->precioPorDia);

        if(tabla == ENCABEZADO)
        {
            clearScreen();
            printf("+=======+==============================+======+==============================+==============+\n");
            printf("|%5s%2s|%20s%10s|%5s%1s|%20s%10s|%12s%2s|\n",
                "ID", "", "Nombre", "", "Tipo", "", "Direccion", "", "Precio Dia", "");
            printf("+=======+==============================+======+==============================+==============+\n");
        }
        printf("|%6s |%29s |%5s |%29s |%13s |\n",
            idAux, (pantalla+indice)->nombre, tipoAux, (pantalla+indice)->direccion, precioAux);
    }
    else
        printf("Pantalla no encontrada.\n");
}

int impresiones_imprimirListaPantallas(Pantalla* pantallas, int longitud)
{
    int retorno = -1;
    int contadorPantallas;
    int i;

    if(pantallas != NULL && longitud > 0)
    {
        contadorPantallas = 0;
        for(i = 0; i < PANTALLAS; i++)
        {
            if(pantallas[i].isEmpty == FULL)
            {
                contadorPantallas++;
                if(contadorPantallas == 1)
                    impresiones_imprimirPantalla(pantallas, i, ENCABEZADO);
                else
                    impresiones_imprimirPantalla(pantallas, i, LISTA);                        
            }
        }
        if(contadorPantallas > 0)
        {
            printf("+=======+==============================+======+==============================+==============+\n");
            retorno = contadorPantallas;
        }
        else if(contadorPantallas == 0)
            printf("No hay pantallas cargadas.\n");
    }

    return retorno;
}

static void clearScreen(void)
{
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif //__unix__
}

static void pauseScreen(char* mensaje)
{
    char flush[2] = " \n";
    printf("%s\n", mensaje);
    __fpurge(stdin);
    fgets(flush, 2, stdin);
}
