// statistica.h: template per array di qualsiasi tipo numerico
// NB: i template vanno definiti interamente nell'header
#ifndef STATISTICA_H
#define STATISTICA_H

// media degli elementi: restituisce sempre un double
template <typename T>
double media(const T *v, int n)
{
  double somma = 0;
  for (int i = 0; i < n; i++)
    somma += v[i];
  return somma / n;
}

// massimo degli elementi: restituisce lo stesso tipo dell'array
template <typename T>
T massimo(const T *v, int n)
{
  T max = v[0];
  for (int i = 1; i < n; i++)
    if (v[i] > max) max = v[i];
  return max;
}

#endif
