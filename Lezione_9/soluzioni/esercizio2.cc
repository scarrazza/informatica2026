/*
  Esercizio 2: Generazione dati su file
  Author: Stefano Carrazza
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


// NB: f non e' definita in x = 0; con 100 punti in [-3, 3] lo zero non viene mai toccato
double f(double x)
{
    return -sin(x*x) / x + 0.01 * x*x;
}

int main()
{
    const int N = 100;
    double x[N], dx = 6.0/(N-1);
    for (int i = 0; i < N; i++)
    {
        x[i] = -3 + i * dx;
    }

    fstream out;
    out.open("output.dat", ios::out);
    if (!out.good())
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        out << x[i] << " " << f(x[i]) << endl;
    }
    out.close();

    return 0;
}
