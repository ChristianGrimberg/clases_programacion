#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

/** \brief
 * Borrado de caracteres en memoria de un ingreso no controlado de datos, realizado por el usuario hasta que presiona Enter.
 *
 * \param void No se requiere parametros.
 * \return No retorna valores.
 *
 */
void clearBuffer(void);

int isNumber(char value[]);

#endif