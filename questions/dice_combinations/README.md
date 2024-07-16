# Dice Combinations

<br>
refs: "https://cses.fi/problemset/task/1633"


<br>

## Solução
Como to soma será da forma
1 + (n-1)
2 + (n-2)
3 + (n-3)
4 + (n-4)
5 + (n-5)
6 + (n-6)
onde n > 6, então apenas soma as formas dos casos (n-x), onde 1 <= x <= 6, guardando os casos anteriores em um vetor, já 
que poderá ser utilizado em otros casos, como 3 = 1 +(3-1) -> (2) -> (2, 1 + 1).
