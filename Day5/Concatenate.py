import numpy as np
n,m,p=map(int,input().split())
ar1 = []
ar2 = []
for i in range(n):
    tmp = list(map(int,input().split()))
    ar1.append(tmp)
for i in range(m):
    tmp = list(map(int,input().split()))
    ar2.append(tmp)    
np_ar1 = np.array(ar1)
np_ar2 = np.array(ar2)
print(np.concatenate((np_ar1,np_ar2),axis = 0))



