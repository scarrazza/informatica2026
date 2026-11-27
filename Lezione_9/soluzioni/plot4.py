# Grafico della massa in funzione del tempo (esercizio 4)
import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('masse.dat')
t, massa = data[:, 0], data[:, 1]

plt.plot(t, massa, 'o', markersize=3, label='misure')
plt.axhline(massa.mean(), color='r', label=f'media = {massa.mean():.3f} kg')

plt.title("Massa in funzione del tempo")
plt.xlabel("t")
plt.ylabel("massa (kg)")
plt.legend()

plt.show()
