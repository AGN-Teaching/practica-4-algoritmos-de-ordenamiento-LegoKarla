#include "ordenamiento_rec_t.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <cmath>

// Estructura para almacenar los tiempos de ejecución de los algoritmos recursivos
struct TiemposAlgoritmosRec {
    double ms_t; // Tiempo de merge sort
    double qs_t; // Tiempo de quicksort
};

// Función para ejecutar y medir el tiempo de un algoritmo recursivo con rango especificado
template <typename Func>
std::chrono::duration<double> ejecutar_y_medir_tiempo(Func algoritmo, std::vector<int>& arr, int inicio, int fin) {
    auto start = std::chrono::high_resolution_clock::now();
    algoritmo(arr.data(), inicio, fin);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}

// Genera un arreglo aleatorio de tamaño n
std::vector<int> generar_arreglo_aleatorio(int n) {
    std::vector<int> array;
    array.reserve(n);
    for (int i = 0; i < n; ++i) {
        array.push_back(rand() % (10 * n) + 1);
    }
    return array;
}

// Calcula el promedio de un vector de números
double calcular_promedio(const std::vector<double>& tiempos) {
    return std::accumulate(tiempos.begin(), tiempos.end(), 0.0) / tiempos.size();
}

// Calcula la desviación estándar de un vector de números dados su promedio
double calcular_desviacion_estandar(const std::vector<double>& tiempos, double promedio) {
    double suma_cuadrados = 0.0;
    for (double tiempo : tiempos) {
        suma_cuadrados += pow(tiempo - promedio, 2);
    }
    double varianza = suma_cuadrados / tiempos.size();
    return sqrt(varianza);
}

int main(int argc, char *argv[]) {
    // Verificar el número correcto de argumentos de línea de comandos
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <tamaño del arreglo> <número de arreglos a generar y ordenar>" << std::endl;
        return 1;
    }

    // Obtener el tamaño del arreglo y el número de arreglos a generar y ordenar desde los argumentos
    int n = std::stoi(argv[1]); // Tamaño del arreglo
    int m = std::stoi(argv[2]); // Número de arreglos a generar y ordenar

    // Almacenar los arreglos generados aleatoriamente
    std::vector<std::vector<int>> arrays;
    arrays.reserve(m);

    // Generar todos los arreglos aleatorios de una vez
    for (int i = 0; i < m; ++i) {
        arrays.push_back(generar_arreglo_aleatorio(n));
    }

    // Estructura para almacenar los tiempos de ejecución de los algoritmos recursivos
    TiemposAlgoritmosRec tiempos;

    // Crear archivo para almacenar resultados
    std::ofstream outputFile("resultados10^9.txt");
    outputFile << "#Ejec.\t\tms_t\t\tqs_t" << std::endl;

    // Medir y almacenar los tiempos para cada arreglo
    for (int i = 0; i < m; ++i) {
        // Medir el tiempo para cada algoritmo directamente en el arreglo generado
        tiempos.ms_t = ejecutar_y_medir_tiempo(merge_sort, arrays[i], 0, arrays[i].size() - 1).count();
        tiempos.qs_t = ejecutar_y_medir_tiempo(quicksort, arrays[i], 0, arrays[i].size() - 1).count();

        // Imprimir en el archivo utilizando el operador de salida de flujo
        outputFile << i + 1 << "\t" << std::fixed << std::setprecision(6)
                    << tiempos.ms_t << "\t" << tiempos.qs_t << std::endl;
    }

    // Cerrar el archivo de resultados
    outputFile.close();

    // Calcular promedio y desviación estándar para cada algoritmo
    std::vector<double> tiempos_ms, tiempos_qs;

    for (int i = 0; i < m; ++i) {
        tiempos_ms.push_back(ejecutar_y_medir_tiempo(merge_sort, arrays[i], 0, arrays[i].size() - 1).count());
        tiempos_qs.push_back(ejecutar_y_medir_tiempo(quicksort, arrays[i], 0, arrays[i].size() - 1).count());
    }

    // Calcular promedio y desviación estándar para cada algoritmo
    double promedio_ms = calcular_promedio(tiempos_ms);
    double desviacion_ms = calcular_desviacion_estandar(tiempos_ms, promedio_ms);

    double promedio_qs = calcular_promedio(tiempos_qs);
    double desviacion_qs = calcular_desviacion_estandar(tiempos_qs, promedio_qs);

    // Imprimir resultados de promedio y desviación estándar
    std::cout << "Promedio y desviación estándar de tiempos:" << std::endl;
    std::cout << "Merge sort:\tPromedio: " << promedio_ms << "\tDesviación estándar: " << desviacion_ms << std::endl;
    std::cout << "Quicksort:\tPromedio: " << promedio_qs << "\tDesviación estándar: " << desviacion_qs << std::endl;

    return 0;
}
