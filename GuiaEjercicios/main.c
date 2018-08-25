#include <stdio.h>
#include <stdlib.h>
#include "validator.h"

int main()
{
    #pragma region Ejercicio 1 /**< Ingresar 5 números y calcular su media. */ 
    int inputNumber;
    int i;
    int numberQty = 5;
    int validateInput;
    float average = 0.0f;

    printf("Ejercicio 1\n");
    for(i=0; i<numberQty; i++)
    {
        printf("Ingrese el numero %d: ", i+1);
        setbuf(stdin, NULL); /**< Se limpia el buffer de entrada del teclado para los distintos SO */
        validateInput = scanf("%d", &inputNumber);
        clearBuffer();

        if(validateInput)
            average+=(float)inputNumber;
        else
        {
            printf("Error de ingreso. Se termina el programa.\n");
            break;
        }
    }

    if(numberQty>0 && validateInput==1)
    {
        average = average/(float)numberQty;
        printf("\nEl promedio de los numeros ingresados es: %.2f\n", average);
    }    
    
    #pragma endregion

    return 0;
}