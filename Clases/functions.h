#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define CANTIDAD_EMPLEADOS 5
#define INITIALIZER -2
#define true 1
#define false 0
#define ASC 0
#define DESC 1
#define NUMBER_QTY 6

int getEdad(int*);
int getEntero(int*, int, int, int, char*, char*);
int debugIntArray(int*, int);
int debugFloatArray(float*, int);
int getMaxIntArray(int*, int, int*);
int initIntArrayInt(int*, int, int);
int initFloatArrayInt(float*, int, int);
int intBubbleSort(int*, int, int);
int floatBubbleSort(float*, int, int);

#endif //FUNCTIONS_H_INCLUDED
