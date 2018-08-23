#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    int maxNumber;
    int minNumber;
    int qtyNumbers = 10;
    int i;

    for(i=0; i<qtyNumbers; i++)
    {
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &number);

        if(i==0)
        {
            maxNumber=number;
            minNumber=number;
        }
        else
        {
            if(number>maxNumber)
            {
                maxNumber=number;
            }
            else if(number<minNumber)
            {
                minNumber=number;
            }
        }
    }

    printf("\nMinimo: %d\nMaximo: %d", minNumber, maxNumber);

    return 0;
}
