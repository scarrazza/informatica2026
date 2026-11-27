// funzioni1.h: struttura e funzioni per l'esercizio 1
#ifndef FUNZIONI1_H
#define FUNZIONI1_H

#include <string>

// una riga del file: x e due misure y1, y2
struct misura {
  double x, y1, y2;
};

// conta le righe del file, riavvolge, alloca e carica i dati
misura* carica(const std::string &filename, int &n);

// fit lineare y = m x + q con i minimi quadrati (colonna = 1 per y1, 2 per y2)
void fit_lineare(const misura *v, int n, int colonna, double &m, double &q);

#endif
