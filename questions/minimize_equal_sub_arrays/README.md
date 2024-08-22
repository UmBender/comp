# Minimize Equal Sum Subarrays

<br>
refs: "https://codeforces.com/contest/1998/problem/B"


<br>

## Solução
A solução é simples, a parte difícil é entender o problema.
Basicamente o que ele quer dizer é que deve se minimizar
o número de intervalos p_i + ... + p_j = q_i + ... + q_j,
ou seja, que a permutação q tenho o menor número de sub arrays
que a soma sejam iguais ao mesmo intervalo em p. 
Por exemplo, p_2 + p_3 + p_4 = q_2 + p_3 + p_4.
Então é fácil ver que no mínimo vai haver um sub array
que a soma de p[i,j] = soma de q[i,j], que é de [1,n],
já que ambos devem ter o mesmo elementos, então a somas 
devem ser iguais.
Mas, também, por serem permutações, os elementos são únicos,
então quer dizer que se p_i + ... + p_j, então se mover
um para o lado não será possível chegar no valor, pois
como o intervalo é fixo, então se saiu um valor x, para 
que mantenha a soma tem que entrar esse mesmo valor x.
Desta forma então basta mover todos os elementos um para esquerda
e colocar o primeiro elemento ao final do array.
