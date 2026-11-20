/*
  Esercizio 1: Hello World struct 1
  Author: Stefano Carrazza - 2018
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
void stampa_prodotto(prodotto p);

//__________________________________
int main()
{
  // inizializzazione a elenco: segue l'ordine dei membri (peso, prezzo, nome)
  prodotto banana = {200, 2.5, "banana"};

  stampa_prodotto(banana);

  return 0;
}

//__________________________________
void stampa_prodotto(prodotto p)
{
  cout << "Prodotto:" << endl;
  cout << "  - nome: " << p.nome << endl;
  cout << "  - peso: " << p.peso << endl;
  cout << "  - prezzo: " << p.prezzo << endl;
}
