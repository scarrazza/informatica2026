/*
  Esercizio 3: Vettori
  Author: Stefano Carrazza - 2018
*/
#include <iostream>
using namespace std;

// definizione della struttura
struct vettore {
  double x;
  double y;
  double z;
};

//__________________________________
double scalar(const vettore &a, const vettore &b);
vettore somma(const vettore &a, const vettore &b);

//__________________________________
int main()
{
  vettore a, b;
  a.x = -1;
  a.y = 2;
  a.z = -3;

  b = a; // copia completa di tutti i membri

  cout << "Prodotto scalare: " << scalar(a, b) << endl;

  vettore c = somma(a, b);
  cout << "Vettore somma: (" << c.x << "," << c.y << "," << c.z << ")" << endl;

  return 0;
}

//__________________________________
// riferimento costante: nessuna copia e nessuna modifica degli argomenti
double scalar(const vettore &a, const vettore &b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

//__________________________________
vettore somma(const vettore &a, const vettore &b)
{
  vettore c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}
