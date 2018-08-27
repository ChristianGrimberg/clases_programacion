#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "validator.h"

void clearScreen(void)
{
    #ifdef __unix__
        system("clear"); /**< Borrar pantalla en SO basados en Unix */
    #else
        system("cls"); /**< Borrar pantalla en Windows */
    #endif // __unix__
}

int acumulateNumbers(int qtyOfNumbers, double *resultValue)
{
    int returnValue = 1;
    double inputNumber;
    int i;
    int validateInput = 1;
    double average = 0.0f;
    
    for(i=0; i<qtyOfNumbers; i++)
    {
        validateInput = requestDoubleNumber("Ingrese el numero: ", &inputNumber);
        average+=inputNumber;
    }

    if(validateInput==0 && qtyOfNumbers>0)
    {
        *resultValue = average;
        returnValue = 0;
    }

    return returnValue;
}