# Mystic Permutation

<br>
refs: "https://codeforces.com/problemset/problem/1689/B"


<br>

## Solução
Criar um vetor para ver se o valor foi utilizado, como os elementos são os valores 1..n
apenas vai testando qual valor de 1 até k, e vendo se no vetor original os valores no coincidem.
No caso final, onde sobra 2 elementos checa qual das duas é uma posição é valida, pois
já que no primeiro caso onde p[n-1] == q[n-1] ou p[n] == q[n], é so inverter que isso será válido,pois nenhum elemento repete.
