#Item E da questão 1

arr = [4, 5, 2, 1, 7, 11]


def itemE(arr):

    aux = len(arr)//2

    for i in range(0, aux):
        if i % 2 == 0:
            for j in range(aux, len(arr)):
                if j % 2 == 1:
                    aux2   = arr[i]
                    arr[i] = arr[j]
                    arr[j] = aux2
                    aux = j+1
                    return arr

print(arr) #print pra ver a lista antes da função modifica-la
itemE(arr)#chamada da função passando a lista
print(arr)#print do resultado da lista depois de modificada pela função
