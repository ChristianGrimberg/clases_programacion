# Temas en Clase

## Clase 1
Diferencias entre Javascript y ANSI C. Tipos de Datos. Uso de estructuras condicionales y de iteración. Teoría de Punteros. Práctica de Máximos y Mínimos y Medios. Uso de Arrays.

## Clase 2
Repaso de practica de clase anterior. Uso de acumulador y promedio con ANSI C. Casteo entre tipos de datos teniendo en cuenta el concepto de inclusión.

![Git](/img/Git-Logo.png)

Instalación y uso de Git en entorno local. Comandos básicos de Git. Subida de commits en [Github](https://github.com). Clonacion a repositorio local. Creación de archivo README.md.

## Clase 3
¿Porqué y para qué se utilizan las funciones? Uso de los prototipos de una función. Stack: Zona de memoria para alamcenar las funciones, entre otros objetos del programa. Scope/Ámbito de la función. Regla para uso de punteros:

```c
int edad = 31;
int* pEdad; /**< Variable puntero que apunta a otra variable. */
pEdad = &edad; /**< Se obtiene la direccion de memoria de la variable pEdad. */
```

# Clase 4
Funcion generica para obtener un entero en un rango determinado. Uso de bibliotecas con archivos `source` (extensión `*.c`) y archivos `header` (extensión `*.h`).

> Tips: No se incluyen los archivos `source` en los archivos ya que al agregarlo en mas de un archivo el compilador ve dos veces implementada la función. Al incluir el `header` en un archivo, le trae todos los prototipos de la función al archivo que está incluido. En caso que el `source` utilice una función implementada en si mismo, debe incluirse el `header` en él. Uso de modificador `static` para funciones privadas y variables globales privadas en el mismo `source`. Se pueden implementar una variable global privada dentro de una función, y sigue tomándose como variable global como si estuviera fuera de la función, aunque no puede invocarse en otra función.

```c
int function(void)
{
	static int i = 9;
	i++;
	return i;
}
```

# Clase 5
Uso de arrays. Intro a exploits en C en el stack con funciones y tipos de datos no controlados.

__Segmentos de códigos importantes:__

```c
int salario[5];

/**< Direccion de inicio de memoria reservada en el stack del array. */
salario;
&salario[0];

/**< Direccion de memoria de un elemento del puntero es igual al algebra de punteros. */
&salario[i];
salario + i; /**< Algebra de punteros */

/**< Validar negando el condicional es lo mismo que validarlo a cero. */
if(!utn_getInt(&edades[i], 2, 0, 200, "\nEdad", "\nEdad fuera de rango"))
if(utn_getInt(&edades[i], 2, 0, 200, "\nEdad", "\nEdad fuera de rango")==0)

/**< Un puntero a array como parametro de ambas formas */
int mostrarArray(int* pArray, int limite)
int mostrarArray(int pArray[], int limite)
```