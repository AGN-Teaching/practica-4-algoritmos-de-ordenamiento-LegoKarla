#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>

// Estructura para almacenar los tiempos de ejecución de los algoritmos
struct TiemposAlgoritmos {
    double is_t; // Tiempo de insertion sort
    double ss_t; // Tiempo de selection sort
    double bs_t; // Tiempo de bubblesort
    double ms_t; // Tiempo de merge sort
    double qs_t; // Tiempo de quicksort
};

// Función para ejecutar y medir el tiempo de algoritmos que toman tres argumentos
template <typename Func>
std::chrono::duration<double> ejecutar_y_medir_tiempo(Func algoritmo, std::vector<int>& arr, int inicio, int fin) {
    auto start = std::chrono::high_resolution_clock::now();
    algoritmo(arr.data(), inicio, fin);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}

// Función sobrecargada para algoritmos que toman solo dos argumentos
template <typename Func>
std::chrono::duration<double> ejecutar_y_medir_tiempo(Func algoritmo, std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    algoritmo(arr.data(), arr.size());
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}

// Función para generar un arreglo aleatorio de tamaño n
std::vector<int> generar_arreglo_aleatorio(int n) {
    std::vector<int> array;
    array.reserve(n);
    for (int i = 0; i < n; ++i) {
        array.push_back(rand() % (10 * n) + 1);
    }
    return array;
}

// Función para calcular el promedio de un vector de valores
double calcular_promedio(const std::vector<double>& tiempos) {
    return std::accumulate(tiempos.begin(), tiempos.end(), 0.0) / tiempos.size();
}

// Función para calcular la desviación estándar de un vector de valores
double calcular_desviacion_estandar(const std::vector<double>& tiempos, double promedio) {
    double suma_cuadrados = 0.0;
    for (double tiempo : tiempos) {
        suma_cuadrados += pow(tiempo - promedio, 2);
    }
    double varianza = suma_cuadrados / tiempos.size();
    return sqrt(varianza);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <tamaño del arreglo> <número de arreglos a generar y ordenar>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]); // Tamaño del arreglo
    int m = std::stoi(argv[2]); // Número de arreglos a generar y ordenar

    std::vector<std::vector<int>> arrays;
    arrays.reserve(m);

    // Generar todos los arreglos aleatorios de una vez
    for (int i = 0; i < m; ++i) {
        arrays.push_back(generar_arreglo_aleatorio(n));
    }

    TiemposAlgoritmos tiempos;
    std::ofstream outputFile("resultados.txt");
    outputFile << "#Ejec.\t\tis_t\t\tss_t\t\tbs_t\t\tms_t\t\tqs_t" << std::endl;

    for (int i = 0; i < m; ++i) {
        // Medir el tiempo para cada algoritmo directamente en el arreglo generado
        tiempos.is_t = ejecutar_y_medir_tiempo(insertion_sort, arrays[i]).count();
        tiempos.ss_t = ejecutar_y_medir_tiempo(selection_sort, arrays[i]).count();
        tiempos.bs_t = ejecutar_y_medir_tiempo(bubblesort, arrays[i]).count();
        tiempos.ms_t = ejecutar_y_medir_tiempo(merge_sort, arrays[i], 0, arrays[i].size() - 1).count();
        tiempos.qs_t = ejecutar_y_medir_tiempo(quicksort, arrays[i], 0, arrays[i].size() - 1).count();

        // Imprimir en el archivo utilizando el operador de salida de flujo
        outputFile << i + 1 << "\t" << std::fixed << std::setprecision(6)
                    << tiempos.is_t << "\t" << tiempos.ss_t << "\t"
                    << tiempos.bs_t << "\t" << tiempos.ms_t << "\t" << tiempos.qs_t << std::endl;
    }

    outputFile.close();

    // Calcular promedio y desviación estándar
    std::vector<double> tiempos_is, tiempos_ss, tiempos_bs, tiempos_ms, tiempos_qs;

    for (int i = 0; i < m; ++i) {
        tiempos_is.push_back(ejecutar_y_medir_tiempo(insertion_sort, arrays[i]).count());
        tiempos_ss.push_back(ejecutar_y_medir_tiempo(selection_sort, arrays[i]).count());
        tiempos_bs.push_back(ejecutar_y_medir_tiempo(bubblesort, arrays[i]).count());
        tiempos_ms.push_back(ejecutar_y_medir_tiempo(merge_sort, arrays[i], 0, arrays[i].size() - 1).count());
        tiempos_qs.push_back(ejecutar_y_medir_tiempo(quicksort, arrays[i], 0, arrays[i].size() - 1).count());
    }

    double promedio_is = calcular_promedio(tiempos_is);
    double desviacion_is = calcular_desviacion_estandar(tiempos_is, promedio_is);

    double promedio_ss = calcular_promedio(tiempos_ss);
    double desviacion_ss = calcular_desviacion_estandar(tiempos_ss, promedio_ss);

    double promedio_bs = calcular_promedio(tiempos_bs);
    double desviacion_bs = calcular_desviacion_estandar(tiempos_bs, promedio_bs);

    double promedio_ms = calcular_promedio(tiempos_ms);
    double desviacion_ms = calcular_desviacion_estandar(tiempos_ms, promedio_ms);

    double promedio_qs = calcular_promedio(tiempos_qs);
    double desviacion_qs = calcular_desviacion_estandar(tiempos_qs, promedio_qs);

    std::cout << "Promedio y desviación estándar de tiempos:" << std::endl;
    std::cout << "Insertion sort:\tPromedio: " << promedio_is << "\tDesviación estándar: " << desviacion_is << std::endl;
    std::cout << "Selection sort:\tPromedio: " << promedio_ss << "\tDesviación estándar: " << desviacion_ss << std::endl;
    std::cout << "Bubblesort:\tPromedio: " << promedio_bs << "\tDesviación estándar: " << desviacion_bs << std::endl;
    std::cout << "Merge sort:\tPromedio: " << promedio_ms << "\tDesviación estándar: " << desviacion_ms << std::endl;
    std::cout << "Quicksort:\tPromedio: " << promedio_qs << "\tDesviación estándar: " << desviacion_qs << std::endl;

    return 0;
}

