# Primer Parcial de Laboratorio 1 (Año 2018)
Desarrollar en ANSI C para una empresa que necesita administrar el stock de sus productos, y para ello se deberá realizar un programa de acuerdo a lo siguiente:

__Proveedores:__
* Código de proveedor (autoincremental)
* Descripción (máximo 50 caracteres) __Validar__

__Productos:__
* Código de producto (autoincremental)
* Descripción (máximo 50 caracteres) __Validar__
* Importe __Validar__
* Cantidad __Validar__

## 1. ALTAS
No es necesario el ingreso de todos los productos.

## 2. MODIFICAR
Se ingresará el Código de Producto, permitiendo en un submenú modificar:
* Descripción
* Importe
* Cantidad

## 3. BAJA
Se ingresará el Código de Producto y se realizará una baja lógica.

## 4. INFORMAR
1. __Total__ y __promedio__ de los importes, y __cuántos__ productos superan ese promedio.
1. __Total__ y __promedio__ de los importes, y __cuántos__ productos no superan ese promedio.
1. La cantidad de productos cuyo stock es menor o igual a 10.
1. La cantidad de productos cuyo stock es mayor a 10.

## 5. LISTAR
1. Realizar un __solo listado__ de los productos ordenados por los siguientes criterios:
    * Importe (descendentemente)
    * Descripción (ascendentemente)
1. Todos los productos que en cantidad son menor o igual a10.
1. Todos los productos que en cantidad son mayor a 10.
1. Todos los productos que superan el promedio de los importes.
1. Todos los productos que no superan el promedio de los importes.
1. Todos los proveedores cuya cantidad de producto es menor o igual a 10.
1. Todos los productos provistos por cada proveedor.
1. Todos los productos provistos por un proveedor determinado.
1. El proveedor que provee más productos, mostrando los productos.
1. El proveedor que provee menos productos, mostrando los productos.
1. El proveedor que provee el producto más caro, mostrando ese producto.
1. El proveedor que provee el producto más barato, mostrando ese producto.

### NOTAS:
> Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las fuciones Alta, Baja, Modificar y Listar.

> Los informes deberán estar en una biblioteca aparte.

> El menú de opciones y las validaciones deberán estar en una biblioteca aparte.

> Tener en cuenta que no se podrá ingresar a los casos 2, 3, 4 y 5; sin antes haber realizado la carga de algún producto (utilizar bandera).

> El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.
