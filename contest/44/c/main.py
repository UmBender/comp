def solve():
    n = int(input())
    s = input()
    s = s.split(" ")
    a = [int(i) for i in s]
    power2 = [1 for _ in a]
    for i in range(n-1, -1, -1):
        print(i)


def __main__():
    print("caps")
    n = int(input())
    for _ in range(0, n):
        solve()


if __name__ == "__main__":
    __main__()
