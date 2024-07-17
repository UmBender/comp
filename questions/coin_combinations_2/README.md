# Coin Combinations 2

<br>
refs: "https://cses.fi/problemset/task/1636/"


<br>

## Solução
A grande questão aqui é aqui encontrar formas realmente distintas para chegar em um dado valor.
Então a ideia, para evitar a repetição é fazer de forma crescente.
Então começa com um caso base solutions[0] = 1.
Agora o que fazemos é ordenar as moedas, assim calculamos todas as possibilidades que sejam da seguinte forma.
Para um k de 1 até n, vemos o número de geradores para aquele número dado a moeda.
Então fica da forma solution[k] += solution[k - moeda[i]]. Por exemplo com moedas de valor 1,3 para o valor 5:
[1, 0, 0, 0, 0, 0] então olha quem dado que o valor atual é 1 e a moeda é 1 gera, ou seja o zero, e o número de
formas de gerar 0 é uma, então solution[1] += solution[0], ou seja é 0 + 1, agora para dois, quem gera ele com uma
moeda de valor 1 é 1, então solution[2] += solution[1]...
[1,1,1,1,1,1,1], agora para a moeda três, de que forma eu posso gerar um com 3, não dá, agora para dois, tbm não
agora para três temos a forma 3 = 0 + 3, então a forma que podemos calcular 3 com uma moeda de 3 é então
solution[3] += solution[0], agora para quatro, para gerar quatro com a moeda de 3 temo o número de possibilidades
de termos o valor 1, desta forma solution[4] += solution[1], pois 4 = 1 + 3, agora para gerar 5 temos que ver quantas 
formas podemos gerar cinco com uma moeda de 3, que é o número de possibilidades de gerar o valor 2, desta forma 
solution[5] += solution[2]. Agora terminamos, já que não há mais moedas,
e ficamos com o vetor da seguinte forma
[1, 1, 1, 2, 2, 2]
já que 0 = 0
1 = 1
2 = 1 + 1
3 = 3 ou 1 + 1 + 1
4 = 1 + 3 ou 1 + 1 + 1 + 1
5 = 1 + 1 + 3 ou 1 + 1 + 1 + 1 + 1

