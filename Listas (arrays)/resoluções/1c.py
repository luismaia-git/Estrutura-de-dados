#Item C da questão 1

arr = [0,1,2,3,4,5,6]

def itemC(arr):
	n = len(arr) - 1

	m = (n // 2) + 1		# 'm' é a segunda metade da lista
	p = m						  # 'p' guarda o valor da segunda metade da lista
	i = 1
	
	while i < p:
		aux = arr[i]
		aux2 = arr[m]
	
		arr[m] = aux
		arr[i] = aux2

		i += 1
		m += 1

# se o tamanho do vetor for impar	
	if n % 2 != 0:
		while p < n:
			aux = arr[p]
			aux2 = arr[n]
	
			arr[p] = aux2
			arr[n] = aux
			p += 1
	return arr

print(arr)#print pra ver a lista antes da função modifica-la
itemC(arr)#chamada da função passando a lista
print(arr)#print do resultado da lista depois de modificada pela função
	
			
	
		
	
	


	 	 