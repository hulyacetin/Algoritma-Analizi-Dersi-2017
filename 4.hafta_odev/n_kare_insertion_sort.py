import numpy as np
import matplotlib.pyplot as plt
import random
import time
import math

def insertionSort(alist):
   for index in range(1,len(alist)):

     currentvalue = alist[index]
     position = index

     while position>0 and alist[position-1]>currentvalue:
         alist[position]=alist[position-1]
         position = position-1

     alist[position]=currentvalue
    


dizi = [i for i in range(1000)]
random.shuffle(dizi)
start = time.time()
sorteddizi=insertionSort(dizi)
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
plt.title('n**2 insertion sort')
plt.plot(eleman_sayilari,sureler,"ro")


plt.show()
