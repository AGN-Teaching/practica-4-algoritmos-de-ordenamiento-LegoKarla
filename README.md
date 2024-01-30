# Práctica 4: Algoritmos de ordenamiento

## Objetivo

El objetivo de esta práctica es realizar un análisis experimental del tiempo de ejecución de cinco algoritmos de ordenamiento: insertion sort, selection sort, bubblesort, merge sort y quicksort. Se busca comparar el rendimiento de estos algoritmos en función del tamaño del arreglo a ordenar.

## Procedimiento

Para llevar a cabo el análisis experimental, se implementó un programa de control denominado "ordenamiento.cpp". Este programa recibe por línea de comando el tamaño del arreglo (n) y el número de arreglos a generar y ordenar (m). A continuación, se generan m arreglos aleatorios de tamaño n y se ejecuta cada algoritmo de ordenamiento sobre ellos. Se registran los tiempos de ejecución de cada algoritmo y se calcula el promedio y la desviación estándar del tiempo de ejecución para cada valor de n.

Además, se genera un archivo de salida con los tiempos registrados en una estructura tabular para cada tamaño n. Este archivo servirá para realizar el análisis estadístico y la generación de gráficas.

## Resultados

Los resultados obtenidos muestran el tiempo promedio y la desviación estándar del tiempo de ejecución para cada algoritmo en función del tamaño del arreglo.
Los resultados obtenidos revelan que el tiempo de ejecución de los algoritmos de ordenamiento exhibe una variación significativa en función del tamaño de los datos a ordenar (n). Quicksort se destacó consistentemente al mostrar un rendimiento superior en comparación con los algoritmos de orden cuadrático (insertion sort, selection sort, bubblesort). Además, se observó que los algoritmos recursivos (merge sort, quicksort) demostraron un mejor rendimiento para valores grandes de n. 

A continuación se presentan las tablas con los tiempos de cada algoritmo:

### Promedio

- Iteratividad:
  
![Promedio_iteraivo](T_Pi.png)

- Recursividad:

![Promedio_recursivo](T_Pr.png)


### Desviación estándar

- Iteratividad:

![Desviación_e_iteraivo](T_Di.png)

- Recursividad:

![Desviación_e_recursivo](T_Dr.png)

En un representación grafica:

### Promedio

- Iteratividad:
  
![GPromedio_iteraivo](G_Pi.jpg)

- Recursividad:

![GPromedio_recursivo](G_Pr.jpg)


### Desviación estándar

- Iteratividad:

![GDesviación_e_iteraivo](G_Di.jpg)

- Recursividad:

![GDesviación_e_recursivo](G_Dr.jpg)

#### Nota
Cabe destacar que los experimentos con valores extremadamente grandes de n, específicamente n=500,000,000 y n=1,000,000,000, no pudieron ser realizados debido a que dichos valores exceden los límites de capacidad de procesamiento de la computadora utilizada para el análisis. En estos casos, el programa termina el proceso sin regresar ningún valor debido a la alta demanda de recursos computacionales.
Asimismo, a partir de n=500,000, no se llevaron a cabo experimentos con los algoritmos insertion sort, selection sort y bubblesort, ya que el tiempo de ejecución para estos valores era considerablemente largo y el proceso finalizaba sin arrojar resultados. Estas limitaciones deben tenerse en cuenta al interpretar los resultados y al considerar la escalabilidad de los algoritmos para conjuntos de datos de gran tamaño.

## Análisis

A partir de las gráficas y los datos obtenidos, se observa que:

**Insertion Sort:**
- Este algoritmo es eficiente para conjuntos de datos pequeños o casi ordenados.
- Tiene una complejidad de tiempo promedio de O(n^2), lo que significa que su rendimiento empeora significativamente para conjuntos de datos grandes.
- Es estable y funciona bien en conjuntos de datos con pocos elementos desordenados.

**Selection Sort:**
- Aunque simple, este algoritmo es ineficiente para conjuntos de datos grandes.
- Su complejidad de tiempo promedio es de O(n^2), lo que lo hace menos adecuado para conjuntos de datos extensos.
- Es inestable y no es recomendable para conjuntos de datos grandes o sensibles al tiempo.

**Bubblesort:**
- Es un algoritmo simple pero ineficiente, con una complejidad de tiempo promedio de O(n^2).
- Aunque fácil de implementar, su rendimiento es pobre para conjuntos de datos grandes.
- No se recomienda para aplicaciones que requieran ordenamiento eficiente de grandes volúmenes de datos.

**Merge Sort:**
- Este algoritmo tiene una complejidad de tiempo promedio de O(n log n), lo que lo hace eficiente para conjuntos de datos grandes.
- Es estable y eficaz en la clasificación de grandes volúmenes de datos.
- Su enfoque recursivo lo hace adecuado para aplicaciones que requieren un rendimiento predecible en una amplia gama de situaciones.

**Quicksort:**
- Es altamente eficiente con una complejidad de tiempo promedio de O(n log n).
- Es rápido y adecuado para conjuntos de datos grandes.
- Aunque puede tener un peor rendimiento en el peor de los casos, su rendimiento promedio lo hace ideal para aplicaciones que requieren un ordenamiento rápido y eficiente.

En resumen:

- Quicksort sobresale: Quicksort exhibió un rendimiento excepcional en comparación con los demás algoritmos. Su complejidad de tiempo promedio de O(n log n) lo posiciona como una opción más eficiente, particularmente para conjuntos de datos de gran escala.

- Comportamiento cuadrático en algoritmos iterativos: Los algoritmos de ordenamiento iterativos (insertion sort, selection sort, bubblesort) mostraron un comportamiento cuadrático en términos de tiempo de ejecución, lo cual concuerda con las expectativas basadas en los antecedentes.

- Mejor rendimiento de algoritmos recursivos para grandes conjuntos de datos: Los algoritmos recursivos (merge sort, quicksort) demostraron un mejor rendimiento a medida que el tamaño del conjunto de datos aumentaba. Este hallazgo subraya la importancia de considerar la complejidad del algoritmo al seleccionar un método de ordenamiento para conjuntos de datos grandes.

## Conclusiones

- La elección del algoritmo de ordenamiento es crucial y depende del tamaño y naturaleza del conjunto de datos.
- Quicksort se destaca como una opción eficiente para conjuntos de datos grandes debido a su complejidad O(n log n).
- Los algoritmos iterativos son adecuados para conjuntos de datos pequeños, pero su rendimiento decae rápidamente a medida que el tamaño del conjunto de datos aumenta.
- Los algoritmos recursivos, como merge sort y quicksort, demostraron un mejor rendimiento a medida que el tamaño del conjunto de datos aumentaba, lo que destaca la importancia de considerar la complejidad del algoritmo al seleccionar un método de ordenamiento para conjuntos de datos grandes.
