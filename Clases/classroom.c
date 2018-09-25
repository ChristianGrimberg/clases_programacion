#include "classroom.h"

int global; /**< Prueba de uso de variable global en otro archivo */

void clase10(void)
{
    Pantalla pantallas[PANTALLAS];
    Contratacion contrataciones[CONTRATACIONES];
    int pantallaLibre;
    int opcionMenu;
    int opcionModificar;
    char seguirPrograma = 's';
    int contadorPantallas;
    int idParaBuscar;
    int indiceConsultado;
    char consultaEliminar;
    int i;
    
    if(pantalla_inicializarArray(pantallas, PANTALLAS) == 0 && contratacion_inicializarArray(contrataciones, CONTRATACIONES) == 0)
    {
        do
        {
            opcionMenu = impresiones_menuPrincipal();
            switch(opcionMenu)
            {
                case 1:
                    pantallaLibre = pantalla_buscarLugarLibre(pantallas, PANTALLAS);
                    if(pantallaLibre == -1)
                        printf("No hay pantalla libre.\n");
                    else
                    {
                        if(pantalla_altaPantalla(pantallas, pantallaLibre) == 0)
                            printf("Pantalla cargada en el indice %d.\n", pantallaLibre);
                        else
                            printf("Error al cargar la pantalla.\n");
                    }
                    break;
                case 2:
                    if(utn_getInt(&idParaBuscar, REINTENTOS, PANTALLA_INICIAL, PANTALLAS, "Indique el ID de Pantalla a eliminar: ", "Valor fuera de rango. ") == 0)
                    {
                        indiceConsultado = pantalla_buscarPantallaPorId(pantallas, PANTALLAS, idParaBuscar);
                        if(indiceConsultado != -1)
                        {
                            impresiones_imprimirPantalla(pantallas, indiceConsultado, ENCABEZADO);
                            printf("\n");
                            opcionModificar = impresiones_menuModificarPantalla(pantallas, indiceConsultado);
                            if(opcionModificar != -1)
                            {
                                if(pantalla_modificarValorPantalla(pantallas, indiceConsultado, opcionModificar) == 0)
                                    printf("Pantalla modificada correctamente.\n");
                                else
                                    printf("Error al modificar la pantalla.\n");
                            }
                        }
                        else
                            printf("Pantalla no encontrada.\n");
                    }
                    else
                        printf("Error al encontrar el ID de pantalla.\n");
                    break;
                case 3:
                    if(utn_getInt(&idParaBuscar, REINTENTOS, PANTALLA_INICIAL, PANTALLAS, "Indique el ID de Pantalla a eliminar: ", "Valor fuera de rango. ") == 0)
                    {
                        indiceConsultado = pantalla_buscarPantallaPorId(pantallas, PANTALLAS, idParaBuscar);
                        if(indiceConsultado != -1)
                        {
                            impresiones_imprimirPantalla(pantallas, indiceConsultado, ENCABEZADO);
                            printf("\n");
                            if(utn_getChar(&consultaEliminar, REINTENTOS, "Confirme para eliminar (S/N): ", "Valor incorrecto. ") == 0
                                && (consultaEliminar == 's' || consultaEliminar == 'S'))
                            {
                                if(pantalla_eliminarPantallaPorIndice(pantallas, indiceConsultado) == 0)
                                    printf("Pantalla eliminada %d\n", idParaBuscar);
                                else
                                    printf("Error al eliminar pantalla.\n");
                            }
                            else
                                printf("Eliminacion cancelada.\n");
                        }
                        else
                            printf("Pantalla no encontrada.\n");                      
                    }
                    else
                        printf("Error al encontrar el ID de pantalla.\n");
                    break;
                case 9:
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
                        printf("\n");
                    else if(contadorPantallas == 0)
                        printf("No hay pantallas cargadas.\n");
                    break;
                case SALIR_PROGRAMA:
                    break;
            }
            if(opcionMenu != SALIR_PROGRAMA && utn_getChar(&seguirPrograma, REINTENTOS, "Desea Continuar? (S/N): ", "Valor Incorrecto. ") == -1)
            {
                printf("Error al Salir.\n");
                break;
            }
            else if(opcionMenu == SALIR_PROGRAMA || seguirPrograma == 'n' || seguirPrograma == 'N')
                break;
        }while(seguirPrograma == 's' || seguirPrograma == 'S' || seguirPrograma == '\n');
    }
    else
        printf("Error de inicializacion de datos.\n");
}

