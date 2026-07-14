




def main() -> None:
    [n, k] = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    longest = 0
    actual = 0
    for i in a:
        if i < k:
            actual = 0
        else:
            actual += 1
        longest = max(longest, actual)
    print(longest)

main()





