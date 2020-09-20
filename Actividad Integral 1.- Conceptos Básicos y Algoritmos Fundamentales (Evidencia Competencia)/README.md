# Actividad Integral 1.- Conceptos Básicos y Algoritmos Fundamentales

## De manera individual crea una aplicación que:
1. Lea información de un archivo de texto que tenga formato de logs o bitacora.
2. Almacene la información en un vector.
3. Ordene la información por un tipo de atributo de la bitácora.
4. Permita al usuario realizar una búsqueda por rangos en las entradas.
5. Despliegue los registros correspondientes a las entradas.
6. Almacene en un archivo de texto el resultado del ordenamiento.

## Análisis de complejidad: 
En el programa utilizo las funciones de ordenaMerge, buscarPokemon.
- ordenaMerge: El algoritmo recorre los pasos en subgrupos, dividiendose a su vez generando una especie de arbol, por lo que su complejidad es de O(nlog(n)) para el peor de los casos.
- buscarPokemon: El algoritmo recorre los todos lo elementos dentro del archivo hasta encontrar el que es similar, por los que su complejidad es O(n) para el peor de los casos.