void clase09(void)
{
    Producto productos[200];
    int indiceBuscado;
    char seguirPrograma = 's';
    int opcion;
    int contadorProductos = 0;
    int i;

    if(products_inicializarArray(productos, 200) == 0)
        printf("Productos inicializados correctamente.\n");
    else
        printf("Error de inicializacion de Productos.\n");

    do{
        opcion = products_menuOpciones();
        switch(opcion)
        {
            case 1:
                indiceBuscado = products_GetEmptyIndex(productos, 200);
                if(indiceBuscado != -1)
                {
                    if(products_cargarProducto(productos, indiceBuscado, 200) == 0)
                        printf("Producto cargado correctamente en indice %d.\n", indiceBuscado);
                    else
                        printf("Error de carga.\n");
                }
                else
                    printf("No hay productos libres a cargar.\n");
                break;
            case 2:
                for(i = 0; i < 200; i++)
                {
                    if(productos[i].isEmpty == 0)
                    {
                        products_imprimirListado(productos, i, 200);
                        contadorProductos++;
                    }
                }
                if(contadorProductos == 0)
                    printf("Listado de productos vacio.\n");
                break;
            case 3:
                break;
        }
        if(opcion != 3 && utn_getChar(&seguirPrograma, REINTENTOS, "Desea Continuar (s/n)?: ", "Valor Incorrecto. ") == -1)
        {
            printf("Error al Salir.\n");
            break;
        }
        else if(opcion == 3)
            break;
    }while(seguirPrograma == 's');
}

void clase08_2(void)
{
    Persona arrayPersonas[3];

    if(persons_inicializarArray(arrayPersonas, 3) == 0)
    {
        if(persons_altaPersonas(arrayPersonas, 3, 1) == 0)
        {
            persons_imprimirPersonas(arrayPersonas, 3);
        }
    }
}

void clase08(void)
{
    /*
    char nombres[2][5];

    nombres[0][0] = 'A';
    nombres[0][1] = 'B';
    nombres[0][2] = '\0';

    nombres[1][0] = 'C';
    nombres[1][1] = 'D';
    nombres[1][2] = '\0';

    print(&nombres[0]);
    printf("**");
    print(&nombres[1]);
    printf("\n");

    int i;
    for(i = 0; i < 5; i++)
    {
        printf("");
    }
    */
}

void clase07(void)
{
    char nombre[STRING_MAX];

    if(utn_getString(nombre, 26, 0, "Ingrese su nombre: ", "El valor es incorrecto. ", ONLY_LETTERS) == 0)
        printf("Nombre ingresado: %s\n", nombre);
}

void clase06_4()
{
    int numeros[NUMBER_QTY];
    int i;

    if(initIntArrayInt(numeros, NUMBER_QTY, INIT_INT_ARRAY) == -1)
        printf("Error al inicializar el array.\n");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array inicializado.");

    for(i = 0; i < NUMBER_QTY; i++)
    {
        if(utn_getInt(&numeros[i], 2, -90, 90, "Ingrese un numero desde -90 hasta 90: ", "Numero fuera de rango. ") == -1)
            numeros[i] = -100;
    }
    debugIntArray(numeros, NUMBER_QTY, "Array desordenado.");

    if(intInsertionSort(numeros, NUMBER_QTY, ASC) == -1)
        printf("\nError al ordenar de menor a mayor.");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array ordenado de menor a mayor.");

    if(intInsertionSort(numeros, NUMBER_QTY, DESC) == -1)
        printf("\nError al ordenar de mayor a menor.");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array ordenado de mayor a menor.");
}

void clase06_3()
{
    float decimales[NUMBER_QTY];
    int i;

    if(initFloatArrayInt(decimales, NUMBER_QTY, INIT_INT_ARRAY) == -1)
        printf("Error al inicializar el array.\n");
    else
        debugFloatArray(decimales, NUMBER_QTY, "Array inicializado.");

    for(i = 0; i < NUMBER_QTY; i++)
    {
        if(utn_getFloat(&decimales[i], 2, -1000000, 1000000, "Ingrese un decimal: ", "Decimal fuera de rango. ") == -1)
            decimales[i] = -100.0f;
    }
    debugFloatArray(decimales, NUMBER_QTY, "Array desordenado.");

    if(floatBubbleSort(decimales, NUMBER_QTY, ASC) == -1)
        printf("\nError al ordenar de menor a mayor.");
    else
        debugFloatArray(decimales, NUMBER_QTY, "Array ordenado de menor a mayor.");

    if(floatBubbleSort(decimales, NUMBER_QTY, DESC) == -1)
        printf("\nError al ordenar de mayor a menor.");
    else
        debugFloatArray(decimales, NUMBER_QTY, "Array ordenado de mayor a menor.");
}

