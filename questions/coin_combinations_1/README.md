# Coin Combinations I

<br>
refs: "https://cses.fi/problemset/task/1635/"


<br>

## Solução
Considerando que as moedas são o vetor moedas[n].
Os casos das possiveis formas que podemos atinigir o valor n será da seguinter forma.
x = (0<= i < n)\sum  soluação(x - moedas[i]), desta forma podemos ver que 
o número de soluções é igual a soma do caso onde o alvo é x menos o valor da i-esima moeda,
para otimizar isso podemos guardar os casos já calculados e um vetor, marcar se ele é possível ou não.

