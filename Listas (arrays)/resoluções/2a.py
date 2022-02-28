#Item A da questão 2
arr = [0,3,4,7,9,2,10,8]

def itemA2(arr):

  i = 1
  maiorE = 0
  maiorE2 = 0

  while i < len(arr):
    if arr[i] > maiorE:
      maiorE2 = maiorE
      maiorE = arr[i]
      i+=1
    elif arr[i]> maiorE2:
      maiorE2 = arr[i]
      i+=1
    else:
      i+=1
  return maiorE2


print(arr) #print pra ver a lista antes da função modifica-la
print(itemA2(arr)) #print do resultado que a função retorna

