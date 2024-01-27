#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

// Definir una estructura para almacenar los tiempos de ejecución de cada algoritmo
struct TiemposAlgoritmos {
    double is_t; // Tiempo de insertion sort
    double ss_t; // Tiempo de selection sort
    double bs_t; // Tiempo de bubblesort
    double ms_t; // Tiempo de merge sort
    double qs_t; // Tiempo de quicksort
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <tamaño del arreglo> <número de arreglos a generar y ordenar>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]); // Tamaño del arreglo
    int m = std::stoi(argv[2]); // Número de arreglos a generar y ordenar

    std::vector<std::vector<int>> arrays;
    arrays.reserve(m);

    // Generar m arreglos aleatorios de tamaño n
    for (int i = 0; i < m; ++i) {
        std::vector<int> array;
        array.reserve(n);
        // Lógica para generar arreglos aleatorios de tamaño n
        arrays.push_back(array);
    }

    // Declarar la variable tiempos
    TiemposAlgoritmos tiempos;
    
    // Realizar experimentos con los algoritmos de ordenamiento
    std::ofstream outputFile("resultados.txt");
    outputFile << "#Ejec.\tis_t\tss_t\tbs_t\tms_t\tqs_t" << std::endl;

    for (int i = 0; i < m; ++i) {
        for (auto& arr : arrays) {
            auto arr_copy = arr; // Hacer una copia del arreglo 

            // Ejecutar cada algoritmo de ordenamiento y medir el tiempo de ejecución    
            auto start = std::chrono::high_resolution_clock::now();
            insertion_sort(arr_copy.data(), arr_copy.size());
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            tiempos.is_t = elapsed_seconds.count(); // Asignar el tiempo de ejecución a la variable is_t

            start = std::chrono::high_resolution_clock::now();
            selection_sort(arr_copy.data(), arr_copy.size());
            end = std::chrono::high_resolution_clock::now();
            elapsed_seconds = end - start;
            tiempos.ss_t = elapsed_seconds.count(); // Asignar el tiempo de ejecución a la variable ss_t

            start = std::chrono::high_resolution_clock::now();
            bubblesort(arr_copy.data(), arr_copy.size());
            end = std::chrono::high_resolution_clock::now();
            elapsed_seconds = end - start;
            tiempos.bs_t = elapsed_seconds.count(); // Asignar el tiempo de ejecución a la variable bs_t

            // Ejecutar merge sort y medir el tiempo de ejecución
            start = std::chrono::high_resolution_clock::now();
            merge_sort(arr_copy.data(), 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed_seconds = end - start;
            tiempos.ms_t = elapsed_seconds.count(); // Asignar el tiempo de ejecución a la variable ms_t

            // Ejecutar quicksort y medir el tiempo de ejecución
            start = std::chrono::high_resolution_clock::now();
            quicksort(arr_copy.data(), 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed_seconds = end - start;
            tiempos.qs_t = elapsed_seconds.count(); // Asignar el tiempo de ejecución a la variable qs_t

            // Escribir los tiempos en el archivo de salida
            outputFile << i + 1 << "\t" << tiempos.is_t << "\t" << tiempos.ss_t << "\t" << tiempos.bs_t << "\t" << tiempos.ms_t << "\t" << tiempos.qs_t << std::endl;
    }
}

    outputFile.close();

    return 0;
}
