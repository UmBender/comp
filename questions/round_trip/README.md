# Round Trip 

<br>
refs: "https://cses.fi/problemset/task/1669/"


<br>

## Solução
A solução é fazer uma dfs, e quando encontrar um ponto já acessado mas que não seja o ponto que acessou o seu ponto
atual, voce encontrou um ciclo da forma (x ... y x), encontrando o cara requerido.
