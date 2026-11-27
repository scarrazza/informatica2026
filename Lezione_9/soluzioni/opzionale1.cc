/*
  Esercizio opzionale 1: Classe con distruttore
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// carica la colonna y1 (seconda colonna) di un file con tre colonne
class Campione {
private:
  double *dati;
  int n;

public:
  Campione(const string &filename)
  {
    n = 0;
    dati = nullptr;
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
      cerr << "Errore: impossibile aprire " << filename << endl;
      return;
    }

    string riga;
    while (getline(f, riga)) n++;
    f.clear();
    f.seekg(0);

    dati = new double[n];
    double x, y2;
    for (int i = 0; i < n; i++)
      f >> x >> dati[i] >> y2;
    f.close();
    cout << "Campione: allocati " << n << " valori" << endl;
  }

  ~Campione()
  {
    delete[] dati; // delete[] su nullptr non fa nulla
    cout << "Campione: memoria liberata" << endl;
  }

  int size() const { return n; }

  double media() const
  {
    double somma = 0;
    for (int i = 0; i < n; i++)
      somma += dati[i];
    return somma / n;
  }
};

//__________________________________
// passaggio per riferimento costante: nessuna copia dell'oggetto
void descrivi(const Campione &c)
{
  cout << "Valori: " << c.size() << ", media: " << c.media() << endl;
}

//__________________________________
int main()
{
  {
    Campione c("../data5.dat");
    descrivi(c);
  } // qui c esce dallo scope e viene chiamato il distruttore

  cout << "fine del main" << endl;

  return 0;
}
