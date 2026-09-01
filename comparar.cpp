#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;


void hacerArray(int v[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < n; i++) {
        v[i] = dist(gen);
    }
}


int tiempoOn3(int v[], int n) {
    int max = v[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int parcial = 0;
            for (int w = i; w <= j; w++) 
                parcial += v[w];
            if (parcial > max)  max = parcial;
            
        }
    }
    return max;
}

int tiempoOn2(int v[], int n) {
    int max = v[0];
    for (int i = 0; i < n; i++) {
        int parcial = 0;
        for (int j = i; j < n; j++) {
            parcial += v[j];
            if (parcial > max)  max = parcial;
        }
    }

    return max;
}

int tiempoOn(int v[], int n) {
    int aqui = v[0];
    int global = v[0];

    for (int i = 1; i < n; i++) {
        aqui = max(v[i], aqui + v[i]);
        global = max(global, aqui);
    }

    return global;
}


double medirTiempo(int (*funcion)(int[], int), int v[], int n) {
    auto inicio = high_resolution_clock::now();
    int resultado = funcion(v, n);
    auto fin = high_resolution_clock::now();
    volatile int aux = resultado;
    (void)aux;
    duration<double> tiempo = fin - inicio;
    return tiempo.count();
}


void medir() {
    cout << left
         << setw(10) << "n"
         << setw(15) << "O(n^3)"
         << setw(12) << "Razon"
         << setw(15) << "O(n^2)"
         << setw(12) << "Razon"
         << setw(15) << "O(n)"
         << setw(12) << "Razon"
         << endl;

    cout << string(91, '-') << endl;


    double anterior3 = 0;
    double anterior2 = 0;
    double anterior1 = 0;

    for (int n = 1000; n <= 8000; n *= 2) {
        int v[8000];
        hacerArray(v, n);

        double t3 = medirTiempo(tiempoOn3, v, n);
        double t2 = medirTiempo(tiempoOn2, v, n);
        double t1 = medirTiempo(tiempoOn, v, n);

        double razon3 = 0;
        double razon2 = 0;
        double razon1 = 0;

        if (anterior3 != 0)
            razon3 = t3 / anterior3;

        if (anterior2 != 0)
            razon2 = t2 / anterior2;

        if (anterior1 != 0)
            razon1 = t1 / anterior1;


        cout << left
             << setw(10) << n
             << setw(15) << fixed << setprecision(6) << t3
             << setw(12) << fixed << setprecision(2) << razon3
             << setw(15) << fixed << setprecision(6) << t2
             << setw(12) << fixed << setprecision(2) << razon2
             << setw(15) << fixed << setprecision(6) << t1
             << setw(12) << fixed << setprecision(2) << razon1
             << endl;


        anterior3 = t3;
        anterior2 = t2;
        anterior1 = t1;
    }
}

int main() {
    int v[] = {10, 0, -8, 19, -1};
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Array: {10, 0, -8, 19, -1}\n\n";
    cout << "O(n^3) = " << tiempoOn3(v, n) << endl;
    cout << "O(n^2) = " << tiempoOn2(v, n) << endl;
    cout << "O(n)   = " << tiempoOn(v, n) << endl;


    medir();

    return 0;
}

