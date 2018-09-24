#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "screen.h"
#define SALIR_PROGRAMA 11
#define ENCABEZADO 1
#define LISTA 2

int impresiones_menuPrincipal(void);
void impresiones_imprimirPantalla(Pantalla* pantalla, int indice, int tabla);

#endif // MENU_H_INCLUDED
