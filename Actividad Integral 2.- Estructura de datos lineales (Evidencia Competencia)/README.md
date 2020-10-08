# Actividad Integral 2.- Estructura de datos lineales
Registrando Listas: el programa tiene como función obtener datos como la matricula y el nombre separados por un guión, permite agregar nuevas personas, encontrar una persona, eliminar personas y limpiar totalmente la lista, guardando todo en un archivo output.txt.
También hay un archivo llamado casos_prueba.cpp donde se puede comprobar que las funciones sirvan de manera correcta.

## Análisis de complejidad: 
En este programa uso las funciones principales para una lista que son:
 - add: va a recorrer la estructura para agregar el dato en la última posición por lo que en el peor de los casos su nivel de complejidad es O(n).
 - show: la función recorre toda la estructura imprimiendo cada dato dentro de ella, por lo que para el peor de los casos su nivel de complejidad es O(n).
 - remove: la función recorre la estructura lineal buscando el dato que se quiere eliminar, por lo que para el peor de los casos su nivel de complejidad va a ser O(n).
 - find: va a recorrer la estructura lineal buscando un valor en específico para regresar si se encontro o no el dato por lo que en el peor de los casos su nivel de complejidad es O(n).

## Glosario:
 - Listas ligadas: son estructura de datos que tiene una organización lineal y se caracteriza porque cada uno de sus elementos tiene que indicar dónde se encuentra el siguente.
 - Archivos: 


### Nota: los proyectos en este repositorio no tienen relación (a menos que se mencione) y están hechos para demostrar las competecias requeridas para esta materia.
