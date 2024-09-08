#include <iostream>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;

double cpuTest(long long iterations) {
    auto start = chrono::high_resolution_clock::now();

    double result = 0.0; // Eliminado volatile
    for (long long i = 0; i < iterations; ++i) {
        result += sin(i) * cos(i);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    return duration.count();
}

int main() {
    long long iterations = 1e8; // Puedes cambiar este valor
    double timeTaken = cpuTest(iterations);

    cout << fixed << setprecision(6);
    cout << "Tiempo tomado para " << iterations << " iteraciones: " << timeTaken << " segundos." << endl;

    return 0;
}
