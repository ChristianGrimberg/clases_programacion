#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED

#include "utn.h"

typedef struct
{
    char nombre[32];
    char descripcion[128];
    float precio;
    int isEmpty;
}Producto;

int inicializarProducto(Producto* pProductos, int cantidad);
int nuevoProducto(Producto* pProducto, int indice, int longitud);
void imprimirProducto(Producto* pProducto, int indice, int longitud);
int productoGetEmptyIndex(Producto* productos, int longitud);
int menuProductos(void);

#endif //PRODUCTS_H_INCLUDED
