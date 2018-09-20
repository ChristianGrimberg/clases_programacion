#include <stdio.h>
#include <stdlib.h>
#include "products.h"

//static Producto productoVacio()

int inicializarProducto(Producto* pProductos, int cantidad)
{
    int i;
    int retorno=-1;
    if(pProductos!=NULL && cantidad>0)
    {
        for(i=0;i<cantidad;i++)
        {
            (pProductos+i)->isEmpty=1;
        }
        retorno=0;
    }
    return retorno;

}

int nuevoProducto(Producto* pProducto, int indice, int longitud)
{
    int retorno=-1;
    Producto productoAuxiliar;

    if(pProducto!=NULL && indice>=0 && indice<longitud)
    {
        if(utn_getString(productoAuxiliar.nombre, 32, 3, "escriba un nombre : ", "Error, intente nuevamente ") == 0
        && utn_getString(productoAuxiliar.descripcion, 128, 3, " escriba una descripcion : ", "Error intente nuevamente ") == 0
        && utn_getFloat(&productoAuxiliar.precio, 3, 1.0, 20000.0, "ingrese el precio : ", " Error escriba bien ") == 0)
        {

            if((pProducto+indice)->isEmpty==1)
            {
                pProducto[indice]=productoAuxiliar;
                pProducto[indice].isEmpty=0;
                retorno = 0;

            }

        }
    }
    return retorno;
}

void imprimirProducto(Producto* pProducto, int indice, int longitud)
{
    if(pProducto!=NULL && indice<longitud)
    {
        printf("Nombre : %s \n descripcion : %s \n precio : %.2f\nvacio : %d\n", pProducto[indice].nombre,pProducto[indice].descripcion, pProducto[indice].precio, pProducto[indice].isEmpty);
    }
    else
    {
        printf("Error al imprimir la persona \n");
    }
}

int productoGetEmptyIndex(Producto* productos, int longitud)
{
    int retorno=-1;
    int i;
    if(productos!=NULL && longitud>0)
    {
        for(i=0;i<longitud;i++)
        {
            if(productos[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int menuProductos(void)
{
    int enteroAuxiliar;
    int retorno=-1;

    system("clear");
    printf(" MENU DE OPCIONES\n ");
    printf(" 1. Cargar un Producto\n ");
    printf(" 2. Imprimir lista de Productos\n ");
    if(utn_getInt(&enteroAuxiliar,3,1,2," Indique la Opcion deseada : ","Seleccion no valida. ")==0)
    {
        retorno=enteroAuxiliar;
    }


    return retorno;
}
