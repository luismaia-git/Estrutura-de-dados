'''Dados dois vetores (de números inteiros) ordenadas A[1::m] e B[1::n], retornar um único vetor ordenado contendo todos os elementos dos vetores originais.'''


A = [6,7,8,9,10]
B = [1,2,3,4,5]


def junta_vetor(A,B):
  
  C=[0] * (len(A) + len(B))

  for i in range(0,len(A)):
    C[i] = A[i]
  for i in range(len(A),len(A)+len(B)):
    C[i]= B[i-len(A)]
  return C
  
V = junta_vetor(A,B)
V.sort()
print(V)
