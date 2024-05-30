# Maximum Subarray Sum

<br>
refs: "https://cses.fi/problemset/task/1643/"


<br>

## Solução

Apenas define duas variaveis, maximo e soma, e adiciona um por um dos elementos de x em soma,
se soma > maximo, então maximo = soma, se soma < 0, soma = 0
Isso se deve pelo fato que o valor da soma se for menor que zero então não vale a pena usar aquele intervalo.
