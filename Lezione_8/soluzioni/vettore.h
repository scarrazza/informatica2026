// vettore.h: definizione della struct vettore e dichiarazioni delle funzioni
#ifndef VETTORE_H // include guard: evita la doppia definizione
#define VETTORE_H

struct vettore {
  double x;
  double y;
  double z;
};

double scalar(const vettore &a, const vettore &b);
vettore somma(const vettore &a, const vettore &b);
double modulo(const vettore &a);
void stampa(const vettore &v);

// Esercizio opzionale 3
vettore prodotto_vettoriale(const vettore &a, const vettore &b);

#endif
