from sys import getsizeof

myList=[]
print(getsizeof(myList))

for i in range(10000):
    size_1=getsizeof(myList)
    myList.append(i)
    size_2=getsizeof(myList)
    if(size_1 != size_2):
        print(i,"size degisti")
        print(getsizeof(myList))
    else:
        pass
