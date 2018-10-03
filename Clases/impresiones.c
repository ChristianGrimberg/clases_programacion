#include "impresiones.h"

static void clearScreen(void);

void pauseScreen(char* mensaje)
{
    char flush[2] = " \n";
    printf("%s\n", mensaje);
    __fpurge(stdin);
    fgets(flush, 2, stdin);
}

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
    printf("5. Modificar condiciones de Publicacion.\n");
    printf("6. Cancelar Contratacion.\n");
    printf("7. Consultar Contratacion por CUIT.\n");
    printf("8. Listar Contrataciones.\n");
    printf("9. Listar Pantallas.\n");
    printf("%d. Salir del programa.\n", SALIR_PROGRAMA);
    printf("=======================================\n");
    if(utn_getInt(&opcionAuxiliar, RETRY, 1, SALIR_PROGRAMA, "Indique la opcion deseada: ", "Seleccion no valida. ") == 0)
        retorno = opcionAuxiliar;

    return retorno;
}

int impresiones_menuModificarPantalla(Pantalla* pantalla, int indicePantalla)
{
    int retorno = -1;
    int opcionAuxiliar;

    if(pantalla != NULL && indicePantalla >= 0 && indicePantalla < PANTALLAS)
    {
        printf("==========MODIFICAR PANTALLA================\n");
        printf("1. Modificar Tipo (1 para LED, 2 para LCD).\n");
        printf("2. Modificar Nombre de Pantalla.\n");
        printf("3. Modificar direccion de Pantalla.\n");
        printf("4. Modificar Precio por dia.\n");
        printf("5. Cancelar.\n");
        printf("============================================\n");
        if(utn_getInt(&opcionAuxiliar, RETRY, 1, 5, "Indique la opcion deseada: ", "Seleccion no valida. ") == 0)
            retorno = opcionAuxiliar;
    }

    return retorno;
}

void impresiones_imprimirPantalla(Pantalla* pantallas, int indice, int tabla)
{
    char idAux[7];
    char tipoAux[6];
    char precioAux[14];

    if(pantallas != NULL && indice >= 0)
    {
        if((pantallas+indice)->tipo == LED)
            strncpy(tipoAux, "LED", 4);
        else if((pantallas+indice)->tipo == LCD)
            strncpy(tipoAux, "LCD", 4);
        sprintf(idAux, "%d", (pantallas+indice)->pantallaID);
        sprintf(precioAux, "%.2f", (pantallas+indice)->precioPorDia);

        if(tabla == ENCABEZADO)
        {
            clearScreen();
            printf("+=======+==============================+======+==============================+==============+\n");
            printf("|%5s%2s|%20s%10s|%5s%1s|%20s%10s|%12s%2s|\n",
                "ID", "", "Nombre", "", "Tipo", "", "Direccion", "", "Precio Dia", "");
            printf("+=======+==============================+======+==============================+==============+\n");
        }
        printf("|%6s |%29s |%5s |%29s |%13s |\n",
            idAux, (pantallas+indice)->nombre, tipoAux, (pantallas+indice)->direccion, precioAux);
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

void impresiones_imprimirContratacion(Contratacion* contrataciones, int indiceContratacion, Pantalla* pantallas, int longitudPantallas, int tabla)
{
    char idAux[7];
    char diasAux[18];
    char pantallasAux[14];
    int indicePantalla;

    if(contrataciones != NULL && indiceContratacion >= 0 && pantallas != NULL && longitudPantallas > 0)
    {
        indicePantalla = pantalla_buscarPantallaPorId(pantallas, longitudPantallas, contrataciones[indiceContratacion].pantallaID);
        if(indicePantalla != -1)
        {
            sprintf(idAux, "%d", (contrataciones+indiceContratacion)->contratacionID);
            sprintf(diasAux, "%d", (contrataciones+indiceContratacion)->diasPublicacion);
            sprintf(pantallasAux, "%d", (pantallas+indicePantalla)->pantallaID);

            if(tabla == ENCABEZADO)
            {
                clearScreen();
                printf("+=======+==================+================+==================+==============+==============================+\n");
                printf("|%5s%2s|%9s%9s|%10s%6s|%17s%1s|%12s%2s|%20s%10s|\n",
                    "ID", "", "CUIT", "", "Video", "", "Dias Publicacion", "", "ID Pantalla", "", "Nombre Pantalla", "");
                printf("+=======+==================+================+==================+==============+==============================+\n");
            }
            printf("|%6s |%17s |%15s |%17s |%13s |%29s |\n",
                idAux, (contrataciones+indiceContratacion)->CUIT, (contrataciones+indiceContratacion)->video, diasAux, pantallasAux, (pantallas+indicePantalla)->nombre);
        }
        else
            printf("No se encuentra la pantalla a mostrar.\n");
    }
    else
        printf("Contratacion no encontrada.\n");
}

int impresiones_imprimirListaContrataciones(Contratacion* contrataciones, int longitudContrataciones, Pantalla* pantallas, int longitudPantallas)
{
    int retorno = -1;
    int contadorContrataciones;
    int i;

    if(contrataciones != NULL && longitudContrataciones > 0 && pantallas != NULL && longitudPantallas > 0)
    {
        contadorContrataciones = 0;
        for(i = 0; i < CONTRATACIONES; i++)
        {
            if(contrataciones[i].isEmpty == FULL)
            {
                contadorContrataciones++;
                if(contadorContrataciones == 1)
                    impresiones_imprimirContratacion(contrataciones, i, pantallas, longitudPantallas, ENCABEZADO);
                else
                    impresiones_imprimirContratacion(contrataciones, i, pantallas, longitudPantallas, LISTA);
            }
        }
        if(contadorContrataciones > 0)
        {
            printf("+=======+==================+================+==================+==============+==============================+\n");
            retorno = contadorContrataciones;
        }
        else
            printf("No hay contrataciones cargadas.\n");
    }

    return retorno;
}

int impresiones_imprimirContratacionesPorCuit(Contratacion* contrataciones, int longitudContrataciones, Pantalla* pantallas, int longitudPantallas, char* cuitExistente)
{
    int retorno = -1;
    char consultaCUIT[CUIT_MAX];
    int contadorContrataciones;
    int i;

    if(contrataciones != NULL && longitudContrataciones > 0 && pantallas != NULL && longitudPantallas > 0)
    {
        contadorContrataciones = 0;
        if(utn_getCUIT(consultaCUIT, CUIT_MAX, RETRY, "Ingrese el CUIT del Cliente a buscar: ", "Valor ingresado incorrecto. ") == 0)
        {
            printf("%s\n", consultaCUIT);
            for(i = 0; i < longitudContrataciones; i++)
            {
                if(contrataciones[i].isEmpty == FULL && strncmp(contrataciones[i].CUIT, consultaCUIT, CUIT_MAX) == 0)
                {
                    contadorContrataciones++;
                    if(contadorContrataciones == 1)
                        impresiones_imprimirContratacion(contrataciones, i, pantallas, longitudPantallas, ENCABEZADO);
                    else
                        impresiones_imprimirContratacion(contrataciones, i, pantallas, longitudPantallas, LISTA);
                }
            }
            if(contadorContrataciones > 0)
            {
                strncpy(cuitExistente, consultaCUIT, CUIT_MAX);
                printf("+=======+==================+================+==================+==============+==============================+\n");
                retorno = contadorContrataciones;
            }
            else
                printf("No hay contrataciones para el CUIT ingresado.\n");
        }
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
