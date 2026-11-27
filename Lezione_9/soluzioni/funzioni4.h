// funzioni4.h: struttura e funzioni per l'esercizio 4
#ifndef FUNZIONI4_H
#define FUNZIONI4_H

#include <string>

struct misure {
  int t;         // istante della misura
  double vx;     // componente x della velocita'
  double vy;     // componente y della velocita'
  double vz;     // componente z della velocita'
  double K;      // energia cinetica totale
  double massa;  // massa dell'oggetto in moto
};

// carica tutte le misure: conta le righe, riavvolge e legge (nullptr se errore)
misure* load_misure(const std::string &filename, int &ntotal);

// calcola e assegna la massa a ogni misura
void fill_mass(misure *m, int ntot);

// stampa la descrizione completa di ogni misura
void print_misure(const misure *m, int ntot);

// salva t e massa su file, per il grafico
void store_masses(const misure *m, int ntot, const std::string &filename);

#endif
