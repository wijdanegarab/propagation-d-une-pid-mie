import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt('Pop.txt')

temps             = data[:, 0]
S                 = data[:, 1]
I                 = data[:, 2]
R                 = data[:, 3]
C                 = data[:, 4]
V                 = data[:, 5]
D                 = data[:, 6]
population_totale = data[:, 7]

plt.figure(figsize=(10, 7))
plt.plot(temps, population_totale, label='Population totale', linestyle='-', color='black')
plt.plot(temps, S, label='Sains non vaccinés',  linestyle='-', color='blue')
plt.plot(temps, I, label='Infectés',            linestyle='-', color='red')
plt.plot(temps, R, label='Rétablis',            linestyle='-', color='green')
plt.plot(temps, C, label='Contaminés',          linestyle='-', color='orange')
plt.plot(temps, V, label='Vaccinés',            linestyle='-', color='purple')
plt.plot(temps, D, label='Morts',               linestyle='-', color='pink')

plt.xlabel('Temps')
plt.ylabel('Population')
plt.title('Évolution des populations en fonction du temps')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('evolution_epidemie.png', dpi=150)
plt.show()
