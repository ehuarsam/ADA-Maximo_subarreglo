#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int tiempoOn(const vector<int>& v, long long n) {
    int aqui = v[0];
    int global = v[0];
    for (long long i = 1; i < n; i++) {
        aqui = max(v[i], aqui + v[i]);
        global = max(global, aqui);
    }
    return global;
}

int main() {
    long long n = 100000000LL; // 10^8

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-100, 100);

    vector<int> v(n);
    for (long long i = 0; i < n; i++) v[i] = dist(gen);

    auto inicio = high_resolution_clock::now();
    int resultado = tiempoOn(v, n);
    auto fin = high_resolution_clock::now();

    duration<double> tiempo = fin - inicio;

    cout << "Resultado (suma maxima) = " << resultado << endl;
    cout << "Tiempo Kadane n=1e8: " << fixed << tiempo.count() << " s" << endl;

    return 0;
}
