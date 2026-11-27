# Questo makefile contiene le istruzioni per compilare tutti gli esercizi
# Qui ho utilizzato alcune funzionalita' piu' avanzate del makefile come
# la definizione di variabili, CC, e riferimenti $@ e $<.
# Gli header sono dipendenze: se cambiano, si ricompila.
CC=g++

all: prog1 prog2 prog3 prog4 prog5 prog6 opz1 opz2 opz3

prog1: esercizio1.cc funzioni1.cc funzioni1.h
	$(CC) -o $@ esercizio1.cc funzioni1.cc

prog2: esercizio2.cc
	$(CC) -o $@ $<

prog3: esercizio3.cc funzioni3.cc funzioni3.h
	$(CC) -o $@ esercizio3.cc funzioni3.cc

prog4: esercizio4.cc funzioni4.cc funzioni4.h
	$(CC) -o $@ esercizio4.cc funzioni4.cc

# solo header: i template sono definiti in statistica.h
prog5: esercizio5.cc statistica.h
	$(CC) -o $@ $<

prog6: esercizio6.cc vettore.cc vettore.h
	$(CC) -o $@ esercizio6.cc vettore.cc

opz1: opzionale1.cc
	$(CC) -o $@ $<

opz2: opzionale2.cc
	$(CC) -o $@ $<

opz3: opzionale3.cc funzioni4.cc funzioni4.h
	$(CC) -o $@ opzionale3.cc funzioni4.cc

clean:
	rm -f prog1 prog2 prog3 prog4 prog5 prog6 opz1 opz2 opz3
