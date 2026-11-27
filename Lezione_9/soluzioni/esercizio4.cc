/*
  Esercizio 4: Misure da file
  Author: Stefano Carrazza
*/
#include <iostream>
#include "funzioni4.h"
using namespace std;

int main()
{
  // Punto 1
  int ntot = 0;
  misure *m = load_misure("../data4.dat", ntot);
  if (m == nullptr) return 1;

  cout << "Punto 1" << endl;
  cout << "i)   Misure lette = " << ntot << endl;
  cout << "ii)  Descrizione delle misure (t, vx, vy, vz, K, massa):" << endl;
  print_misure(m, ntot);

  // Punto 2
  cout << "Punto 2" << endl;
  cout << "i, ii) calcolo delle masse..." << endl;
  fill_mass(m, ntot);
  cout << "iii) descrizione aggiornata:" << endl;
  print_misure(m, ntot);

  // dati per il grafico (plot4.py)
  store_masses(m, ntot, "masse.dat");

  delete[] m;

  return 0;
}
