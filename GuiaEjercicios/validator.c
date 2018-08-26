#include <stdio.h>
#include <stdlib.h>
#include "validator.h"

void clearBuffer(void)
{
    char memoryBuffer = '\n';    
    while (getchar() != memoryBuffer)
    {
        /**< Without implementation to clean memory */
    }
}

int isIntegerOrDoubleNumber(char value[])
{
    int numberType = -1;
    int i = 0;
    int coma = 0;

    while(value[i] != (int)'\0')
    {
        if(value[i] >= (int)'0' && value[i] <= (int)'9')
            numberType = 0;
        else if(value[i]=='.')
            coma++;
        else
        {
            numberType = -1;
            break;
        }        
        i++;
    }

    if(numberType==0 && coma==1)
        numberType = 1;
    else if(numberType==0 && coma>1)
        numberType = -1;    

    return numberType;
}