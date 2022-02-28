#Item C da questão 2

arr = [0,1,1,2,2,3,3,4,4,4,5,5,5,5,5]
def itemC2(arr):
	n = len(arr) 

	aux = len(arr) * [1]
	aux[0] = 0

	i = 1
	while i < n:
		j = 1
		while j < i:
			if arr[i] == arr[j]:
				i += 1
				break			
			else:
				j += 1	
		
		k = i + 1 
		while k < n:
			if arr[i] == arr[k]:
				aux[i] += 1
				k += 1
			else:
				k += 1
		i += 1	
	

	maiorE = 0
	po = 1
	while po < n:
		if aux[po] >= maiorE:
			maiorE = aux[po]
		po += 1
		
		
	qn = 1				
	while qn < n:
		if aux[qn] == maiorE:
			print(arr[qn])
		qn += 1

itemC2(arr)#chamada da função, ela mostra o resultado do elemento que mais aparece
