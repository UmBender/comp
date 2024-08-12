# Trailing Zeros

<br>
refs: "https://cses.fi/problemset/task/1618"


<br>

## Solução

Inicialmente é necessário notar que a maior cadeia de zeros em um fatorial irá surgir sempre será 
no início. Após isso é necessário ver que para adicionar um zero ao final o fatorial deve ser multiplicado
por 10, o que ocorre quando há um numero terminado por 0 ou quando dois números são multiplicados os quais são
múltiplos de 2 e 5. Também é possível ver que há bem mais número múltiplos de 2 do que de 5. Dado este 
fato o que é possível ser feito é calcular o número de mutliplos de 5 até um certo número, basta diviir esse número por 5,
e pegar a parte inteira, o que também é possível ver que se fazermos essa operação novamente com o resultda
teremos o número de valores que são multiplos de 25. Fazendo a soma do número de números que são múltiplos de 5, mais os que são
de 25, que irão garantir mais de um zero, dos múltiplos de 125 que irão garantir mais de dois zeros, assim sucessivamente.
Basicamente assim calculamos o expoente do número de cinco após a fatoração desse número fatorial, sendo assim sabemos
o número de zeros que irão haver ao final do número.

