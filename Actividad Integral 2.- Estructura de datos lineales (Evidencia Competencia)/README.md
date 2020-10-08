# Actividad Integral 2.- Estructura de datos lineales
Registrando Listas: el programa tiene como función obtener datos como la matricula y el nombre separados por un guión, permite agregar nuevas personas, leer los elementos de un archivo llamado input.txt, encontrar una persona, eliminar personas y limpiar totalmente la lista, hasta que salimos del programa se crea un nuevo archivo con los datos actualizados y se guarda en output.txt, usa la libreria list.h que permite hace las operaciones necesarias para que tenga un buen funcionamiento.
También hay un archivo llamado casos_prueba.cpp donde se puede comprobar que las funciones sirvan de manera correcta.

## Ejemplo de ejecución
--------Bienvenido--------
- Agregar Persona   //Si seleccionamos agregar se ingresa una nueva persona (matricula-nombre).
- Mostrar lista     //Si seleccionamos mostrar se verán los elementos del archivo input.txt, además de los que se hayan agregado.
- Buscar Persona    //Si seleccionamos buscar se ingresa la persona (matricula-nombre) en caso de que no se encuentre regresara un mensaje junto con un "-1".
- Remover Persona   //Si seleccionamos remover se ingresa la persona (matricula-nombre) y se va a eliminar.    
- Limpiar lista     //Si seleccionamos limpiar la lista se queda vacia.
- Exit              //Si seleccionamos exit, se termina el programa y nuestro nuevo registro se encontrara en el archivo output.txt



## Análisis de complejidad: 
En este programa uso las funciones principales para una lista que son:
 - add: va a recorrer la estructura para agregar el dato en la última posición por lo que en el peor de los casos su nivel de complejidad es O(n).
 - show: la función recorre toda la estructura imprimiendo cada dato dentro de ella, por lo que para el peor de los casos su nivel de complejidad es O(n).
 - remove: la función recorre la estructura lineal buscando el dato que se quiere eliminar, por lo que para el peor de los casos su nivel de complejidad va a ser O(n).
 - find: va a recorrer la estructura lineal buscando un valor en específico para regresar si se encontro o no el dato por lo que en el peor de los casos su nivel de complejidad es O(n).

## Glosario:
 - Listas ligadas: son estructura de datos que tiene una organización lineal y se caracteriza porque cada uno de sus elementos tiene que indicar dónde se encuentra el siguente.
 - Archivos: es un conjunto de bytes que son almacenados en un dispositivo. Un archivo es identificado por un nombre y la descripción de la carpeta o directorio que lo contiene. 


### Nota: los proyectos en este repositorio no tienen relación (a menos que se mencione) y están hechos para demostrar las competecias requeridas para esta materia.
