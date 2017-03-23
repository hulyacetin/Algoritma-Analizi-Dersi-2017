import numpy as np
import matplotlib.pyplot as plt
import random
import time
import math


def sort(array):
    less = []
    equal = []
    greater = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x < pivot:
                less.append(x)
            if x == pivot:
                equal.append(x)
            if x > pivot:
                greater.append(x)
        # Don't forget to return something!
        return sort(less)+equal+sort(greater)  # Just use the + operator to join lists
    # Note that you want equal ^^^^^ not pivot
    else:  # You need to hande the part at the end of the recursion - when you only have one element in your array, just return the array.
        return array
    


dizi = [i for i in range(1000)]
random.shuffle(dizi)
start = time.time()
sorteddizi=sort(dizi)
end = time.time()

sure = end-start

sureler = []
sureler.append(sure)
d=sure
step=1000
for i in range(3):
    d = (d * math.log(step*10,2)*10)/math.log(step,2)
    sureler.append(d)
    step=step*10

print(sureler)

eleman_sayilari = [1000,10000,100000,1000000]
plt.xlabel('Eleman Sayilari')
plt.ylabel('Gecen Sure')
plt.title('nlogn quicksort')
plt.plot(eleman_sayilari,sureler,"ro")


plt.show()
