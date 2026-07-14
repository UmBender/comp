
def main():
    [n, m, k] = [int(i) for i in input().split()]
    d = [int(i) for i in input().split()]
    ps = []
    for i in range(0, m):
        psi = [int(i) for i in input().split()]
        ps.append(psi)

    narr = []
    i = 0
    j = 0
    while i < n and j < m:
        corri = i + 1
        [p, s] = ps[j]
        if p < corri:
            narr.append(s)
            j += 1
        else:
            narr.append(-d[i])
            i += 1

    while i < n:
        narr.append(-d[i])
        i += 1
    while j < m:
        [p, s] = ps[j]
        narr.append(s)
        j += 1

    for i in narr:
        if i < 0 and k <= 0:
            print("No")
            return
        elif i < 0:
            k += i
        else:
            k = max(k, i)

    print("Yes")

            
main()


            
        
