/*
  Esercizio 2: Hello World struct 2
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
void fattura(prodotto *p, int size);

//__________________________________
int main()
{
  const int nmax = 4;
  prodotto *p = new prodotto[nmax]; // array dinamico di dimensione massima 4

  int n;
  cout << "Quanti prodotti vuoi inserire (max " << nmax << ")? ";
  cin >> n;
  if (n < 1 || n > nmax)
  {
    cout << "Numero di prodotti non valido." << endl;
    delete[] p;
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    cout << "Introdurre prodotto " << i + 1 << endl;
    cout << "Nome (una sola parola): ";
    cin >> p[i].nome;
    cout << "Peso: ";
    cin >> p[i].peso;
    cout << "Prezzo: ";
    cin >> p[i].prezzo;
    cout << endl;
  }

  fattura(p, n); // si passano solo gli n elementi inseriti

  delete[] p;

  return 0;
}

//__________________________________
void fattura(prodotto *p, int size)
{
  cout << "Fattura" << endl;
  cout << "--------------------------------" << endl;
  cout << "Nome\tPeso\tPrezzo" << endl;
  cout << "--------------------------------" << endl;
  double totale = 0;
  for (int i = 0; i < size; i++)
  {
    cout << p[i].nome << "\t" << p[i].peso << "\t" << p[i].prezzo << endl;
    totale += p[i].prezzo;
  }
  cout << "--------------------------------" << endl;
  cout << "Totale (euro): " << totale << endl;
  cout << "--------------------------------" << endl;
}
