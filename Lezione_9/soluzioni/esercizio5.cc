/*
  Esercizio 5: Template e overloading
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "statistica.h"
using namespace std;

//__________________________________
// overloading: stesso nome, parametri di tipo diverso
void stampa(const string &nome, int valore)
{
  cout << nome << " = " << valore << endl;
}

void stampa(const string &nome, double valore)
{
  cout << nome << " = " << fixed << setprecision(3) << valore << endl;
}

//__________________________________
int main()
{
  int voti[5] = {28, 30, 25, 27, 30};
  double g[4] = {9.79, 9.83, 9.81, 9.80}; // misure di g in m/s^2

  // media restituisce double: si usa stampa(string, double)
  // massimo restituisce il tipo dell'array: int per voti, double per g
  stampa("media voti", media(voti, 5));
  stampa("massimo voti", massimo(voti, 5));
  stampa("media g", media(g, 4));
  stampa("massimo g", massimo(g, 4));

  return 0;
}
