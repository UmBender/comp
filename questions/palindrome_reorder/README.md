# Palindrome Reorder

<br>
refs: "https://cses.fi/problemset/task/1755/"


<br>

## Solução
Primeiro vê se é possível ser um palindromo, ou seja, ter um número par
de cada letra, quando a palavra tem tamnho par. Ou ter apenas uma letra
com um número impar de letras, se a palavra ter um tamanho impar.


Para gerar agora é só printar a metada do número das vezes que a letra aparece em ordem alfabetica.
caso seja impar decrementar antes em um o único valor que é impar e printar no meio essa única letra impar,
então printar a metade do número de vezes que a letra aparece, só que na ordem oposta da alfabetica.
