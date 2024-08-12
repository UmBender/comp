# Road Construction

<br>
refs: "https://cses.fi/problemset/task/1676/"


<br>

## Solução
A solução é simples, apenas utilize a estrutura de dados Disjoint Set Union para
controlar a adição de estradas, já que cada cidade pode ser modelada como um conjunto
unitário e a criação de estradas como sendo a união entre esse dois conjuntos.
E para controlar tanto o número de cidades desconectas quanto o conjunto com o maior número de cidades
conectas é criado as variáveis internas `max_size_set` e `sets` respectivamente, ambas tendo complexidade
O(1), já a busca e a união são O(n).
