/*
  Esercizio opzionale 2: Strutture annidate
  Author: Stefano Carrazza - 2026
*/
#include <iostream>
#include <string>
using namespace std;

// NB: il nome "data" non va bene: con "using namespace std" entra in
// conflitto con la funzione std::data della libreria standard (C++17)
// data_cal va definita prima di evento, che la contiene
struct data_cal {
  int giorno;
  int mese;
  int anno;
};

struct evento {
  string nome;
  data_cal data_evento;
};

//__________________________________
void stampa_evento(evento e);

//__________________________________
int main()
{
  evento compleanno = {"Compleanno", {10, 12, 2025}};

  stampa_evento(compleanno);

  return 0;
}

//__________________________________
void stampa_evento(evento e)
{
  cout << "Evento: " << e.nome << endl;
  cout << "Data: " << e.data_evento.giorno << "/" << e.data_evento.mese
       << "/" << e.data_evento.anno << endl;
}
