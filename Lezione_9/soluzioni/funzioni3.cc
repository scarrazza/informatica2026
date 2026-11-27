// funzioni3.cc: implementazione delle funzioni dell'esercizio 3
#include <cmath>
#include "funzioni3.h"
using namespace std;

double distanza(const point2d &p)
{
  return sqrt(pow(p.x - 0.5, 2) + pow(p.y - 0.5, 2));
}
