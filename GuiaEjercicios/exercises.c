#include <stdio.h>
#include <stdlib.h>
#include "exercises.h"
#include "validator.h"
#include "operations.h"

void exercise1(void)
{
    int numberQty = 5;
    double average;
    int validateInput;

    validateInput = averageOfNumbers(numberQty, &average);    
    if(validateInput == 0)
        printf("El promedio de los numeros ingresados es: %.2lf\n", average);
}