#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED

#include "utn.h"

typedef struct
{
    int ID;
    char nombre[32];
    char descripcion[128];
    float precio;
    int isEmpty;
}Producto;

int products_inicializarArray(Producto* pProductos, int cantidad);
int products_cargarProducto(Producto* pProducto, int indice, int longitud);
void products_imprimirListado(Producto* pProducto, int indice, int longitud);
int products_GetEmptyIndex(Producto* productos, int longitud);
int products_menuOpciones(void);

#endif //PRODUCTS_H_INCLUDED
