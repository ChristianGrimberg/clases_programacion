# Primer Parcial de Laboratorio 1 (Año 2016)
Se debe desarrollar en ANSI C donde una compañía que brinda el servicio de Atención Médica de Emergencias requiere una aplicación que permita registrar cada uno de los pedidos de asistencia recibidos de manera telefónica. Cada llamada pertenece a un asociado, tiene un motivo, un estado y transcurre un tiempo en ser asignada una ambulancia.
1. __ALTA DEL ASOCIADO__: Se da de alta el abonado (ID, DNI, NOMBRE, APELLIDO, EDAD) teniendo en cuenta que el ID es auto-incrementable.
1. __MODIFICAR DATOS DEL ASOCIADO__: Se ingresará el ID de asociado, permitiendo modificar: NOMBRE y APELLIDO.
1. __BAJA DEL ASOCIADO__: Se ingresará el ID de asociado y se marcara a este como inhabilitado.
1. __NUEVA LLAMADA__: En esta opción se registran los datos (asociado y motivo) indicando que el estado es _“PENDIENTE”_.
1. __ASIGNAR AMBULANCIA__: En esta opción se registran los datos (ID_AMBULANCIA y tiempo insumido) y se indica que el estado es _"CUMPLIDO”_.
1. __INFORMAR__:
    * El nombre y apellido del asociado con mas llamados.
    * El o los motivo/s mas recurrente/s y su cantidad.
    * El motivo que en promedio mas demora en ser resuelto.

> __Nota 0__: Tanto los motivos como los estados pueden ser definidos con `#defines`
>   * Motivos (_INFARTO - ACV - GRIPE_)
>   * Estados (_PENDIENTE – CUMPLIDO_)

> __Nota 1__: Se deberá desarrollar una biblioteca `lib.c` y `lib.h` la cual contendrá las funciones (Alta, Baja, Modificar, Nueva llamada, Fin de llamada e Informar).

> __Nota 2__: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.