void clase06_2()
{
    int numeros[NUMBER_QTY];
    int i;

    if(initIntArrayInt(numeros, NUMBER_QTY, INIT_INT_ARRAY) == -1)
        printf("Error al inicializar el array.\n");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array inicializado.");

    for(i = 0; i < NUMBER_QTY; i++)
    {
        if(utn_getInt(&numeros[i], 2, INT_MIN, INT_MAX, "Ingrese un numero: ", "Numero fuera de rango. ") == -1)
            numeros[i] = -100;
    }
    debugIntArray(numeros, NUMBER_QTY, "Array desordenado.");

    if(intBubbleSort(numeros, NUMBER_QTY, ASC) == -1)
        printf("\nError al ordenar de menor a mayor.");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array ordenado de menor a mayor.");

    if(intBubbleSort(numeros, NUMBER_QTY, DESC) == -1)
        printf("\nError al ordenar de mayor a menor.");
    else
        debugIntArray(numeros, NUMBER_QTY, "Array ordenado de mayor a menor.");
}

void clase06()
{
    int edad = 0;

    if(utn_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);
}

void clase05()
{
    int edades[CANTIDAD_EMPLEADOS];
    int valorMaximo;
    int i;

    if(initIntArrayInt(edades, CANTIDAD_EMPLEADOS, INITIALIZER)==-1)
        printf("\nError al inicializar el array.");
    else
        debugIntArray(edades, CANTIDAD_EMPLEADOS, "Array inicializado.");

    for(i=0; i<CANTIDAD_EMPLEADOS; i++)
    {
        /**< Conviene validar si hubo un error */
        if(utn_getInt(&edades[i], 2, 0, 200, "Edad? ", "Edad fuera de rango.")==-1)
        {
            edades[i] = -1;
        }
    }
    debugIntArray(edades, CANTIDAD_EMPLEADOS, "Array inicializado.");
    //debugIntArray(edades+2, CANTIDAD_EMPLEADOS-2, "Array inicializado."); /**< Slidezing */

    if(!getMaxIntArray(edades, CANTIDAD_EMPLEADOS, &valorMaximo))
        printf("\nEdad maxima: %d", valorMaximo);

}

void clase04()
{
    int edad = 0;
    float decimal = 0.0f;

    if(utn_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);

    if(utn_getFloat(&decimal, 3, 0.0, 100.0, "Ingrese decimal entre 0 y 100: ", "Decimal fuera de rango. ") == 0)
        printf("Decimal ingresado: %.2f\n", decimal);
}

void clase03()
{
    int edad = 0;
    int ingreso;

    ingreso = getEdad(&edad);
    if(ingreso == 0)
        printf("La edad ingresada es: %d.", edad);
    else
        printf("Error de ingreso de edad.");
}

void clase02(void)
{
    int number;
    int maxNumber;
    int minNumber;
    int qtyNumbers = 10;
    float average=0.0f;
    int i;

    for(i=0; i<qtyNumbers; i++)
    {
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &number);
        average+=(float)number; /**< First use average like accumulator */

        if(i==0)
        {
            maxNumber=number;
            minNumber=number;
        }
        else if(number>maxNumber)
            maxNumber=number;
        else if(number<minNumber)
            minNumber=number;
    }

    if(qtyNumbers!=0)
        average=average/qtyNumbers;
    printf("\nMinimo: %d\nMaximo: %d\nPromedio: %.2f\n", minNumber, maxNumber, average);
}

void pruebas(void)
{
    char telefono[15];
    if(utn_getPhone(telefono, 15, 50, "Telefono: ", "Error. ") == 0)
        printf("\n%s\n", telefono);
}

int getEdad(int* pEdad)
{
    int edadAux;
    int retorno = -1;
    int ingreso;

    do
    {
        printf("Ingrese la edad: ");
        ingreso = scanf("%d", &edadAux);
        if(ingreso == 1 && edadAux >= 0 && edadAux <= 199)
        {
            *pEdad = edadAux;
            retorno = 0;
            break;
        }
        else
            __fpurge(stdin); /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
    } while(ingreso != 1);

    return retorno;
}

int getEntero(int* pEdad, int reintentos, int minimo, int maximo, char* mensaje, char* error)
{
    int edadAux;
    int retorno = -1;
    int ingreso;

    if(maximo > minimo && reintentos > 0)
    {
        for(; reintentos > 0; reintentos--)
        {
            printf(mensaje);
            ingreso = scanf("%d", &edadAux);
            if(ingreso == 1 && edadAux >= minimo && edadAux <= maximo)
            {
                *pEdad = edadAux;
                retorno = 0;
                break;
            }
            else
            {
                /**< Funcion extendida en stdio_ext.h para limpiar el buffer de entrada */
                __fpurge(stdin);
                printf(error);
            }
        }

        if(reintentos == 0)
            printf("Cantidad de intentos superada.");
    }

    return retorno;
}
