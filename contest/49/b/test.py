def exact_sqrt(x: int)-> int:
    i = 0 
    j = 100000000000
    while(i < j):
        m = i + (j-i)//2
        if(m * m == x):
            return m 
        elif(m * m > x):
            j = m - 1 
            continue
        i = m + 1 
    return -1


import math
x =((288+1) * 288)//2 
print(x)
print(math.sqrt(x))
print(exact_sqrt(((288+1) * 288)//2))

# acc = 0
# for i in range(1, 100000):
#     acc+=i 
#     if(exact_sqrt(acc) != -1):
#         print(acc, i)
#

