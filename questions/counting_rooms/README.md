# Counting Rooms

<br>
refs: "https://cses.fi/problemset/task/1192/"


<br>

## Solução
Você passa por todos os pontos, se o ponto for do tipo floor e não foi visitado, então faz uma dfs marcando todos os pontos
visinhos como marcados que são do tipo floor, e encrementa o contador.
