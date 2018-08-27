#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"
#include "validator.h"

int main()
{
    int exerciseNumber = 0;

    printf("Coloque el numero del ejercicio: ");
    if(scanf("%d", &exerciseNumber))
    {
        switch(exerciseNumber)
        {
            case 1:
                /**< Ingresar 5 números y calcular su media. */
                exercise1();
                break;
            case 2:
                /**< Escribir el programa necesario para calcular
                 * la suma de dos números. */
                exercise2();
                break;
            case 0:
            default:
                printf("Opcion no encontrada. El programa se termina.\n");
                break;
        }
    }
    else
        printf("\nError de ingreso. El programa se termina.\n");
    
    return 0;
}