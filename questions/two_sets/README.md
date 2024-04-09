# Two Sets

<br>
refs: "https://cses.fi/problemset/task/1092/"


<br>

## Solução
Vê se a soma de PA de 1 até n é divisível por 2

Caso Par:
Vai pegando pares de elemento dos extremos:
[1,2,3,4,5,6,7,8] -> 1,8 -> 2,7 -> 3,6 -> 4,5
E dividi essa lista de elementos em dois:
[1,3,6,8]
[2,4,5,7]

Caso impar:
Faz o mesmo, porém remove o elemento 1, o que gera uma série par que não é divisível
[1,2,3,4,5,6,7] -> [2,3,4,5,6,7]
2,7 -> 3,6 -> [4,5]
Então pega divide os pares que foram feitos em duas listas
[2,7]
[3,6]
Agora adiciona em uma das listas o valor 1 e o menor valor dos dois que sobrou, e na outra
adiciona o elemento maior 
[2,7,1,4]
[3,6,5]

