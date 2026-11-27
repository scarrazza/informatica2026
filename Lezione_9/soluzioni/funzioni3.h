// funzioni3.h: struttura e funzioni per l'esercizio 3
#ifndef FUNZIONI3_H
#define FUNZIONI3_H

struct point2d
{
  double x, y;
};

// distanza dal centro del cerchio (0.5, 0.5)
// NB: evitiamo il nome "distance", che esiste gia' come std::distance
double distanza(const point2d &p);

#endif
