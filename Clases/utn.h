#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define CHAR_ARQ_INT_64 11 /**< Character length limit in 64-bit architecture interger numbers. */
#define CHAR_ARQ_FLOAT_64 32 /**< Character length limit in 64-bit architecture float numbers. */
#define EXIT_BUFFER '\n' /**< Exit buffer of the fgets function. */
#define INIT_INT_ARRAY -50
#define INIT_FLOAT_ARRAY -100.0f

int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

#endif //UTN_H_INCLUDED
