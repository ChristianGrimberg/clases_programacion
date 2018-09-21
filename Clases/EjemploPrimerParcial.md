# Primer Parcial Laboratorio 1 año 2017
Se debe desarrollar un sistema (en ANSI C) el cual permita comercializar espacios publicitarios, los cuales estarán integrados por dos tipos de dispositivos:
1. __Pantallas LCD__ - Ubicados en paseos comerciales.
1. __Pantallas​ Gigantes Led__ - Ubicadas en la vía pública.

En el sistema existirán pantallas del _tipo_ __Led__ o __LCD__, las cuales se registrarán mediante _nombre_, _dirección_ y _precio_ de la publicidad en dicha __pantalla__ por cada _día_ de publicación. La plataforma permitirá vender a un __cliente__ la publicación de un _video_ publicitario en una __pantalla__ determinada. La porción del sistema que deberá realizarse se centrará en la venta de publicidad y consta de un menú con las siguientes opciones:
1. __Alta de pantalla__: Se solicitan al usuario los datos de la __pantalla__, para que el sistema pueda funcionar se deberá generar un _ID_ único para cada pantalla.
1. __Modificar datos de pantalla__: Se ingresa el _ID_ de la __pantalla__, permitiendo modificar sus datos.
1. __Baja de pantalla__: Se ingresa el _ID_ de la __pantalla__, se eliminará la __pantalla__ junto con todas las __contrataciones__ de publicidad para esta __pantalla__.
1. __Contratar una publicidad__:​ Se listarán todas las pantallas y se le pedirá al usuario que elija la __pantalla__ donde se quiere publicar, ingresando su _ID_. Luego se pedirán los datos asociados a la publicidad: _cuit_ del cliente, cantidad de _días_ que dura la publicación y nombre del archivo de _video_ (p.ej. Video1.avi).
1. __Modificar condiciones de publicación__:​ Se pedirá que se ingrese el _cuit_ del cliente y se listaran todas las pantallas de _video_ que el cliente tiene contratadas mostrando todos sus
campos. Luego de ingresar el _ID_ de la __pantalla__, se permitirá modificar la cantidad de _días_ contratados para la misma.
1. __Cancelar contratación__: ​ Se pedirá que se ingrese el _cuit_ del cliente y se listaran todas las pantallas de _video_ que el cliente tiene contratadas mostrando todos sus campos. Luego ingresar el _ID_ de la __pantalla__ de la cual se quiere cancelar la __contratación__.
1. __Consulta facturación__: Se deberá ingresar el _cuit_ del cliente y se deberá listar el _importe_ a pagar por cada __contratación__.
1. __Listar contrataciones__: Se deberán listar las __contrataciones__ indicando _nombre_ de la __pantalla__, nombre de _video_, cantidad de _días_ y _cuit_ de cliente.
1. __Listar pantallas__: Se deberán listar las pantallas existentes indicando todos sus campos.
1. __Informar__:
    1. Lista de cada cliente con cantidad de __contrataciones__ e _importe_ a pagar por cada una.
    1. Cliente con _importe_ más alto a facturar (si hay más de uno indicar el primero).

> __Nota 0__: El sistema soportará una capacidad máxima de 100 pantallas y 1000 contrataciones.

> __Nota 1__: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.). Los informes deberán estar en una biblioteca aparte.

> __Nota 2__: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.