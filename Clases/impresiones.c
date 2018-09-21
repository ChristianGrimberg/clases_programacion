#include "impresiones.h"

static void pauseScreen(char* mensaje);

int impresiones_menuPrincipal(void)
{
    int retorno = -1;
    int opcionAuxiliar;

    system("clear");
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

void impresiones_imprimirPantalla(Pantalla* pantalla, int indice)
{
    char tipo[4];

    if(pantalla != NULL && indice >= 0)
    {
        if(pantalla->tipo == LED)
            strncpy(tipo, "LED", 4);
        else if(pantalla->tipo == LCD)
            strncpy(tipo, "LCD", 4);

        printf("ID: %d\tNombre: %s\tTipo: %s\tDireccion: %s\tPrecio por Dia: %.2f\tVacio: %d\n",
            pantalla->pantallaID, pantalla->nombre, tipo, pantalla->direccion, pantalla->precioPorDia, pantalla->isEmpty);
    }
    else
        printf("Pantalla no encontrada.\n");
}

static void pauseScreen(char* mensaje)
{
    char flush[2] = " \n";
    printf("%s\n", mensaje);
    __fpurge(stdin);
    fgets(flush, 2, stdin);
}
