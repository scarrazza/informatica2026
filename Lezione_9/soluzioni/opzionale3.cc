/*
  Esercizio opzionale 3: Strutture e puntatori a strutture
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include "funzioni4.h"
using namespace std;

//__________________________________
// riceve il puntatore a una misura e aggiorna direttamente il suo campo massa
void calcola_e_assegna_massa(misure *m)
{
  double v2 = m->vx * m->vx + m->vy * m->vy + m->vz * m->vz;
  m->massa = 2 * m->K / v2;
}

//__________________________________
int main()
{
  int ntot = 0;
  misure *m = load_misure("../data4.dat", ntot);
  if (m == nullptr) return 1;

  for (int i = 0; i < ntot; i++)
    calcola_e_assegna_massa(&m[i]); // indirizzo dell'elemento i

  // stampa delle prime 3 misure
  print_misure(m, 3);

  delete[] m;

  return 0;
}
