#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

/** \brief
 *  Borrado de caracteres en memoria de un ingreso no controlado de datos hasta que se presiona Enter.
 *
 *  \param void No se requiere parametros.
 *  \return No retorna valores.
 *
 */
void clearBuffer(void);

/** \brief
 *  Funcion que solicita al usuario el ingreso de un numero entero y con decimales tambien.
 * 
 *  \param message[] char Mensaje a mostrar en pantalla.
 *  \param *resultValue double Referencia para almacenar el valor ingresado.
 *  \return Retorna 0 si pudo obtener un valor numerico, de lo contrario retorna 1.
 * 
 */
int requestDoubleNumber(char message[], double *resultValue);

/** \brief
 *  Funcion que solicita al usuario el ingreso de un numero entero.
 * 
 *  \param message[] char Mensaje a mostrar en pantalla.
 *  \param *resultValue double Referencia para almacenar el valor ingresado.
 *  \return Retorna 0 si pudo obtener un valor numerico, de lo contrario retorna 1.
 * 
 */
int requestIntNumber(char message[], int *resultValue);

/** \brief
 *  Funcion que determina si una cadena de caracteres puede ser numerica o decimal.
 * 
 *  \param value[] char Cadena de caracteres a evaluar
 *  \return Retorna -1 si no es numerico, 0 si es entero y 1 si es decimal. 
 * 
 */
int isIntegerOrDecimalNumber(char value[]);

#endif