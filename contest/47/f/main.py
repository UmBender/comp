def sol(n, k):
    acc = 1
    sol = f"{k} "
    for i in range(1,n+1):
        acc = ((acc * (n + 1 - i ))//i)
        if acc & 1 == 1:
            sol += f"{k} "
        else:
            sol += "0 "
    return sol


def solve():
    [n,k] = list(input().split(" "))
    n = int(n)
    k = int(k)
    print(sol(n-1,k)[:-1])

def __main__():
    t = int(input())
    for _ in range(0,t):
        solve()


if __name__=="__main__":
    __main__()
