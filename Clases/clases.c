#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#include "clases.h"
#define CANTIDAD_EMPLEADOS 5
#define INICIALIZADOR -2
#define true 1
#define false 0

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

    if(utn_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);

    if(utn_getFloat(&decimal, 3, 0.0, 100.0, "Ingrese decimal entre 0 y 100: ", "Decimal fuera de rango. ") == 0)
        printf("Decimal ingresado: %.2f\n", decimal);
}

void clase05()
{
    int edades[CANTIDAD_EMPLEADOS];
    int valorMaximo;
    int i;

    if(initArray(edades, CANTIDAD_EMPLEADOS, INICIALIZADOR)==-1)
        printf("\nError al inicializar el array.");
    else
        mostrarArray(edades, CANTIDAD_EMPLEADOS);

    for(i=0; i<CANTIDAD_EMPLEADOS; i++)
    {
        /**< Conviene validar si hubo un error */
        if(utn_getInt(&edades[i], 2, 0, 200, "\nEdad? ", "\nEdad fuera de rango.")==-1)
        {
            edades[i] = -1;
        }
    }
    mostrarArray(edades, CANTIDAD_EMPLEADOS);
    //mostrarArray(edades+2, CANTIDAD_EMPLEADOS-2); /**< Slidezing */

    if(!calcularMaximoArray(edades, CANTIDAD_EMPLEADOS, &valorMaximo))
        printf("\nEdad maxima: %d", valorMaximo);

}

void clase06()
{
    int edad = 0;

    if(utn_getInt(&edad, 3, 0, 199, "Ingrese la edad: ", "Edad fuera de rango: ") == 0)
        printf("Edad ingresada: %d\n", edad);
}

int mostrarArray(int* pArray, int limite)
{
    int retorno = 0;
    int i;

    for(i=0; i<limite; i++)
    {
        printf("\nIndex: %d, Value: %d, Add: %p.", i, pArray[i], pArray+i);
    }

    return retorno;
}

int calcularMaximoArray(int* pArray, int limite, int* pMaximo)
{
    int retorno = -1;
    int maximo;
    int flagPrimerMaximo = false;
    int i;

    if(pArray!=NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            if(pArray[i]!=INICIALIZADOR)
            {

                if(flagPrimerMaximo == true && pArray[i]>maximo)
                    maximo = pArray[i];
                else if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
            }
        }

        if(flagPrimerMaximo == false)
        {
            retorno = -2;
        }
        else if(flagPrimerMaximo == true)
        {
            retorno = 0;
            *pMaximo = maximo;
        }
    }

    return retorno;
}

int initArray(int* pArray, int limite, int valor)
{
    int retorno = -1;
    int i;

    if(pArray!=NULL && limite>0)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            pArray[i] = valor;
            //*(pArray + 1) = valor;
        }
    }

    return retorno;
}
