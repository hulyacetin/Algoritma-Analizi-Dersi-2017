import numpy as np
import matplotlib.pyplot as plt
import random
import time
import math


def bubbleSort(alist):
    for passnum in range(len(alist)-1,0,-1):
        for i in range(passnum):
            if alist[i]>alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp
    


dizi = [i for i in range(1000)]
random.shuffle(dizi)
start = time.time()
sorteddizi=bubbleSort(dizi)
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
plt.title('n**2 bubblesort')
plt.plot(eleman_sayilari,sureler,"ro")


plt.show()
