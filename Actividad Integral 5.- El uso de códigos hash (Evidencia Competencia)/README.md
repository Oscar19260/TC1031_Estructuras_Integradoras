# Actividad Integral 5.- El uso de códigos hash (Evidencia Competencia)
### Registro de residentes
En este proyecto se guarda en una estructura hash una serie de alumnos que tiene una matricula como llave y un nip como valor para entrar a residencias. En el programa se despliegan las funciones para agregar al registro un nuevo residente con matricula y nip (preferentemente de 4 digitos), mostrar la lista de residentes registrados, una opción que te permite obtener el nip de un estudiante y leer un archivo input.txt para no tener que hacer el cada registro; al finalizar el programa se escribe en un archivo llamado output.txt los datos para su obtención inmediata. Se utiliza 2 archivos .h (info.h y hash.h).
Posee un main_Casos_Prueba.cpp para revisar que las funciones sirvan correctamente.

## Análisis de complejidad: 
En este programa se utilizan la siguiente funciones:
    - put (linear): función que se encarga de insertar elementos a una tabla de hash con prueba lineal, se selecciono por su facil implementación, tener el mejor performance con el caché, teniendo una complejidad para el peor y la mayoria de los casos de O(1), sin embargo en ocasiones llega a O(n).
    - get: función que se encarga de obtiener el valor de una llave en especifico, por lo que para el peor de los casos su nivel de complejidad es O(n).

## Glosario:
    - Tabla hash: permite el acceso de elementos almacenados a partir de una llave generada.
    - Función hash: sirve para obtener un número que identifica la posición donde la tabla hash localiza el valor deseado.

### Nota: los proyectos en este repositorio no tienen relación (a menos que se mencione) y están hechos para demostrar las competecias requeridas para esta materia.
