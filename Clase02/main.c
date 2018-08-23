#include <stdio.h>
#include <stdlib.h>

int main()
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

        average+=number;

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

    average=average/qtyNumbers;

    printf("\nMinimo: %d\nMaximo: %d\nPromedio: %.2f", minNumber, maxNumber, average);

    return 0;
}
