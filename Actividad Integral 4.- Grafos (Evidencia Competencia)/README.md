# Actividad Integral 4.- Grafos (Evidencia Competencia)
## Viajando con grafos 
Lo que se ve en el programa es el origen y destino de un recorrido, también se pueden agregar nuevos recorridos, en los que cada lugar representa un vertice y el recorrido de origen y destino o destinos representa un aristas, tambien nos imprime el grafo en forma de lista adyacente en un archivo llamado output.txt, también tiene un main casos de prueba en el que podemos comprobar el funcionamiento de las funciones.

Ejemplo de funcionamiento:
Vamos a utilizar 3 lugares:
 -EUA
 -Mexico
 -Canada
 -Brasil
 -Chile

Cada uno tiene un o más destinos por ejemplo:
 -Origen: EUA
 -Destinos: Mexico, Canada

 -Origen: Mexico
 -Destinos: Brasil, Chile

 -Origen: Canada
 -Destinos: EUA

La impresión en el .txt se va a ver como:
    +EUA -> Mexico -> Canada
    +Mexico -> Brasil -> Chile
    +Canada -> EUA

## Análisis de complejidad: 
En este programa se utilizan la siguiente funciones:
 - getVertex: esta funcion se encarga de checar si encontramos el valor que estamos buscando, por lo que para el peor de los casos debe de recorrer todo el grafo y su nivel de complejidad para el peor de los casos es O(n).
 - addVertex: esta funcion se encarga de agregar un vertice, por lo que para el peor de los casos su nivel de complejidad es O(n) ya que debe de recorrer todo el grafo.
 - addEdge: esta funcion se encarga de agregar un arista, por lo que para el peor de los casos su nivel de complejidad es O(n) ya que debe de recorrer todo el grafo.
 - AdjList: este programa imprime el grafo que tenemos, por lo que para cualquier caso debe recorrer todo el grafo y su nivel de complejidad es O(n), ya que debe recorrer todo el grafo.
 - deleteEdge: esta función se encarga de eliminar una arista seleccionada, por lo que para el peor casos es O(n).
 - deleteVertex: esta función se encarga de eliminar los vertices seleccionados, por lo que para el peor de los casos su nivel de complejidad es O(n), ya que debe recorrer todo el grafo.
 

## Glosario:
 - Grafo: conjunto de puntos y lineas. los puntos se llaman nodo o vértices de un grafos y las lineas se llaman aristas o arcos.
    + Vértice: punto o nodo de un grafo.
    + Arista: linea que une un vértice con otro del mismo grafo.

### Nota: los proyectos en este repositorio no tienen relación (a menos que se mencione) y están hechos para demostrar las competecias requeridas para esta materia.
