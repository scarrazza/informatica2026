// funzioni1.cc: implementazione delle funzioni dell'esercizio 1
#include <iostream>
#include <fstream>
#include <sstream>
#include "funzioni1.h"
using namespace std;

//__________________________________
misura* carica(const string &filename, int &n)
{
  ifstream f;
  f.open(filename);
  if (!f.is_open())
  {
    cerr << "Errore: impossibile aprire " << filename << endl;
    n = 0;
    return nullptr;
  }

  // 1. conto le righe
  n = 0;
  string riga;
  while (getline(f, riga)) n++;

  // 2. riavvolgo il file: prima clear, poi seekg
  f.clear();
  f.seekg(0);

  // 3. alloco esattamente n misure
  misura *v = new misura[n];

  // 4. leggo riga per riga e divido le colonne con uno string stream
  for (int i = 0; i < n; i++)
  {
    getline(f, riga);
    stringstream ss(riga);
    ss >> v[i].x >> v[i].y1 >> v[i].y2;
  }
  f.close();

  return v;
}

//__________________________________
void fit_lineare(const misura *v, int n, int colonna, double &m, double &q)
{
  double sx = 0, sy = 0, sxx = 0, sxy = 0;
  for (int i = 0; i < n; i++)
  {
    double y = (colonna == 1) ? v[i].y1 : v[i].y2;
    sx += v[i].x;
    sy += y;
    sxx += v[i].x * v[i].x;
    sxy += v[i].x * y;
  }
  m = (n * sxy - sx * sy) / (n * sxx - sx * sx);
  q = (sy - m * sx) / n;
}
