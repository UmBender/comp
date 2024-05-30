# Sum of Two Values

<br>
refs: "https://cses.fi/problemset/task/1640"


<br>

## Solução
Apenas coloca todos os valores em um vetor, e cria uma mapa onde a chave é o valor e valor é a posição no vetor.
Então passa todo array, descobre o valor que falta para cada valor para atingir o alvo e então vê no mapa se
tem um elemento que satisfaz a soma, assim ficando da forma O(n*log(n))
