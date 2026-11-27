/*
  Esercizio 6: La classe Vettore
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include "vettore.h"
using namespace std;

int main()
{
  // il problema dell'esercizio 4 della Lezione 8, ora con una classe
  Vettore F(3, 0, 4);  // forza (N)
  Vettore s1(2, 0, 0); // primo spostamento (m)
  Vettore s2(0, 1, 0); // secondo spostamento (m)

  Vettore s = s1.somma(s2);
  cout << "Spostamento totale s = ";
  s.stampa();
  cout << " m" << endl;

  cout << "Modulo della forza |F| = " << F.modulo() << " N" << endl;
  cout << "Lavoro W = F . s = " << F.scalare(s) << " J" << endl;

  // array di oggetti: serve il costruttore di default
  Vettore forze[3];
  forze[0] = Vettore(1, 0, 0);
  forze[1] = Vettore(0, 2, 0);
  forze[2] = Vettore(0, 0, 3);

  Vettore risultante; // parte dal vettore nullo
  for (int i = 0; i < 3; i++)
    risultante = risultante.somma(forze[i]);

  cout << "Risultante R = ";
  risultante.stampa();
  cout << ", |R| = " << risultante.modulo() << " N" << endl;

  // F.x = 1;  ERRORE: x e' private, si usa getX()
  cout << "Componente x di F: " << F.getX() << " N" << endl;

  return 0;
}
