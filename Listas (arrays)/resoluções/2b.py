#Item B da questão 2
arr = [0,1,2,3,2,2,2,2,4,5,5,6,3,3,6,1]

def itemB2(arr):
	n = len(arr) - 1

	i = 1
	while i <= n:
		j = 1
		while j < i:
			if arr[i] == arr[j]:
				i += 1
				break			
			else:
				j += 1	
		
		k = i + 1 
		while k <= n:
			if arr[i] == arr[k]:
				print(arr[i])
				i += 1
				break
			else:
				k += 1
		i += 1	
	

itemB2(arr) #chamada da função, ela mostra o resultado dos elementos repetidos
