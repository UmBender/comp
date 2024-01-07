val = 0
val = int(input())
lista = [""]  * val
for i in range(val):
    lista[i]= input()

for i in range(val):
    print(int(lista[i][0]) + int(lista[i][2]))
