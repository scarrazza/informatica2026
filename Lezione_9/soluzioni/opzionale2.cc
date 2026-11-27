/*
  Esercizio opzionale 2: Ereditarieta'
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <string>
using namespace std;

class Particella {
protected:
  string nome;
  double massa; // MeV/c^2
  int carica;   // in unita' di e

public:
  Particella(string n, double m, int q)
  {
    nome = n;
    massa = (m > 0) ? m : 0;
    carica = q;
  }

  string getNome() const { return nome; }
  int getCarica() const { return carica; }
  double energia_riposo() const { return massa; } // E = m c^2, in MeV
};

class Elettrone : public Particella {
public:
  Elettrone() : Particella("elettrone", 0.511, -1) {}
};

class Protone : public Particella {
public:
  Protone() : Particella("protone", 938.272, 1) {}
};

//__________________________________
// accetta qualsiasi classe figlia di Particella
void descrivi(const Particella &p)
{
  cout << p.getNome() << ": carica " << p.getCarica()
       << " e, energia a riposo " << p.energia_riposo() << " MeV" << endl;
}

//__________________________________
int main()
{
  Elettrone e;
  Protone p;

  descrivi(e);
  descrivi(p);

  cout << "Rapporto delle masse protone/elettrone: "
       << p.energia_riposo() / e.energia_riposo() << endl;

  return 0;
}
