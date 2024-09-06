# Knapsack 2 

<br>
refs: "https://atcoder.jp/contests/dp/tasks/dp_e"


<br>

## Solução
Neste caso a solução é considerando o fato que não poderemos construir uma dp
bidimensional para os pesos, pois os pesos são até 10^9 teremos que utilizar outra abordagem,
esta será utilizar todas as possíveis somas de valores e o pesos minimo realcionado a elas
basta observar que os teremos apenas 100 objetos no máximo, então basta ordenalos
para termos os menores valores com os menores pesos.

Agora basta fazer uma dp da seguinte forma
dp[j] = min(dp[j - objetos[i].valores] + objetos[i].peso, dp[j]), porém
devemos observar que a dp deve ser inicializada com dp[j] = INF, pois assim garantimos
que os valores não irão ser zero, já quando os objetos irão passar pela primeira vez podemos
ver que de fato se não houver nenhum casos que os a dp seja forçada para um valor diferente de INF
teremos que não há solução, então sempre que j == objetos[i].valores nós fazemos uma dp
da seguinte for dp[j] = min(dp[j], objetos[i].pesos), assim desta forma sabemos que ao menos em um
caso o valor será diferente de inf.
E teremos que fazer o acesso de traz para frente, j comeca em n * max_val e termina em 1, pois se formos
acessando cada valor de dp[j] e alterando de frente para tras iremos gerar casos inconsistente onde colocamos
o mesmo objeto duas vezes, tipo um objeto de valor 10 e max_val * n == 100, então se formos de frente para 
tras veremos que agora haverá valores diferentes de inf em 10, 20, 30, ..., 90 e 100, pois o caso de 20 olha para
o de 10, o de 30 para o de 20 e assim por diante.

Então a formula final sera dp[j], se j < 0 e j < objeto[i].valores = INF; dp[j] = min(dp[j], objeto[i].peso), se j == objeto[i].valores;
dp[j] = min(dp[j], dp[j - objeto[i].valores] + objeto[i].peso), se j < objeto[i].valores
 
