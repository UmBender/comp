t = int(input())
for i in range(t):
    s = input()
    s = s.split(" ")
    acc = ""
    for i in s:
        acc += i[0]
    print(acc)
    

