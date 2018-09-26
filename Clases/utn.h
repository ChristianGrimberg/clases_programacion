#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#define CHARACTERS_NUMBERS 64 /**< Valor maximo de caracteres numericos. */
#define STRING_MAX 4096 /**< Valor maximo en cadena de caracteres. */
#define EXIT_BUFFER '\0' /**< Valor de terminacion de una cadena de caracteres. */
#define INIT_INT_ARRAY -200 /**< Valor para inicializar el array de enteros. */
#define INIT_FLOAT_ARRAY -100.0f /**< Valor para inicializar el array de flotantes. */
#define DNI_MAX 16 /**< Valor maximo de caracteres de un DNI formateado. */
#define REINTENTOS 3 /**< Valor por defecto para reintentos. */
#define ONLY_LETTERS 1 /**< Definicion para indicar que es solo letras la cadena. */
#define ALL_CHARACTERES 0 /**< Definicion para indicar la cadena contiene caracteres de todo tipo. */
#define EMPTY 1
#define FULL 0

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

int utn_getChar(char* pCaracter, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion para obtener una cadena de caracteres por teclado con mensajes al usuario.
 *  \param pNombre char* Direccion de memoria a almacenar la cadena ingresada por teclado.
 *  \param limite int Longitud del array de caracteres a ingresar por teclado.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \param isOnlyLetters int Indicador si acepta solo letras (ONLY_LETTERS:1) o letras, numeros y caracteres especiales (ALL_CHARACTERES: 0).
 *  \return Retorna 0 si obtuvo la cadena correctamente y -1 si hubo un error.
 *
 */
int utn_getString(char* pNombre, int limite, int reintentos, char* mensaje, char* mensajeError, int isOnlyLetters);

/** \brief
 *  Funcion que solicita el ingreso por teclado de un numero telefonico con codigo de area separado por un guion.
 *  \param pTelefono char* Direccion de memoria a almacenar el numero de telefono.
 *  \param cantDeNumerosMax int Cantidad maxima de numeros que debera tener el numero telefonico.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un telefono correcto y -1 si no es un valor valido.
 *
 */
int utn_getPhone(char* pTelefono, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita y valida el ingreso de DNI Argentino formateado por ejemplo "99.999.999".
 *  \param pDNI char* Direccion de memoria a almacenar el DNI ingresado formateado.
 *  \param cantDeNumerosMax int Cantidad maxima de numeros que debera tener el numero telefonico.
 *  \param reintentos int Cantidad de reintentos al usuario.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un DNI dentro del rango y -1 si no es un valor valido.
 *
 */
int utn_getDNI(char* pDNI, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError);

/** \brief
 *  Funcion que solicita y valida el ingreso de CUIT Argentino formateado, ejemplo "99/99.999.999-9".
 *  \param pCuit char* Direccion de memoria al almacenar el CUIT validado.
 *  \param cantDeNumerosMax int Cantidad maxima de numeros que debera tener el numero telefonico.
 *  \param mensaje char* Mensaje personalizado que solicita el dato al usuario.
 *  \param error char* Mensaje personalizado en caso de error.
 *  \return Retorna 0 si obtuvo un CUIT valido y -1 si hubo un error.
 *
 */
int utn_getCUIT(char* pCUIT, int cantDeNumerosMax, int reintentos, char* mensaje, char* mensajeError);

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
