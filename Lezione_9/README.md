# 💻 Laboratorio di Informatica 9

### Prof. Stefano Carrazza - Corso C

**Riassunto:** Esercizi di base in C++: **caricamento dati**, string stream, template, overloading e classi.

Prima di iniziare suggeriamo di creare una cartella per questa lezione in cui potete salvare tutti i file che saranno creati per gli esercizi.

```bash
cd ~/           # ci porta alla home directory
mkdir lezione9  # crea la directory sulla vostra home
cd lezione9     # entrate dentro la cartella
```

Dopodiché creare un `makefile` con le istruzioni di compilazione per tutti gli esercizi.

-----

### 📈 Esercizio 1 - Caricamento dati e fit lineare

Il file `data5.dat` contiene, riga per riga, i valori di una variabile $x$ e di due misure $y_1$ e $y_2$ (3 colonne). Il numero di righe **non è noto** a priori. Programmare applicando la distinzione tra header e sorgenti.

1.  Scaricare il file con:

    ```bash
    wget https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data1.dat
    # oppure (se macos)
    curl https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data1.dat -o data1.dat
    ```

2.  Nel file header **`funzioni1.h`**, definire la struttura:
    ```c++
    struct misura {
      double x, y1, y2;
    };
    ```

3.  Scrivere una funzione `misura* carica(const string &filename, int &n)` che:
    - conta le righe del file con `getline`;
    - **riavvolge** il file con `clear()` e `seekg(0)`;
    - alloca un **array dinamico** di esattamente `n` misure;
    - legge ogni riga con: `getline` e ne estrae le tre colonne con uno **`stringstream`** oppure direttamente con l'operatore `>>`;
    - restituisce il puntatore all'array e, tramite il riferimento `n`, il numero di misure.

4.  Scrivere una funzione `void fit_lineare(const misura *v, int n, int colonna, double &m, double &q)` che calcola con il metodo dei **minimi quadrati** la retta $y = m x + q$ per la colonna $y_1$ (`colonna = 1`) o $y_2$ (`colonna = 2`):
    $$m = \frac{n \sum x_i y_i - \sum x_i \sum y_i}{n \sum x_i^2 - \left(\sum x_i\right)^2}, \qquad q = \frac{\sum y_i - m \sum x_i}{n}$$

5.  Nel `main`, stampare il numero di misure lette e i parametri $m$ e $q$ dei fit di $y_1$ e di $y_2$, con 3 cifre decimali. Ricordarsi di **liberare la memoria**.

> **Domanda:** i dati $y_1$ sono stati generati da una retta e quelli $y_2$ da una parabola, entrambi con un rumore del 5%. Quale dei due fit lineari ha senso? Come potreste verificarlo con un grafico?

-----

### ✍️ Esercizio 2 - Generazione dati su file

Scrivere un programma in C++ in cui:

1.  Definite una funzione di tipo `double` che restituisce la formula:
    $$f(x) = -\frac{\sin(x^2)}{x} + 0.01 x^2$$
    dove $x$ è l'argomento della funzione.

2.  Sul `main` costruire un array $x$ di **100 elementi** distanziati linearmente tra **$[-3, 3]$**. (*Nota:* $f$ non è definita in $x = 0$; con 100 punti equidistanti lo zero non viene mai raggiunto.)

3.  Stampare su file **`output.dat`** riga per riga le coppie $x$ e $f(x)$ e visualizzarle con uno script di plotting.

-----

### 🔍 Esercizio 3 - Data filtering

Scrivere un **programma in C++** in cui dei punti letti da file vengono classificati in 2 categorie: **dentro** e **fuori** da un cerchio centrato nel piano $(x,y) = (0.5, 0.5)$ e raggio $r = 0.5$. Programmare applicando la distinzione tra header e sorgenti.

1.  Definire una struttura dati per punti sul piano $(x,y)$. Scaricare il file di dati con le coordinate $(x,y)$ di 1000 punti con:

    ```bash
    wget https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data3.dat
    # oppure
    curl https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data3.dat -o data3.dat
    ```

2.  Caricare i dati da file in un **array dinamico** della struttura definita al punto 1.

