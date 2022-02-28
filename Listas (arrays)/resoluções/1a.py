#Item A da questão 1

arr = [1,2,3,4,5]

def itemA(A,X,k):
  i = 0
  while i < len(arr):
    if arr[i] == X:
      print("o Elemento",X, "ja ta na lista")
      return -1
    i+=1
  i = 0  
  while i < len(arr):

    if i == k:
      arr[i] = X
      return i
    i+=1


print(arr) #print pra ver a lista antes da função modifica-la
itemA(arr,3,2) #chamada da função passando a lista
print(arr)#print do resultado da lista depois de modificada pela função


