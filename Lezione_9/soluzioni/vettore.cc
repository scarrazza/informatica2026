// vettore.cc: implementazione dei metodi della classe Vettore
#include <iostream>
#include <cmath>
#include "vettore.h"
using namespace std;

//__________________________________
Vettore::Vettore()
{
  x = 0;
  y = 0;
  z = 0;
}

//__________________________________
Vettore::Vettore(double ix, double iy, double iz)
{
  x = ix;
  y = iy;
  z = iz;
}

//__________________________________
double Vettore::modulo() const
{
  return sqrt(scalare(*this));
}

//__________________________________
double Vettore::scalare(const Vettore &b) const
{
  return x * b.x + y * b.y + z * b.z;
}

//__________________________________
Vettore Vettore::somma(const Vettore &b) const
{
  return Vettore(x + b.x, y + b.y, z + b.z);
}

//__________________________________
void Vettore::stampa() const
{
  cout << "(" << x << ", " << y << ", " << z << ")";
}
