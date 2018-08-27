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

    validateInput = acumulateNumbers(numberQty, &average);    
    if(validateInput == 0)
    {
        average = average/(double)numberQty;
        printf("El promedio de los numeros ingresados es: %.2lf\n", average);
    }
}

void exercise2(void)
{
    int numberQty = 2;
    double sumNumbers;
    int validateInput;

    validateInput = acumulateNumbers(numberQty, &sumNumbers);
    if(validateInput == 0)
        printf("La suma de los numeros ingresados es: %.2lf\n", sumNumbers);
}

void exercise3(void)
{
    
}