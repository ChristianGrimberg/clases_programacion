#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "inputs.h"
#include "clases.h"
#include "limits.h"
#include "float.h"

int global; /**< Prueba de uso de variable global en otro archivo */

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

void clase04()
{
    int edad = 0;
    float decimal = 0.0f;

    if(inputs_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);

    if(inputs_getFloat(&decimal, 3, 0.0, 100.0, "Ingrese decimal entre 0 y 100: ", "Decimal fuera de rango. ") == 0)
        printf("Decimal ingresado: %.2f\n", decimal);
}

void clase05()
{
    int edades[CANTIDAD_EMPLEADOS];
    int valorMaximo;
    int i;

    if(initIntArrayInt(edades, CANTIDAD_EMPLEADOS, INITIALIZER)==-1)
        printf("\nError al inicializar el array.");
    else
        debugIntArray(edades, CANTIDAD_EMPLEADOS);

    for(i=0; i<CANTIDAD_EMPLEADOS; i++)
    {
        /**< Conviene validar si hubo un error */
        if(inputs_getInt(&edades[i], 2, 0, 200, "Edad? ", "Edad fuera de rango.")==-1)
        {
            edades[i] = -1;
        }
    }
    debugIntArray(edades, CANTIDAD_EMPLEADOS);
    //debugIntArray(edades+2, CANTIDAD_EMPLEADOS-2); /**< Slidezing */

    if(!getMaxIntArray(edades, CANTIDAD_EMPLEADOS, &valorMaximo))
        printf("\nEdad maxima: %d", valorMaximo);

}

void clase06()
{
    int edad = 0;

    if(inputs_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);
}

void clase06_2()
{
    int numeros[NUMBER_QTY];
    int i;

    if(initIntArrayInt(numeros, NUMBER_QTY, INIT_INT_ARRAY) == -1)
        printf("Error al inicializar el array.\n");
    else
        debugIntArray(numeros, NUMBER_QTY);
    printf("\n");

    for(i = 0; i < NUMBER_QTY; i++)
    {
        if(inputs_getInt(&numeros[i], 2, INT_MIN, INT_MAX, "Ingrese un numero: ", "Numero fuera de rango. ") == -1)
        {
            numeros[i] = -100;
        }
    }
    printf("Array desordenado.");
    debugIntArray(numeros, NUMBER_QTY);

    printf("\nArray ordenado de menor a mayor.");
    if(intBubbleSort(numeros, NUMBER_QTY, ASC) == -1)
        printf("\nError al ordenar de menor a mayor.");
    else
        debugIntArray(numeros, NUMBER_QTY);

    printf("\nArray ordenado de mayor a menor.");
    if(intBubbleSort(numeros, NUMBER_QTY, DESC) == -1)
        printf("\nError al ordenar de mayor a menor.");
    else
        debugIntArray(numeros, NUMBER_QTY);    
    printf("\n");
}

void clase06_3()
{
    float decimales[NUMBER_QTY];
    int i;

    if(initFloatArrayInt(decimales, NUMBER_QTY, INIT_INT_ARRAY) == -1)
        printf("Error al inicializar el array.\n");
    else
        debugFloatArray(decimales, NUMBER_QTY);
    printf("\n");

    for(i = 0; i < NUMBER_QTY; i++)
    {
        if(inputs_getFloat(&decimales[i], 2, -1000000, 1000000, "Ingrese un decimal: ", "Decimal fuera de rango. ") == -1)
        {
            decimales[i] = -100.0f;
        }
    }
    printf("Array desordenado.");
    debugFloatArray(decimales, NUMBER_QTY);

    printf("\nArray ordenado de menor a mayor.");
    if(floatBubbleSort(decimales, NUMBER_QTY, ASC) == -1)
        printf("\nError al ordenar de menor a mayor.");
    else
        debugFloatArray(decimales, NUMBER_QTY);

    printf("\nArray ordenado de mayor a menor.");
    if(floatBubbleSort(decimales, NUMBER_QTY, DESC) == -1)
        printf("\nError al ordenar de mayor a menor.");
    else
        debugFloatArray(decimales, NUMBER_QTY);    
    printf("\n");
}
