# Coin Piles

<br>
refs: "https://cses.fi/problemset/task/1754/"


<br>

## Solução
As duas operações podem ser descritas como -2x -y e -x e -2y, o que transforma o problema
em um sistema linear de duas variáveis, desta forma podemos escrever o número de moedas
na pilha como sendo o número de operações de cada tipo, assim
a = 2x + y
b = x + 2y
Agora só tem que resolver o sistema.
y = (-a+2b)/3
x = (2a-b)/3
Desta forma só tem que ver se os valores y e x são inteiros e se ambos são maiores o iguais a zero.
