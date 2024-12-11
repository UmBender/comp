def min(a: int, b: int) -> int:
    return a if a < b else b


def rec(actual: int, rest: int) -> int:
    if rest == 4:
        return actual * 100 + 51
    if rest == 5:
        return rec(actual * 10 + 5, 4)
    if rest == 6:
        return rec(actual * 100 + 50, 4)
    return rec(actual * 100 + 50, rest - 2)


def solve():
    n = int(input())
    if n == 1:
        print(-1)
        return
    if n == 2:
        print(66)
        return
    if n == 3:
        print(-1)
        return

    print(66 * rec(0, n))


t = int(input())
for _ in range(0, t):
    solve()
