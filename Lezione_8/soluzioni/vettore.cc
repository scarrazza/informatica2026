// vettore.cc: implementazione delle funzioni dichiarate in vettore.h
#include <iostream>
#include <cmath>
#include "vettore.h"
using namespace std;

//__________________________________
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

//__________________________________
double modulo(const vettore &a)
{
  return sqrt(scalar(a, a));
}

//__________________________________
void stampa(const vettore &v)
{
  cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

//__________________________________
vettore prodotto_vettoriale(const vettore &a, const vettore &b)
{
  vettore c;
  c.x = a.y * b.z - a.z * b.y;
  c.y = a.z * b.x - a.x * b.z;
  c.z = a.x * b.y - a.y * b.x;
  return c;
}
