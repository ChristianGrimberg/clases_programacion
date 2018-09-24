#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include "utn.h"
#define LED 1
#define LCD 2
#define NOMBRE_MAX 64
#define DIRECCION_MAX 128
#define EMPTY 1
#define FULL 0

/*! \struct Pantalla
    \brief
    Tipo de dato Pantalla.

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

int screen_inicializarArray(Pantalla* pantallas, int longitud);
int screen_buscarLugarLibre(Pantalla* pantallas, int longitud);
int screen_altaPantalla(Pantalla* pantallas, int indice);
int screen_buscarPantallaPorId(Pantalla* pantallas, int longitud, int idPantalla);
int screen_eliminarPantallaPorId(Pantalla* pantalla, int idPantalla);

#endif //SCREEN_H_INCLUDED
