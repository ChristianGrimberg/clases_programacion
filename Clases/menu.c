#include "menu.h"

int menu_opcionesMenu(void)
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
