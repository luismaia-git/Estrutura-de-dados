vetor = [1,2,3,7,4,5,6]

def encontrar(vetor, indice):

  n = len(vetor)

  if indice >= n:
    return -1
  if encontrar(vetor,indice+1) > vetor[indice]:
    return encontrar(vetor,indice+1)
  else:
    return vetor[indice]
  

print(encontrar(vetor, 0))