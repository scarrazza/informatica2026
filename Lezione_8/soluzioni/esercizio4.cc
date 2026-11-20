/*
  Esercizio 4: Headers e sorgente
  Author: Stefano Carrazza - 2018
*/
#include <iostream>
#include "vettore.h"
#include "vettore.h" // incluso due volte: compila grazie all'include guard
using namespace std;

int main()
{
  vettore F = {3, 0, 4};  // forza (N)
  vettore s1 = {2, 0, 0}; // primo spostamento (m)
  vettore s2 = {0, 1, 0}; // secondo spostamento (m)

  vettore s = somma(s1, s2);
  cout << "Spostamento totale s = ";
  stampa(s);
  cout << " m" << endl;

  cout << "Modulo della forza |F| = " << modulo(F) << " N" << endl;
  cout << "Lavoro W = F . s = " << scalar(F, s) << " J" << endl;

  return 0;
}
