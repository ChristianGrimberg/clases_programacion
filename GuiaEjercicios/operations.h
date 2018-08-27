#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

void clearScreen(void);

/** \brief
 *  Funcion que acumula una cantidad determinada de numeros ingresados.
 *  \param qtyOfNumbers int Cantidad de numeros que va a solicitar la funcion.
 *  \return Retorna 0 si pudo acumular correctamente y 1 si hubo un error.
 * 
 */
int acumulateNumbers(int qtyOfNumbers, double *resultValue);

#endif //OPERATIONS_H_INCLUDED