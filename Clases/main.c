#include "classroom.h"

extern int global; /**< Uso de variable global en otro source previamente declarada */
void pruebas(void);

int main()
{
    //pruebas(); /**< Para uso de pruebas de las funciones. */
    //clase02(); /**< Maximos, Minimos y Promedios. */
    //clase03(); /**< Uso de funciones y parametros por referencia. */
    //clase04(); /**< Funcion generica para obtener enteros en un rango. */
    //clase05(); /**< Uso de array y busqueda de mayor. */
    //clase06(); /**< Uso de funcion publica para obtener un entero. */
    //clase06_2(); /**< Uso de array de enteros y ordenamiento por Bubble Sort. */
    //clase06_3(); /**< Uso de array de flotantes y ordenamiento por Bubble Sort. */
    //clase06_4(); /**< Uso de array de enteros y ordenamiento por Insertion Sort. */
    //clase07(); /**< Validaciones de cadena de caracteres. */
    //clase08();
    //clase08_2(); /**< Uso de funciones de un array de Personas. */
    //clase09(); /**< ABM de entidad de Producto. */
    clase10(); /**< ABM y relaciones de entidades. */

    return 0;
}

void pruebas(void)
{
    char telefono[15];
    char dni[16];
    char cuit[16];
    if(utn_getDNI(dni, 16, 15, "DNI: ", "Error. ") == 0)
        printf("%s\n", dni);
    if(utn_getCUIT(cuit, 16, 1, "CUIT: ", "Error. ") == 0)
        printf("%s\n", cuit);
    if(utn_getPhone(telefono, 15, 50, "Telefono: ", "Error. ") == 0)
        printf("%s\n", telefono);
}
