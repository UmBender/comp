# Minimizing Coins

<br>
refs: "https://cses.fi/problemset/task/1634/"


<br>

## Solução
A questão é que como a soma só pode ser escrica utilizando valores de moedas, então
o valor da soma deve ser o valor de uma moeda ou o valor de uma moeda mais a soma de uma série de moedas,
neste caso queremos minimizar, então escolhemos a moeda tal que 
valor = moeda + sum(valor-moeda), tal que o número de moedas utilizadas seja menor.
Utilizando um vetor para armazenar casos já calculados, ou os unitários, em que uma única moeda é necessária,
então podemos calcular o número de moedas necessários para que seja possível ver qual é o menor número de moedas.

