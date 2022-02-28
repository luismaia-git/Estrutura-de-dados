arr = [0,1,2,3,4,5,6,7,8,9]

def busca_ternaria(arr,X):
  l = 1
  r = len(arr)-1


  while l <= r:
    M = (r-l)//3+l

    if arr[M]>=X:
      if arr[M]==X:
        return M
      r=M-1
    else:
      l=M+1

  return -1


print(busca_ternaria(arr,8))