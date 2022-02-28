"""Crie uma função recursiva para calcular a soma dos elementos de um vetor."""
 
def soma(vetor,n):
    if n == 0:
      return 0
    add = vetor[n] + soma(vetor,n-1)
    return add

vetor = [0,1,2,3,4,5]
n = len(vetor) - 1

print(soma(vetor,n))