3.  Per ogni elemento dell'array di punti determinare se si trova dentro o fuori del cerchio e stampare le coordinate $(x,y)$ in 2 file distinti, rispettivamente **`dentro.dat`** e **`fuori.dat`**. (*Suggerimento*: costruire una funzione `distanza` che calcola la distanza tra il punto e il centro del cerchio, in modo che il codice di filtraggio sia breve. Evitate il nome `distance`, che esiste già nella libreria standard come `std::distance`.)

-----

### ⚛️ Esercizio 4 - Misure di un oggetto in movimento

Il file `data4.dat` contiene, riga per riga, un numero **imprecisato** di misure di un oggetto in movimento nello spazio tridimensionale. Ogni riga contiene 1 dato di tipo `int` e 4 dati di tipo `double`: l'istante $t$, le tre componenti della velocità $(v_x, v_y, v_z)$ e l'energia cinetica totale $K$ dell'oggetto all'istante $t$. Scaricare il file con:

```bash
wget https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data4.dat
# oppure
curl https://raw.githubusercontent.com/scarrazza/informatica2026/master/Lezione_9/data4.dat -o data4.dat
```

Definita la struttura:

```c++
struct misure {
    int t;          // istante della misura
    double vx;      // componente x della velocità
    double vy;      // componente y della velocità
    double vz;      // componente z della velocità
    double K;       // energia cinetica totale dell'oggetto
    double massa;   // massa dell'oggetto in moto
};
```

Svolgere i seguenti punti con un programma in C++, usando la distinzione **header/sorgente** e **makefile** assieme ad uno script di plotting:

