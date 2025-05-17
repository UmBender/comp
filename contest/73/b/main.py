[n,k] = list(map(int,input().split(' ')))
def digitc(val: int) -> int:
    count: int = 0
    while val > 0:
        count+=1
        val //= 10
    return count
a = list(map(int, input().split(' ')))
actual = 1
for i in a:
    actual *= i
    if(digitc(actual) > k):
        actual = 1
print(actual)


