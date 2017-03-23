import numpy as np
import matplotlib.pyplot as plt
import random
import time
import math


def selectionSort(alist):
   for fillslot in range(len(alist)-1,0,-1):
       positionOfMax=0
       for location in range(1,fillslot+1):
           if alist[location]>alist[positionOfMax]:
               positionOfMax = location

       temp = alist[fillslot]
       alist[fillslot] = alist[positionOfMax]
       alist[positionOfMax] = temp
    


dizi = [i for i in range(1000)]
random.shuffle(dizi)
start = time.time()
sorteddizi=selectionSort(dizi)
end = time.time()

sure = end-start

sureler = []
sureler.append(sure)
d=sure
step=1000
for i in range(3):
    d = d*(step**10)**2/step**2
    sureler.append(d)
    step=step*10

print(sureler)

eleman_sayilari = [1000,10000,100000,1000000]
plt.xlabel('Eleman Sayilari')
plt.ylabel('Gecen Sure')
plt.title('n**2 selection sort')
plt.plot(eleman_sayilari,sureler,"ro")


plt.show()