1.  Caricare tutte le misure descritte nel file `data4.dat` in un **array di misure allocato dinamicamente**, di dimensione pari al numero di righe del file (contare le righe e riavvolgere il file, come visto a lezione). Il campo `massa` verrà riempito in seguito: inizializzarlo a zero durante il caricamento da file. Stampare a video: (i) il **numero di misure lette** e (ii) la **descrizione completa di ogni misura**. (*Hint*: scrivere funzioni per caricare l'array da file e per stampare la descrizione completa di ogni misura.)

2.  (i) Scrivere una funzione che calcola la massa $m$ per ogni istante $t$ sapendo che l'energia cinetica $K$ è data da:
    $$K = \frac{1}{2} \cdot m \cdot (v_x^2 + v_y^2 + v_z^2)$$
    (ii) Assegnare a ciascuna misura la propria massa, cioè: assegnare al campo `massa` di `misure`.
    (iii) Stampare a video la descrizione aggiornata delle misure. (*Hint*: usare la funzione del punto 1.)

3.  Salvare su un file `masse.dat` le coppie $t$ e massa e realizzare un grafico della massa in funzione del tempo con uno script Python. La massa è costante nel tempo? Quanto vale la sua media?

-----

### 📊 Esercizio 5 - Template e overloading

Scrivere un programma in C++ che calcola semplici statistiche su array di tipi diversi.

1.  In un file header **`statistica.h`** (protetto da un include guard) definire due **template di funzione**:
    - `double media(const T *v, int n)`, che restituisce la media degli elementi;
    - `T massimo(const T *v, int n)`, che restituisce l'elemento più grande, dello stesso tipo dell'array.

    > I template vanno definiti **interamente** nell'header: non serve un file `.cc`.

2.  Nel file `esercizio5.cc` scrivere due versioni (**overloading**) della funzione `stampa`:
    - `void stampa(const string &nome, int valore)`, che stampa il valore così com'è;
    - `void stampa(const string &nome, double valore)`, che stampa il valore con 3 cifre decimali (`fixed` e `setprecision`).

3.  Nel `main`, definire gli array `int voti[5] = {28, 30, 25, 27, 30};` e `double g[4] = {9.79, 9.83, 9.81, 9.80};` (misure di $g$ in m/s²) e stampare media e massimo di entrambi con la funzione `stampa`.

> **Domanda:** quale versione di `stampa` viene chiamata per `massimo(voti, 5)`? E per `media(voti, 5)`? Perché?

-----

### 🧭 Esercizio 6 - La classe `Vettore`

Riprendere la `struct vettore` della Lezione 8 e trasformarla in una **classe**, separando header e sorgente.

1.  Nel file **`vettore.h`** definire la classe `Vettore` con:
    - le coordinate `x`, `y`, `z` come membri **privati**;
    - un **costruttore di default**, che crea il vettore nullo, e un costruttore `Vettore(double ix, double iy, double iz)`;
    - i metodi `getX()`, `getY()`, `getZ()`;
    - i metodi `modulo()`, `scalare(const Vettore &b)`, `somma(const Vettore &b)` e `stampa()`, tutti `const` perché non modificano l'oggetto.
2.  Nel file **`vettore.cc`** implementare costruttori e metodi con il prefisso `Vettore::`.
3.  Nel `main`, risolvere di nuovo il problema dell'Esercizio 4 della Lezione 8: data una forza **F = (3, 0, 4) N** e gli spostamenti **s1 = (2, 0, 0) m** e **s2 = (0, 1, 0) m**, calcolare lo spostamento totale, il modulo della forza e il lavoro $W = \vec F \cdot \vec s$.
4.  Creare un **array di 3 oggetti** `Vettore` con le forze $(1, 0, 0)$, $(0, 2, 0)$ e $(0, 0, 3)$ N, calcolarne la risultante e il suo modulo.
5.  Provare a scrivere `F.x = 1;` nel `main` e leggere l'errore del compilatore. Perché `Vettore forze[3];` richiede il costruttore di default?

-----

### 🧠 Esercizi Opzionali per l'approfondimento

Questi esercizi sono consigliati per approfondire i concetti della lezione, in particolare classi, ereditarietà e gestione della memoria.

1. **Classe con Distruttore**

    1.  Scrivere una classe `Campione` con due membri privati: un puntatore `double *dati` e il numero di valori `int n`.
    2.  Il costruttore `Campione(const string &filename)` conta le righe del file, alloca `dati` con `new` e carica la colonna $y_1$ di `data5.dat`. Il distruttore libera la memoria con `delete[]` e stampa un messaggio.
    3.  Aggiungere i metodi `size()` e `media()` e una funzione `void descrivi(const Campione &c)` che stampa il numero di valori e la media.
    4.  Nel `main`, creare l'oggetto dentro un blocco `{ ... }` e verificare dai messaggi **quando** viene chiamato il distruttore. Verificare l'assenza di memory leak con **Valgrind** (Linux) o con `leaks --atExit -- ./programma` (macOS).
    5.  Perché `descrivi` riceve l'oggetto **per riferimento**? Che cosa succederebbe passandolo per valore?

2. **Ereditarietà: Particelle**

    1.  Definire la classe madre `Particella` con i membri `protected` `nome`, `massa` (in MeV/c²) e `carica`, un costruttore che controlla che la massa sia positiva e i metodi `getNome()`, `getCarica()` e `energia_riposo()`.
    2.  Definire le classi figlie `Elettrone` (0.511 MeV, carica −1) e `Protone` (938.272 MeV, carica +1), i cui costruttori chiamano quello della madre.
    3.  Scrivere una funzione `void descrivi(const Particella &p)` e chiamarla sia con un elettrone sia con un protone. Stampare il rapporto tra le masse di protone ed elettrone.

3. **Strutture e Puntatori a Strutture**

    A partire dall'**Esercizio 4**, modificando la funzione di calcolo massa.

    1.  Modificare la funzione che calcola la massa (punto 2.i dell'Esercizio 4) affinché prenda come argomento un **puntatore a `struct misure`** (`misure* m`) e aggiorni direttamente il campo `massa` della misura puntata. La funzione non dovrà restituire nulla (`void`).
    2.  Rinominare la funzione in `void calcola_e_assegna_massa(misure *m);`.
    3.  Nel `main`, implementare un ciclo in cui si scorre l'array dinamico di misure e si chiama la nuova funzione per ogni elemento, passando l'indirizzo dell'elemento come argomento.
        *Esempio (all'interno del ciclo):* `calcola_e_assegna_massa(&m[i]);`
