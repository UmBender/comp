[n, k, p] = list(map(int, input().split()))
h = sorted(list(map(int, input().split())))[::-1]

rest = k
counter = 0
for i in h:
    if i > 0:
        continue
    ceilOp = (-i) // p + 1
    if ceilOp > k:
        counter += 1
    else:
        k -= ceilOp

print(counter)
        
    

