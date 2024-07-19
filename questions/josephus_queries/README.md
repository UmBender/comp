# Josephs Queries

<br>
refs: "https://cses.fi/problemset/task/2164/"


<br>

## Solução
De fato a questão é simples, básicamente ele ve se o elemento que está sendo removido é o 1, então retorna 1, se não
ele ve se da para ver se nessa primera "volta" se ele já consegue remover, 
ou seja, se 2 * k <= n + 1, se o valor de 2 * k for maior que, quer dizer que ele remove o primeiro cara da volta
então retorna (2 * k) % 2, se ele não começar dar a volta, quer dizer que a remoção vai ser da forma n remove n + 1, por
isso que retorna 2*k.

Se 2 * k > n que dizer que não é ainda na primeira volta, mas simulamos novamente como se fosse, então para 
como "removemos" n / 2, então o novo valor de k é k - (n+1) / 2, e de n é n/2, já que tiramos a metade.

O retorno desse caso vai ter que ser "corrigido" para o caso do tamanho, por exemplo, pro caso que n é par,
quer dizer que o número de elementos é impar, então ele "retira" o 1, já no caso que n é impar, então o número
de elementos é par, então quer dizer que ele retira o valor n, por isso que no caso que n é par, temos que multiplicar 
o retorno por dois, já que metade foi retirada, mas esse caso o último removeu o primeiro, então para acertar isso ele tem que retirar 1.
Já no caso que n é impar o cara que foi removido é o impar da frente, já que não começa a dar a volta.

