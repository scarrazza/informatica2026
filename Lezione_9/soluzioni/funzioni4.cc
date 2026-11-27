// funzioni4.cc: implementazione delle funzioni dell'esercizio 4
#include <iostream>
#include <fstream>
#include "funzioni4.h"
using namespace std;

//__________________________________
misure* load_misure(const string &filename, int &ntotal)
{
  ifstream f;
  f.open(filename);
  if (!f.is_open())
  {
    cerr << "Errore: impossibile aprire " << filename << endl;
    ntotal = 0;
    return nullptr;
  }

  // conto le righe per allocare esattamente la memoria necessaria
  ntotal = 0;
  string riga;
  while (getline(f, riga)) ntotal++;

  // riavvolgo il file
  f.clear();
  f.seekg(0);

  misure *m = new misure[ntotal];
  for (int i = 0; i < ntotal; i++)
  {
    f >> m[i].t >> m[i].vx >> m[i].vy >> m[i].vz >> m[i].K;
    m[i].massa = 0; // verra' calcolata in seguito
  }
  f.close();

  return m;
}

//__________________________________
// K = 1/2 m v^2  =>  m = 2 K / v^2
void fill_mass(misure *m, int ntot)
{
  for (int i = 0; i < ntot; i++)
  {
    double v2 = m[i].vx * m[i].vx + m[i].vy * m[i].vy + m[i].vz * m[i].vz;
    m[i].massa = 2 * m[i].K / v2;
  }
}

//__________________________________
void print_misure(const misure *m, int ntot)
{
  for (int i = 0; i < ntot; i++)
  {
    cout << m[i].t << " "
         << m[i].vx << " "
         << m[i].vy << " "
         << m[i].vz << " "
         << m[i].K << " "
         << m[i].massa << endl;
  }
}

//__________________________________
void store_masses(const misure *m, int ntot, const string &filename)
{
  ofstream out;
  out.open(filename);
  if (!out.is_open())
  {
    cerr << "Errore: impossibile aprire " << filename << endl;
    return;
  }

  for (int i = 0; i < ntot; i++)
    out << m[i].t << " " << m[i].massa << endl;
  out.close();
}
