/*
  Esercizio 1: Caricamento dati e fit lineare
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <iomanip>
#include "funzioni1.h"
using namespace std;

int main()
{
  int n = 0;
  misura *v = carica("../data5.dat", n);
  if (v == nullptr) return 1;

  cout << "Misure lette: " << n << endl;
  cout << fixed << setprecision(3);

  double m, q;
  fit_lineare(v, n, 1, m, q);
  cout << "Fit di y1: m = " << m << ", q = " << q << endl;

  fit_lineare(v, n, 2, m, q);
  cout << "Fit di y2: m = " << m << ", q = " << q << endl;

  delete[] v;

  return 0;
}
