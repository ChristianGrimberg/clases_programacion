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

int isNumber(char value[])
{
   int returnValue = 0;
   int i = 0;

   while(value[i] != '\0')
   {
       if(value[i] < '0' || value[i] > '9')
            returnValue = 1;
       i++;
   }

   return returnValue;
}