# Labyrinth

<br>
refs: "https://cses.fi/problemset/task/1193/"


<br>

## Solução
Basicamente é fazer uma bfs, para encontra o caminho mais curto de primeiro, mas primeiro encontra onde
está em a e b.
Depois faz a bfs sobre toda a árvore, e marca qual foi o caminho que levou para aquele nó, como
foi uma bfs então já será o menor caminho.
Depois vê qual foi o caminho feito pelo busca de traz para fente, de b para a com base na matriz
acima.
