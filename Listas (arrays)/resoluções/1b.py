#Item B da questão 1

arr = [0,1,2,3,4,5]


def itemB(arr):
	n = len(arr) 
	i = 1
	
	while i < n/2:
		aux = arr[i] 
		arr[i] = arr[n-i]
		arr[n-i] = aux
		i += 1
	return arr

print(arr)#print pra ver a lista antes da função modifica-la
itemB(arr)#chamada da função passando a lista
print(arr)#print do resultado da lista depois de modificada pela função