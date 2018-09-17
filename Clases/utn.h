#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
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
 *  \return Retorna 0 si obtuvo un entero dentro del rango y -1 si no es un valor valido.
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
 *  \return Retorna 0 si obtuvo un flotante dentro del rango y -1 si no es un valor valido.
 *
 */
int utn_getFloat(float* pNumero, int reintentos, float minimo, float maximo, char* mensaje, char* error);

/** \brief
 *  Funcion para obtener una cadena de caracteres por teclado con mensajes al usuario.
 *  \param pNombre char* Direccion de memoria a almacenar la cadena ingresada por teclado.
 *  \param limite int Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo la cadena correctamente y -1 si hubo un error.
 * 
 */
int utn_getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita el ingreso por teclado de un numero telefonico con codigo de area separado por un guion.
 *  \param pTelefono char* Direccion de memoria a almacenar el numero de telefono.
 *  \param cantDeNumeros int Cantidad de numeros que debera tener el numero telefonico.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un telefono correcto y -1 si no es un valor valido.
 * 
 */
int utn_getPhone(char* pTelefono, int cantDeNumeros, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita y valida el ingreso por teclado de un numero de Documento de Identidad.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param minimo int Valor minimo a ingresar.
 *  \param maximo int Valor maximo a ingresar.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un DNI dentro del rango y -1 si no es un valor valido.
 * 
 */
int utn_getDNI(int* pDNI, int reintentos, int minimo, int maximo, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita y valida el ingreso por teclado de un CUIT Argentino.
 *  \param pCuit char* Direccion de memoria al almacenar el CUIT validado.
 *  \param limite int Limite de caracteres a ingresar por el usuario.
 *  \param minimo int Valor minimo a ingresar de DNI.
 *  \param maximo int Valor maximo a ingresar de DNI.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un CUIT valido y -1 si hubo un error.
 * 
 */
int utn_getCUIT(char* pCUIT, int limite, int minimo, int maximo, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita el ingreso por teclado de una direccion email y la valida.
 *  \param pEmail char* Direccion de memoria a almacenar el email validado.
 *  \param limite int Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo el email correctamente y -1 si hubo un error.
 * 
 */
int utn_getEmail(char* pEmail, int limite, int reintentos, char* mensaje, char* mensajeError);

#endif //UTN_H_INCLUDED
