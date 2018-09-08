#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define STRING_TO_INT_64 11 /**< Caracter lenght of integers max values. */
#define BUFFER_SCAPE '\n'
#define POSITIVE 1
#define NEGATIVE -1
#define INIT_INT_ARRAY -50

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

#endif // UTN_H_INCLUDED
