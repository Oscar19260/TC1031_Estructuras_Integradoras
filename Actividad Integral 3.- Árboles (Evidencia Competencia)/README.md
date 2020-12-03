# Actividad Integral 3.- Árboles (Evidencia Competencia)
### Registro de Correos
Este programa tiene como fin meter un registro de correos en un árbol de busqueda binaria para que se pueda manejar de manera más facil, además de que nos permitirá disminuir el tiempo de busquedas. Obteniendo datos de un archivo input.txt y sacar los datos actualizados en un output.txt; por ejemplo si se pretende buscar un correo en específico se va a mover a la izquierda o a la derecha dependiendo su localización en el árbol.

El programa tiene casos de prueba en "main_Casos_Prueba.cpp" donde se puede comprobar las funciones que utilizamos en bst.h

Ejemplo:

           [a01705566]
            |      |
    [a01705564]  [a01705567]

## Análisis de complejidad: 
En este programa uso las funciones principales para un árbol que son:
 - Add: es una función que añade un correo moviendose a través de un árbol desde su raíz hasta el lugar el que pertenezca, es una función muy comun en los árboles de busqueda binarios; por lo que para el peor de los casos llega a ser O(n).
 - Inorder: es una función que se encarga de imprimir los datos que tengamos en un archivo de texto o los que vayan añadiendo; por lo que para el peor de los casos su complejidad es O(n).
 - Find: esta función se encarga de moverse por el árbol, por lo que determina si se encuentra o no un dato devolviendo un 1 si se encontro o un 0 en el caso contrario; por lo que para el peor de los casos llega a ser O(n).
 - Remove: esta función se encarga de eliminar un elemento en concreto por lo que debe dirigirse a ese nodo, eliminarlo y recolocar el árbol; por lo que su nivel de complejidad en el peor de los casos puede alcanzar un O(n).
 - Clear: esta funcion elimina todo el árbol e igualar su raíz a nulo, por lo que para el peor de los casos su nivel de complejidad es O(n).


## Glosario:
 - BST: tipo de árbol que permite almacenar información ordenada.
    + Cada nodo del árbol debe tener de 0 a 2 hijos.
    + Los descendientes izquierdos deben tener un valor menor al padre.
    + Los descendientes derechos deben tener un valor mayor al padre.
    
## Referencias
 - GeeksforGeeks. (2020). Binary Search Tree. Retrieved 3 December 2020, from https://www.geeksforgeeks.org/binary-search-tree-data-structure/
 - Lcm. (2020). 4.4 Binary Search Tree. Retrieved 3 December 2020, from https://cutt.ly/GhvzBrk

### Nota: los proyectos en este repositorio no tienen relación (a menos que se mencione) y están hechos para demostrar las competecias requeridas para esta materia.
