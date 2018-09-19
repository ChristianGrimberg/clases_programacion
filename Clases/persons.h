#ifndef PERSONS_H_INCLUDED
#define PERSONS_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define NAME_LIMITS 50 /**< Limite en la cantidad de caracteres en el nombre de una Persona. */
#define DNI_LIMITS 11 /**< Limite en la cantidad de caracteres de un DNI. */
#define PHONE_LIMITS 50 /**< Valor maximo de cantidad de caracteres para un telefono. */
#define NULL_STRING "(vacio)" /**< Valor por defecto en una cadena vacia. */
#define NULL_EDAD -1 /**< Valor por defecto en un valor de Edad. */
#define NULL_ALTURA 0.0f /**< Valor por defecto en un valor de altura. */

typedef struct
{
    char nombre[NAME_LIMITS]; /**< Nombre y Apellido de la Persona. */
    int edad; /**< Edad de la Persona. */
    char dni[DNI_LIMITS]; /**< DNI Argentino de la Persona. */
    float altura; /**< Altura en metros de una persona. */
    char telefono[PHONE_LIMITS]; /**< Telefono de una persona. */
}Persona;

/** \brief
 *  Funcion que inicializa un array de Personas con valores por defecto.
 *  \param personas Persona* Array de Personas.
 *  \param limit int Longitud del Array de Personas.
 *  \return 0 si pudo inicializar el array con los valores por defecto, -1 si hubo un error.
 * 
 */
int persons_inicializarArray(Persona* personas, int limite);

/** \brief
 *  Funcion que da el Alta de Personas en un Array.
 *  \param personas Persona* Array de Personas.
 *  \param cantidad int Cantidad de Personas a cargar.
 *  \param reintentos int Cantidad de reintentos de los valores en caso de error de carga.
 *  \return 0 si el alta fue exitosa, -1 si hubo un error.
 * 
 */
int persons_altaPersonas(Persona* personas, int cantidad, int reintentos);

/** \brief
 *  Funcion que imprime un Array de Personas.
 *  \param personas Persona* Array de Personas.
 *  \param limite int Longitud del Array de Personas.
 *  \return No retorna valores.
 * 
 */
void persons_imprimirPersonas(Persona* personas, int limite);

#endif //PERSONS_H_INCLUDED
