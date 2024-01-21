t = input()
s = input()
h = input()

for i in range(t):
    print('*' + s * ' ' + '*' + s * ' ' + '*')

print('*' * (2 * s + 3))

for i in range(h):
    print((s+1) * ' ' + '*' + (s+1) * ' ')
