import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('output.dat')

plt.plot(data[:,0], data[:,1], '-o')

plt.title("funzione vs x")
plt.xlabel("x")

plt.show()
