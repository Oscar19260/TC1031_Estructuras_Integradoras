# Actividad Integral 1.- Conceptos Básicos y Algoritmos Fundamentales

El programa consiste en una "pokedex", que ordena los pokemons de acuerdo con su nombre y busca un pokemon con su nombre desplegando todos sus datos, además permite agregar nuevos pokemons con datos como son su nombre, generación y tipo(s). El documento donde están los pokemons se llama info.txt y después de desplegar su ordenamiento se transcribe en un archivo llamado example.txt, para que sea más fácil ver su ordenamiento.
Tiene un menu con diferenctes opciones que te permite agregar un pokemon con sus atributos que son nombre, generación y tipo, ver la lista de los pokemons agregados, ordenar por nombre los pokemons de acuerdo a la tabla ascii y buscar si hay un pokemon en especifico.

## Análisis de complejidad: 
En el programa utilizo las funciones de ordenaMerge, buscarPokemon.
- ordenaMerge: El algoritmo recorre los pasos en subgrupos, dividiendose a su vez generando una especie de arbol, por lo que su complejidad es de O(nlog(n)) para el peor de los casos.
- buscarPokemon: El algoritmo recorre los todos lo elementos dentro del archivo hasta encontrar el que es similar, por los que su complejidad es O(n) para el peor de los casos.
