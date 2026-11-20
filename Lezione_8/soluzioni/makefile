# Questo makefile contiene le istruzioni per compilare tutti gli esercizi
# Qui ho utilizzato alcune funzionalita' piu' avanzate del makefile come
# la definizione di variabili, CC, e riferimenti $@ e $<.
CC=g++

all: prog1 prog2 prog3 prog4 prog5 opz1 opz2 opz3

prog1: esercizio1.cc
	$(CC) -o $@ $<

prog2: esercizio2.cc
	$(CC) -o $@ $<

prog3: esercizio3.cc
	$(CC) -o $@ $<

# l'header e' una dipendenza: se cambia vettore.h si ricompila
prog4: esercizio4.cc vettore.cc vettore.h
	$(CC) -o $@ esercizio4.cc vettore.cc

prog5: esercizio5.cc
	$(CC) -o $@ $<

opz1: opzionale1.cc
	$(CC) -o $@ $<

opz2: opzionale2.cc
	$(CC) -o $@ $<

opz3: opzionale3.cc vettore.cc vettore.h
	$(CC) -o $@ opzionale3.cc vettore.cc

clean:
	rm -f prog1 prog2 prog3 prog4 prog5 opz1 opz2 opz3
