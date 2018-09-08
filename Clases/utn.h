#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define CHARACTERS_INT_64 32 /**< Lenght of caracters of integer numbers to support max or min values. */
#define CHARACTERS_FLOAT_64 64
#define BUFFER_SCAPE '\n'
#define INIT_INT_ARRAY -50
#define INIT_FLOAT_ARRAY -100.0f

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

#endif //UTN_H_INCLUDED
