# Actividad Integral 6.- Una nueva estructura (Evidencia Competencia)
### Información de alumnos
En este proyecto se recolecta información y se ordena de acuerdo a strings, lo que obtiene es la matricula, un nombre, un apellido y el correo del alumno, este programa permite buscar, ordenar y mostrar la lista de alumnos original, una vez ordenada la lista, va a mostrarla siempre ordenada, el registro se guarda en un archivo output.txt y se obtienen los datos de un input.txt, igualmente tiene un main de casos de prueba en el que se revisa la eficiencia del algoritmo de ordenamiento para implementar.

## Análisis de complejidad:
En este entragable se entrega un algoritmo de ordenamiento llamado pancake sort que tiene una complejidad de tiempo de O(n^2) y de espacio de O(1).
Para realizar este algoritmo se utilizaron las funciones:
 - flip: función que intercambia la posición de una pila de panqueques, por lo que si nivel de complejidad para el peor de los casos es O(n).
 - max: que se encarga de obtener el valor maximo para saber cuantas veces tiene que hacer un flip, su nivel de complejidad en el peor de los casos es mayor a O(n), pero para menciones practicas se va a tomar como O(n).
 - pancake: en esta función se hace el ordenamiento de un vector, por lo que su nivel de complejidad para el peor de los casos es O(n^2). 


## Explicación:
 - Pancake Sortings: es un algoritmo de ordenamiento para el problema matemático de ordenar una pila desordenada de panqueques por orden de tamaño utilizando una "espátula" que puede ser insertada en cualquier punto en la pila para voltear todos los panqueques encima de ella.

  El ordenamiento de panqueques también aparece en redes de procesamiento paralelo, en el que puede proporcionar un algoritmo de encaminamiento eficaz entre procesadores. El problema es notable por ser el tema del único artículo matemático conocido escrito por el fundador de Microsoft, Bill Gates, titulado "Cotas para el ordenamiento por inversión de prefijos", publicado en 1979 donde se describe un algoritmo eficaz para el problema de ordenamiento de panqueques en el que se nos presenta la formula Tn <= (5n + 5)/3, pero la limitante de este algoritmo es que con el uso de ordenadores, sólo se han logrado calcular número panqueque. En el 2015 se descubrio que era un problema de complejidad NP Completo. Por su complejidad en cuanto espacio sus aplicaciones se puede aplicar en la electrónica.

  Por ejemplo:
+ Si tenemos un arreglo de 3 número vamos a tener 6 casos en el paqueque:
 - Caso 1: los datos estan ordenados [1, 2, 3].
 - Caso 2: los datos estan desordenados de la siguente manera [2, 1, 3] por lo que solo hay que hacer un flip [1, 2, 3].
 - Caso 3: tenemos los datos volteado por lo que sólo hay que dar un flip [3, 2, 1] se voltea [1, 2, 3].
 - Caso 4: los datos estan desordenados de la siguente manera [2, 3, 1] por lo que hay que hacer 2 flips [3, 2, 1] y después a [1, 2, 3].
 - Caso 5: los datos estan desordenados de la siguente manera [3, 1, 2] por lo que hay que hacer 2 flips [2, 1, 3] y después a [1, 2, 3].
 - Caso 6: para el último caso es [1, 3, 2] por lo que se deben hacer 3 cambios [3, 1, 2] depués [2, 1, 3] y finalmente [1, 2, 3].


 ![alt tag](https://github.com/Oscar19260/TC1031_Estructuras_Integradoras/blob/master/Actividad%20Integral%206.-%20Una%20nueva%20estructura%20(Evidencia%20Competencia)/Pancake_sort_operation.png)
 
                                                              ( ^-^)_旦” 

## Referencias
 - Riptutorial. (2020). algorithm - Pancake Sort Basic Information | algorithm Tutorial. Retrieved 3 December 2020, from https://riptutorial.com/algorithm/example/24754/pancake-sort-basic-information
 - Wikipedia. (2020). Pancake sorting. Retrieved 3 December 2020, from https://en.wikipedia.org/wiki/Pancake_sorting
 - CMU. (2020). Pancake Sorting Problem. Retrieved 3 December 2020, from http://www.cs.cmu.edu/~venkatg/teaching/15252-sp20/notes/pancakes-notes.pdf
