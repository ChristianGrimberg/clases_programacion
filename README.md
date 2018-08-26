# Prácticas en ANSI C del curso de Programación y Laboratorio 1 de UTN
El presente repositorio se encuentra segmentado por dos proyectos compatibles con los IDE [__Code::Blocks__](http://www.codeblocks.org/) y [__Visual Studio Code__](https://code.visualstudio.com/). Ambos proyectos son las prácticas realizadas en las [Clases](/Clases/README.md) de la división 1E del segundo cuatrimestre del año 2018, además de la [Guía de Ejercicios](/GuiaEjercicios/README.md) entregadas en el [Campus Virtual de la UTN FRA](https://www.utnfravirtual.org.ar/).
# Descargar el repositorio en el entorno local
Para trabajar con el código del repositorio de manera local es recomendable utilizar el versionador de código [__Git__](https://git-scm.com/). Luego de la instalación de esta herramienta, será necesario abrir una ventana del Terminal, y ubicarse en directorio donde se guardará el código para descargarlo. A continuación se debe ejecutar los siguientes comandos:
```git
git clone https://github.com/ChristianGrimberg/clases_programacion.git
cd clases_programacion/
```
# Utilizar el editor de código de su preferencia
El repositorio es implementado mediante el uso de los editores de Code::Blocks y Visual Studio IDE, aunque podría utilizar otro de su preferencia teniendo a su cargo la tarea de parametrización. En el caso que elija por alguno de los editores mencionados, deberá tener en cuenta varios factores para contar con el espacio de trabajo configurado y listo para su uso.
## Prácticas en Code::Blocks IDE
![CodeBlocks](/img/codeblocks.png)

Para trabajar con los proyectos en el IDE de Code::Blocks se deben abrir los archivos de extensión _*.cbp_ ubicados en las carpetas de proyecto [Clases](/Clases) y [GuiaEjercicios](/GuiaEjercicios). Ambos proyectos se encuentran listos para compilar y depurar.
## Prácticas en Visual Studio Code
![VsCode](/img/vscode.png)
Para trabajar con los proyectos en el IDE de Visual Studio Code se debe abrir la carpeta raíz del repositorio, ya que el editor no opera con proyectos, sino directamente con los archivos ubicados por carpeta. Para compilar ambos proyectos se utiliza el atajo de teclado `Ctrl` + `Shift` + `B` invocando las tareas de compilación. Para el caso de los ejercicios en clase se utiliza la tarea _Classroom Compiler_ y para la los ejercicios de la guía se utiliza la tarea _Exercises Compiler_.

![Vscode tasks](/img/tasks-vscode.png)

Para la ejecución de los programas compilados desde el Terminal de Visual Studio Code se debe ejecutar lo siguiente:

__Programa Clases:__
```bash
./Clases/bin/Debug/Clases
```
__Programa Guía de Ejercicios:__
```bash
./GuiaEjercicios/bin/Debug/GuiaEjercicios
```
> Todas las prácticas fueron realizadas desde el sistema operativo __GNU/Linux__ bajo distribución basada en __Debian__.