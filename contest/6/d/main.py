nn = int(input())


def sol(n):
    if n >= 0 and n <= 9:
        print(n)
        return
    elif n >= 10 and n <= 18:
        val = n % 9
        print(2 * str(val))
        return
    else:
        new_n = n - 18


sol(nn)
