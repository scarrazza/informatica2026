/*
  Esercizio opzionale 3: Headers e vettori (prodotto vettoriale)
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include "vettore.h"
using namespace std;

int main()
{
  vettore a = {1, 0, 0};
  vettore b = {0, 1, 0};

  vettore c = prodotto_vettoriale(a, b);
  cout << "a x b = ";
  stampa(c);
  cout << endl;

  return 0;
}
