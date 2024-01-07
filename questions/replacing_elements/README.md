# Replacing Elements
<br>
refs: "https://codeforces.com/problemset/problem/1473/A"
<br>

## Solução
Inicialmente faz o sort da lista assim será necessário saber apenas dois casos possíveis.

<br>
> 1) O maior valor já é menor ou igual que d
> 2) A soma dos dois menores é menor ou igual a d
<br>

Já que não é definido um limite de vezes a substituição de a_j + a_k por a_i.
Assim todos os valores podem ser reduzidos para menor que d, desde que a[0] + a[1] seja menor que d.


