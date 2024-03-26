# BerSU Ball 

<br>
refs: "https://codeforces.com/problemset/problem/489/B"


<br>

## Solução
Ordena os dois arrays, então, usando a técnica de dois arrays, vai se eliminando os elementos que não são possíveis
criar um par,
por exemplo:

a = [1, 3, 4, 5]
              ^
b = [2, 5, 8]
           ^
a = [1, 3, 4, 5]
              ^
b = [2, 5, 8]
        ^
a = [1, 3, 4, 5]
           ^
b = [2, 5, 8]
     ^
a = [1, 3, 4, 5]
        ^
b = [2, 5, 8]
     ^
a = [1, 3, 4, 5]
     ^
b = [2, 5, 8]
   ^

Termina execução, não há mais elementos em b



 

