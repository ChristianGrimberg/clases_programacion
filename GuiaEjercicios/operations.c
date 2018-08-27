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
        printf("Ingrese el numero %d: ", i+1);
        setbuf(stdin, NULL); /**< Se limpia el buffer de entrada del teclado para los distintos SO */
        validateInput = scanf("%lf", &inputNumber);
        clearBuffer();

        if(validateInput==1)
            average+=inputNumber;
        else
        {
            printf("Error de ingreso. El programa se termina.\n");
            break;
        }
    }

    if(validateInput==1 && qtyOfNumbers>0)
    {
        average = average/(double)qtyOfNumbers;
        *resultValue = average;
        returnValue = 0;
    }

    return returnValue;
}