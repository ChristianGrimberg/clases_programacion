#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"
#include "validator.h"
#include "operations.h"

void exercise1_1(void)
{
    int numberQty = 5;
    double average;

    printf("Ejercicio 1\n");
    if(averageOfNumbers(numberQty, &average) == 0)
        printf("\nEl promedio de los numeros ingresados es: %.2lf\n", average);
}