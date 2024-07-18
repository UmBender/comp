    binary_divisor = int(f"{divisor:b}")
    ended = False
    finded = False
    if value == 0 or value == 1:
        ended = True
        finded = True
    while (not ended):
        if value == binary_divisor:
            return True
        if value % binary_divisor == 0:
            value = value // binary_divisor
            stats = teste(value)
            if stats:
                finded = True
                ended = True
            else:
                value = value * binary_divisor
                divisor += 1
                binary_divisor = int(f"{divisor:b}")

        else:
            divisor += 1
            binary_divisor = int(f"{divisor:b}")
        if binary_divisor > value:
            return False

    return finded


t = int(input())
for i in range(0, t):
    value = int(input())
    finded = teste(value)
    if finded:
        print("YES")
    else:
        print("NO")
