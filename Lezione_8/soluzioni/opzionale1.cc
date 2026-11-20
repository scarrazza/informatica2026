/*
  Esercizio opzionale 1: Prodotto maggiore
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <string>
using namespace std;

// definizione della struttura
struct prodotto {
  int peso;
  double prezzo;
  string nome;
};

//__________________________________
prodotto* trova_maggiore(prodotto *p, int size);

//__________________________________
int main()
{
  const int n = 3;
  prodotto *p = new prodotto[n];
  p[0] = {200, 2.5, "banana"};
  p[1] = {1000, 9.5, "olio"};
  p[2] = {500, 1.2, "pasta"};

  prodotto *max = trova_maggiore(p, n);
  cout << "Prodotto piu' costoso: " << max->nome
       << " (" << max->prezzo << " euro)" << endl;

  delete[] p;

  return 0;
}

//__________________________________
// restituisce l'indirizzo di un elemento dell'array, non di una variabile locale
prodotto* trova_maggiore(prodotto *p, int size)
{
  prodotto *max = &p[0];
  for (int i = 1; i < size; i++)
    if (p[i].prezzo > max->prezzo)
      max = &p[i];
  return max;
}
