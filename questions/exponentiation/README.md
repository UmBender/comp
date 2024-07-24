# Exponentiation 

<br>
refs: "https://cses.fi/problemset/task/1095/"


<br>

## Solução

A questão é que se for fazer a vezes a b vezes seria linear. Desta forma
para quebrar a complexidade faz os seguinte, calcula a elevado a b/2 e 
multiplica esse valor por ele mesmo, e se for b um valor impar multiplica esse valor por a.
Desta forma a complexidade se torna O(log(b)), pois como dividimos b pela metade toda a vez, até chegar em 1
a complexidade dele é k, tal que 2^k = ceil(b).

