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
    printf("2. Modificar Pantalla existente.\n");
    printf("3. Baja de Pantalla.\n");
    printf("9. Informar Pantallas.\n");
    printf("%d. Salir del programa.\n", SALIR_PROGRAMA);
    printf("=======================================\n");
    if(utn_getInt(&opcionAuxiliar, REINTENTOS, 1, SALIR_PROGRAMA, "Indique la opcion deseada: ", "Seleccion no valida. ") == 0)
        retorno = opcionAuxiliar;

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
            printf("\n|%5s%2s|%20s%10s|%5s%1s|%20s%10s|%12s%2s|\n",
                "ID", "", "Nombre", "", "Tipo", "", "Direccion", "", "Precio Dia", "");
            printf("+=======+==============================+======+==============================+==============+\n");
        }
        printf("|%6s |%29s |%5s |%29s |%13s |\n",
            idAux, (pantalla+indice)->nombre, tipoAux, (pantalla+indice)->direccion, precioAux);
    }
    else
        printf("Pantalla no encontrada.\n");
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
