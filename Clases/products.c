#include <stdio.h>
#include <stdlib.h>
#include "products.h"

int products_inicializarArray(Producto* pProductos, int cantidad)
{
    int i;
    int retorno = -1;
    if(pProductos != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            (pProductos+i)->isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;

}

int nuevoProducto(Producto* pProducto, int indice, int longitud)
{
    int retorno = -1;
    Producto productoAuxiliar;

    if(pProducto != NULL && indice >= 0 && indice < longitud)
    {
        if(utn_getString(productoAuxiliar.nombre, 32, 3, "Escriba el nombre: ", "Error, intente nuevamente. ") == 0
        && utn_getString(productoAuxiliar.descripcion, 128, 3, "Escriba la Descripcion: ", "Error, intente nuevamente. ") == 0
        && utn_getFloat(&productoAuxiliar.precio, 3, 1.0f, 20000.0f, "Ingrese el precio (Maximo: 2000.00): ", "Error, valor no admitido. ") == 0)
        {
            if((pProducto+indice)->isEmpty == 1)
            {
                pProducto[indice] = productoAuxiliar;
                pProducto[indice].isEmpty = 0;
                retorno = 0;
            }
        }
    }
    return retorno;
}

void products_imprimirListado(Producto* pProducto, int indice, int longitud)
{
    if(pProducto != NULL && indice < longitud)
    {
        printf("Nombre: %s\tDescripcion: %s\tPrecio: %.2f\tEs vacio: %d.\n", pProducto[indice].nombre, pProducto[indice].descripcion, pProducto[indice].precio, pProducto[indice].isEmpty);
    }
    else
    {
        printf("Error al imprimir la persona.\n");
    }
}

int products_GetEmptyIndex(Producto* productos, int longitud)
{
    int retorno = -1;
    int i;
    
    if(productos != NULL && longitud > 0)
    {
        for(i = 0; i < longitud; i++)
        {
            if(productos[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int products_menuOpciones(void)
{
    int enteroAuxiliar;
    int retorno=-1;

    system("clear");
    printf("==========MENU DE OPCIONES==========\n");
    printf("1. Cargar un Producto.\n");
    printf("2. Imprimir lista de Productos.\n");
    printf("====================================\n");
    if(utn_getInt(&enteroAuxiliar,3,1,2,"Indique la Opcion deseada: ","Seleccion no valida. ") == 0)
        retorno=enteroAuxiliar;

    return retorno;
}
