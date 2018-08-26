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
 *  Funcion que determina si una cadena de caracteres puede ser numerica o decimal.
 * 
 *  \param value[] char Cadena de caracteres a evaluar
 *  \return Retorna -1 si no es numerico, 0 si es entero y 1 si es decimal. 
 * 
 */
int isIntegerOrDoubleNumber(char value[]);

#endif