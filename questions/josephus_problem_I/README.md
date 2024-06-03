# Josephus Problem I

<br>
refs: "https://cses.fi/problemset/task/2162"


<br>

## Solução
Utiliza uma queue, pega dois elementos da frente, print o segundo e adiciona no final o primeiro, até ter
apenas um elemento, depois apenas printa o único elemnto restante. É O(n) pois o número de iterações será
n + (n/2) + n/4 + n/8 + .... = 2n
Então será O(n)
