#ifndef ARRAYFUNCTIONS_H_INCLUDED
#define ARRAYFUNCTIONS_H_INCLUDED

#define CANTIDAD_EMPLEADOS 5
#define INITIALIZER -2
#define true 1
#define false 0
#define ASC 0
#define DESC 1
#define NUMBER_QTY 6

/** \brief
 *  Funcion que muestra el Debug de los valores en pantalla del array de enteros.
 *  \param pArray int* Array de enteros.
 *  \param limit int Longitud del array.
 *  \param message char* Mensaje de cabecera a imprimir.
 *  \return No retorna valores.
 * 
 */
void debugIntArray(int* pArray, int limit, char* message);

/** \brief
 *  Funcion que muestra el Debug de los valores en pantalla del array de flotantes.
 *  \param pArray int* Array de flotantes.
 *  \param limit int Longitud del array.
 *  \param message char* Mensaje de cabecera a imprimir.
 *  \return No retorna valores.
 * 
 */
void debugFloatArray(float* pArray, int limit, char* message);

/** \brief
 *  Funcion que obtiene el valor maximo en un array de enteros.
 *  \param pArray int* Array de enteros a recorrer.
 *  \param limit int Longitud del array.
 *  \param pMaxInt int* Direccion de memoria a almacenar el valor maximo obtenido.
 *  \return 0 si pudo obtener un maximo, -1 si el array no tiene valores y -2 si el array solo esta inicializado.
 * 
 */
int getMaxIntArray(int* pArray, int limit, int* pMaxInt);

/** \brief
 *  Funcion que inicializa con un valor un array de enteros.
 *  \param pArray int* Array de enteros a inicializar.
 *  \param limit int Logitud del array.
 *  \param value int Valor a colocar en cada indice del array.
 *  \param 0 si pudo inicializar el array, -1 si no es posible inicializarlo.
 * 
 */
int initIntArrayInt(int* pArray, int limit, int value);

/** \brief
 *  Funcion que inicializa con un valor un array de flotantes.
 *  \param pArray float* Array de flotantes a inicializar.
 *  \param limit int Logitud del array.
 *  \param value int Valor a colocar en cada indice del array.
 *  \param 0 si pudo inicializar el array, -1 si no es posible inicializarlo.
 * 
 */
int initFloatArrayInt(float* pArray, int limit, int value);

/** \brief
 *  Funcion que realiza el ordenamiento de burbuja en un array de enteros.
 *  \param pArray int* Array de enteros a ordenar.
 *  \param limit int Longitud del array.
 *  \param ascOrDesc int Indicador de ordenamiento Ascendente o Descendente.
 *  \return 0 si pudo ordenar el array, -1 si no es posible.
 * 
 */
int intBubbleSort(int* pArray, int limit, int ascOrDesc);

/** \brief
 *  Funcion que realiza el ordenamiento de burbuja en un array de flotantes.
 *  \param pArray int* Array de flotantes a ordenar.
 *  \param limit int Longitud del array.
 *  \param ascOrDesc int Indicador de ordenamiento Ascendente o Descendente.
 *  \return 0 si pudo ordenar el array, -1 si no es posible.
 * 
 */
int floatBubbleSort(float* pArray, int limit, int ascOrDesc);

/** \brief
 *  Funcion que realiza el ordenamiento de insercion en un array de enteros.
 *  \param pArray int* Array de enteros a ordenar.
 *  \param limit int Longitud del array.
 *  \param ascOrDesc int Indicador de ordenamiento Ascendente o Descendente.
 *  \return 0 si pudo ordenar el array, -1 si no es posible.
 * 
 */
int intInsertionSort(int* pArray, int limit, int ascOrDesc);

#endif //ARRAYFUNCTIONS_H_INCLUDED
