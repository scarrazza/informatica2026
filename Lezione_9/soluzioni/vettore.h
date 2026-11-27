// vettore.h: la classe Vettore (vettore nello spazio 3D)
#ifndef VETTORE_H
#define VETTORE_H

class Vettore {
private:
  double x, y, z;

public:
  Vettore();                               // vettore nullo
  Vettore(double ix, double iy, double iz);

  double getX() const { return x; }
  double getY() const { return y; }
  double getZ() const { return z; }

  double modulo() const;
  double scalare(const Vettore &b) const;
  Vettore somma(const Vettore &b) const;
  void stampa() const;
};

#endif
