#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

double cpuTest() {
    auto start = chrono::high_resolution_clock::now();

    // Realizamos cálculos intensivos para probar la CPU
    volatile double result = 0.0;
    for (long long i = 0; i < 1e8; ++i) {
        result += sin(i) * cos(i);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Retornamos el tiempo en segundos
    return duration.count();
}
