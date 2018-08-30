#include <stdio.h>
#include <stdlib.h>
#include "clases.h"
#include "funciones.h"

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
