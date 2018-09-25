#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

#include "utn.h"
#define CONTRATACIONES 1000 /**< Cantidad de contrataciones que soporta el programa. */
#define CONTRATACION_INICIAL 1 /**< Inicio de contador de ID de Contratacion. */
#define CUIT_MAX 16 /**< Longitud maxima del numero de CUIT Argentino. */
#define VIDEO_MAX 32 /**< Longitud maxima del nombre y tipo del archivo de video. */

/*! \struct Contratacion
    \brief
    Tipo de dato Contratacion.
    Consta de los datos de una contratacion de publicidad para el alquiler de pantallas por ub#define CONTRATACIONES 1000icacion.

*/
typedef struct
{
    int contratacionID; /**< ID de Contratacion del sistema. */
    char CUIT[CUIT_MAX]; /**< Numero de CUIT Argentino del Cliente. */
    char video[VIDEO_MAX]; /**< Nombre y tipo del archivo de video de publicidad. */
    int diasPublicacion; /**< Cantidad de dias de Alquiler para la publicidad. */
    int pantallaID; /**< ID de Pantalla existente. */
    int isEmpty; /**< Indicador de elemento vacio o cargado. */
}Contratacion;

int contratacion_inicializarArray(Contratacion* contrataciones, int longitud);
int contratacion_buscarLugarLibre(Contratacion* contrataciones, int longitud);

#endif //CONTRATACION_H_INCLUDED