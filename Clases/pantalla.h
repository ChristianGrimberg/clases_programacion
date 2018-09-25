#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

#include "utn.h"
#define PANTALLAS 100
#define PANTALLA_INICIAL 1
#define LED 1
#define LCD 2
#define NOMBRE_MAX 64
#define DIRECCION_MAX 128

/*! \struct Pantalla
    \brief
    Tipo de dato Pantalla.
    Consta de una Pantalla para contratacion en publicidades de video en la calle.

*/
typedef struct
{
    int pantallaID; /**< Id de Pantalla que se genera automaticamente al ingresar una nueva persona. */
    int tipo; /**< Tipo de Pantalla. */
    char nombre[NOMBRE_MAX]; /** Nombre de la pantalla. */
    char direccion[DIRECCION_MAX]; /**< Ubicacion de la pantalla. */
    float precioPorDia; /**< Precio por dia de alquiler de la pantalla. */
    int isEmpty; /**< Indicador de elemento vacio o cargado. */
}Pantalla;

int pantalla_inicializarArray(Pantalla* pantallas, int longitud);
int pantalla_buscarLugarLibre(Pantalla* pantallas, int longitud);
int pantalla_altaPantalla(Pantalla* pantallas, int indice);
int pantalla_buscarPantallaPorId(Pantalla* pantallas, int longitud, int idPantalla);
int pantalla_eliminarPantallaPorIndice(Pantalla* pantalla, int indicePantalla);
int pantalla_modificarValorPantalla(Pantalla* pantalla, int indicePantalla, int modificarValor);

#endif //PANTALLA_H_INCLUDED
