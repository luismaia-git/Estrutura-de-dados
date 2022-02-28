#Item D da questão 1

arr = [0,1,2,3]

def itemD(arr):
	n = len(arr)

	impar = 3
	prim = 2

	while impar < n:
		aux = arr[prim]
		pos = arr[impar]

		arr[prim] = pos
		arr[impar] = aux

		impar += 2
		prim += 1
	return arr

print(arr)#print pra ver a lista antes da função modifica-la
itemD(arr)#chamada da função passando a lista
print(arr)#print do resultado da lista depois de modificada pela função
	