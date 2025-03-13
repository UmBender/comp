def funf():
    values = [int(i) for i in input().split(' ')]
    print(values)
    actual = 0
    for (i,j) in enumerate(values):
        if i%2==0:
            actual &=j
        else:
            actual |= j
    print(actual)

t = int(input())
for _ in range(t):
    funf()

