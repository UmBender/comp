# Permutations

<br>
refs: "https://cses.fi/problemset/task/1070/"
<br>

## Solução
A solução é simples, é possível ver que o caso com n=1 é possível, pois não há
valores adjacentes, já no caso n=2 e n=3, é impossível pois pelo número limitado de 
elementos, em qualquer caso ao menos um par de valores terão uma diferença igual a 1
[1,2]
[2,1]
[1,2,3] [1,2,3]
[1,3,2] [3,2]
[2,1,3] [2,1]
[2,3,1] [2,3]
[3,2,1] [3,2,1]
[3,1,2] [1,2]

Já no caso que os valores são maiores ou iguais a 4, então é possível, apenas printa
os valores de 1 até n que são pares e depois os números de 1 até n que são impares.
Isso é valido pois o única posição que é possível ocorrer uma diferença que é igual a um
é no meio, já que o criterio para os elementos na direita é ser par, ou seja, ter a diferença no minimo
de 2, e na esquerda ser impar, o que pode se dizer mesmo, tendo a diferença mínima de 2.
Então no meio é so necessário ver que o maior valor para do intervalo [1..n] tem uma diferença maior que um para
o menor valor impar da do intevalo [1..n], que é 1. Desta forma é possível ver que depois que o maior valor par 
do interval for diferente de dois, qualquer sequência será possível ser *beatiful*. Por isso que para n=2 e n=3 não é possível
mas para n >= 4 é. Já que para todo elemento (n - n % 2) -1 > 1 quando n >=4




