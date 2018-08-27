#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "validator.h"

int averageOfNumbers(int qtyOfNumbers, double *resultValue)
{
    int returnValue = 1;
    double inputNumber;
    int i;
    int validateInput;
    double average = 0.0f;
    
    for(i=0; i<qtyOfNumbers; i++)
    {
        validateInput = requestDoubleNumber("Ingrese el numero: ", &inputNumber);
        if(validateInput==0)
            average+=inputNumber;
        else
        {
            printf("Error de ingreso. El programa se termina.\n");
            break;
        }
    }

    if(validateInput==0 && qtyOfNumbers>0)
    {
        average = average/(double)qtyOfNumbers;
        *resultValue = average;
        returnValue = 0;
    }

    return returnValue;
}