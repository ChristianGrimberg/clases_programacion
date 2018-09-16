#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#define CHARACTERS_NUMBERS 64 /**< Character length limit for interger numbers. */
#define STRING_MAX 4096 /**< . */
#define EXIT_BUFFER '\0' /**< Exit buffer of the fgets function. */
#define INIT_INT_ARRAY -200
#define INIT_FLOAT_ARRAY -100.0f

/** \brief
 *  Funcion para obtener un entero por teclado en un rango, con mensajes al usuario.
 *  \param pNumero int* Direccion en memoria del numero a almacenar.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param minimo int Valor minimo a ingresar.
 *  \param maximo int Valor maximo a ingresar.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un entero dentro del rango y un -1 si no es un valor valido.
 *
 */
int utn_getInt(int* pNumero, int reintentos, int minimo, int maximo, char* mensaje, char* error);

/** \brief
 *  Funcion para obtener un flotante por teclado en un rango, con mensajes al usuario.
 *  \param pNumero float* Direccion en memoria del numero a almacenar.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param minimo float Valor minimo a ingresar.
 *  \param maximo float Valor maximo a ingresar.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un flotante dentro del rango y un -1 si no es un valor valido.
 *
 */
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

int utn_getCadena(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError);

#endif //UTN_H_INCLUDED
