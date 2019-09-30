import matplotlib.pyplot as plt
import numpy as np
import sys

f = open(sys.argv[1],"r")
lines=f.readlines()
x = np.zeros(len(lines))
y = np.zeros_like(x)
y1 = np.zeros_like(x)
i=0
for line in lines:
    x[i] = float(line.split()[0])
    y[i] = float(line.split()[1])
    y1[i] = float(line.split()[2])
    i += 1

plt.figure(figsize=(6,8))
plt.subplot(211)
plt.scatter(x,y, label = "Average error of Eigenvalues", color = 'g')
plt.plot(x,y,color='gray', linewidth=1)
plt.ylabel("Average Error")
#plt.xlabel("Integration points, N")
plt.tick_params(direction='in', top = 'true', right = 'true')
plt.title(r"Presicion and time increase with more integration points. $ \rho_{max} = 10$")
#plt.yscale('log')
#plt.legend()

plt.subplot(212)
plt.scatter(x,y1, label = "Time spent", color = 'b')
plt.plot(x,y1,color='gray', linewidth = 1)
plt.ylabel("Time spent(s)")
plt.xlabel("Integration points, N")
plt.tick_params(direction='in', top = 'true', right = 'true')
#plt.legend()


#plt.suptitle("Presicion and time increase with more integration points")
plt.savefig("PLOT.png", bbox_inches='tight')
plt.show()

"""



f = np.zeros(len(sys.argv))                     #f er vektor med lenge lik antall argumenter
line = np.zeros_like(f)                         #line er det samme
x = np.zeros_like(f)
y = np.zeros_like(f)
for file in range(1,len(sys.argv)):             # for i fra 1 til lengden av inputparameter vektoren (i over alle input parametre)
    f[file] = open(sys.argv[file],"r")          # f[i] = les den i'te fila
    lines[file] = f[file].readlines()           # linjene[i] blir alle linjene i f[i]

    i=0                                         # Definere i= 0 før neste løkke
    for line in lines:                          # For hver linje i den aktuelle fila
        x[file][i] = float(line.split()[0])     # Gjør om linja til to floats der første verdi er x og andre verdi er y
        y[file][i] = float(line.split()[1])
        i += 1                                  # gjør klar til å lese neste linje, altså neste x og y verdi i den aktuelle fila
        plt.plot(x[file],y[file])               # Plotter alle x og y verdiene av den aktuelle fila. label = "TDMA n=&g" % len(x[i])


plt.legend()

plt.show()
"""
