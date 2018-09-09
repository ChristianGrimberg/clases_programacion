#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define CHARACTERS_NUMBERS 64 /**< Character length limit for interger numbers. */
#define EXIT_BUFFER '\n' /**< Exit buffer of the fgets function. */
#define INIT_INT_ARRAY -50
#define INIT_FLOAT_ARRAY -100.0f

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

#endif //UTN_H_INCLUDED
