# Grid 1

<br>
refs: "https://atcoder.jp/contests/dp/tasks/dp_g"


<br>

## Solução
Cria uma dp bi-dimensional em que cada posição é o número de possíveis
caminhos para chegar naquela determinada posição, colocando a posição inicial como
1, os ocupados como -1 e os outros como zero inicialmente, depois passa
por cada coluna de cada linha pois dp[i][j] = max(dp[i-1][j], 0) + max(dp[i][j-1], 0),
se i,j >= 0, se i ou j < 0 dp[i][j] = 0.
Desta forma no final basta pegar o valo da dp[h-1][w-1].
