def main():
    n = int(input())
    x = [int(i) for i in input().split()]
    positions = {}
    for pos, i in enumerate(x):
        positions[i] = pos
    counter = 1
    last = -1
    for i in range(1, n + 1):
        actual = positions[i]
        if actual > last:
            last = actual
        else:
            counter += 1
            last = actual
    print(counter)


if __name__ == "__main__":
    main()
