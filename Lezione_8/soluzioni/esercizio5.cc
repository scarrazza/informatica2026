/*
  Esercizio 5: Particelle cariche (array di struct da file)
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

// definizione della struttura
struct particella {
  double x; // coordinata x
  double y; // coordinata y
  double r; // distanza dalla sorgente in (0,0)
};

//__________________________________
double distanza(const particella *p);
void istogramma(const particella *p, int n, double rmin, double rmax, int nbin);
void anelli(const particella *p, int n, double soglia);

//__________________________________
int main()
{
  const int N = 1000;
  particella *p = new particella[N]; // array di struct sull'heap

  ifstream f;
  f.open("data.dat");
  if (!f.is_open())
  {
    cout << "Errore: impossibile aprire il file 'data.dat'." << endl;
    delete[] p;
    return 1;
  }

  // lettura: ci si ferma a N particelle o quando la lettura fallisce
  int n = 0;
  while (n < N && f >> p[n].x >> p[n].y)
  {
    p[n].r = distanza(&p[n]); // passo l'indirizzo dell'elemento n
    n++;
  }
  f.close();
  cout << "Particelle lette: " << n << endl << endl;

  cout << fixed << setprecision(2); // due cifre decimali

  istogramma(p, n, 0.6, 1.25, 13);
  cout << endl;
  anelli(p, n, 0.9);

  delete[] p;

  return 0;
}

//__________________________________
// distanza dall'origine: p e' un puntatore, quindi si usa ->
double distanza(const particella *p)
{
  return sqrt(p->x * p->x + p->y * p->y);
}

//__________________________________
// istogramma testuale della distanza: un asterisco ogni 4 particelle
void istogramma(const particella *p, int n, double rmin, double rmax, int nbin)
{
  int *conteggi = new int[nbin];
  for (int b = 0; b < nbin; b++) conteggi[b] = 0;

  double larghezza = (rmax - rmin) / nbin;
  for (int i = 0; i < n; i++)
  {
    int b = (p[i].r - rmin) / larghezza;
    if (b >= 0 && b < nbin) conteggi[b]++;
  }

  cout << "Istogramma della distanza r:" << endl;
  for (int b = 0; b < nbin; b++)
  {
    cout << rmin + b * larghezza << "\t| ";
    for (int k = 0; k < conteggi[b] / 4; k++) cout << "*";
    cout << " " << conteggi[b] << endl;
  }

  delete[] conteggi;
}

//__________________________________
// separa i due anelli con una soglia sulla distanza
void anelli(const particella *p, int n, double soglia)
{
  int n_int = 0, n_est = 0;
  double somma_int = 0, somma_est = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[i].r < soglia)
    {
      n_int++;
      somma_int += p[i].r;
    }
    else
    {
      n_est++;
      somma_est += p[i].r;
    }
  }

  cout << "Soglia: r = " << soglia << endl;
  cout << "Anello interno: " << n_int << " particelle, raggio medio "
       << somma_int / n_int << endl;
  cout << "Anello esterno: " << n_est << " particelle, raggio medio "
       << somma_est / n_est << endl;
}
