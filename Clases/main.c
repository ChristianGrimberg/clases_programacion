#include <stdio.h>
#include <stdlib.h>
#include "classroom.h"

extern int global; /**< Uso de variable global en otro source previamente declarada */

int main()
{
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif // __unix__

    //clase02(); /**< Maximos, Minimos y Promedios. */
    //clase03(); /**< Uso de funciones y parametros por referencia. */
    //clase04(); /**< Funcion generica para obtener enteros en un rango. */
    //clase05(); /**< Uso de array y busqueda de mayor. */
    //clase06(); /**< Uso de funcion publica para obtener un entero. */
    //clase06_2(); /**< Uso de array de enteros y ordenamiento por Bubble Sort. */
    //clase06_3(); /**< Uso de array de flotantes y ordenamiento por Bubble Sort. */
    //clase06_4(); /**< Uso de array de enteros y ordenamiento por Insertion Sort. */
    //clase07(); /**< Validaciones de cadena de caracteres. */
    clase08();

    return 0;
}
