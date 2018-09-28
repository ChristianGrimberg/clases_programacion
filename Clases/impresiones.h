#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "pantalla.h"
#include "contratacion.h"
#define SALIR_PROGRAMA 11
#define ENCABEZADO 1
#define LISTA 2

int impresiones_menuPrincipal(void);
int impresiones_menuModificarPantalla(Pantalla* pantalla, int indicePantalla);
void impresiones_imprimirPantalla(Pantalla* pantallas, int indice, int tabla);
int impresiones_imprimirListaPantallas(Pantalla* pantallas, int longitud);
void impresiones_imprimirContratacion(Contratacion* contrataciones, int indiceContratacion, Pantalla* pantallas, int longitudPantallas, int tabla);
int impresiones_imprimirListaContrataciones(Contratacion* contrataciones, int longitudContrataciones, Pantalla* pantallas, int longitudPantallas);
int impresiones_imprimirContratacionesPorCuit(Contratacion* contrataciones, int longitudContrataciones, Pantalla* pantallas, int longitudPantallas, char* cuitExistente);

#endif // MENU_H_INCLUDED
