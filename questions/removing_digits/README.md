# Removing Digits

<br>
refs: "https://cses.fi/problemset/task/1637/"
<br>

## Solução
Dado as limitações dadas no problema a solução pode ser linear.
Neste caso é possível observar que a maior redução sempre será o objetivo,
desta forma pegamos o valor do maior algarismo para saber a redução que será necessária.
Outra coisa que podemos ver é que o valor de operações para atingir um certo ponto é
o valor de operações necessárias para atingir o número atual menos o maior algarismo,
então definimos umas dp da seguinte forma.

dp[i] = dp[i - max_algarismo(i)] + 1

Considerando o caso base de 0 sendo igual a zero então todos os casos são deriváveis com base
nessa dp, então conseguimos um caso onde a complexidade é O(n) já que iremos calcular
a dp de 1 até n, e depois pegamos o valor de dp[n].
