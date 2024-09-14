def solution():
    val = int(input())
    bit_set = []
    i = 1
    while i < int(10e18):
        if val & i:
            bit_set.append(1)
        else:
            bit_set.append(0)
        i *= 2
    numbers = []
    numbers.append(val)
    for i in range(0, len(bit_set)):
        if bit_set[i] == 1:
            nval = val - (1 << i)
            if nval != 0:
                numbers.append(nval)
    numbers = numbers[::-1]
    print(len(numbers))
    word = ""
    for i in numbers:
        word += str(i)
        word += " "
    print(word)


val = int(input())


for _ in range(0, val):
    solution()
