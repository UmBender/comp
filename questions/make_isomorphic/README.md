# Make Isomorphic

<br>
refs: "https://atcoder.jp/contests/abc371/tasks/abc371_c"


<br>

## Solução
A solução é simples, apenas trabalhosa, é feito a matriz de adjacencia de h,g e do custo de alteracao de h.
E basta passar por todas as possiveis permutacoes para ver qual delas eh a mais barata, isso pode
ser feito utilizando um vector de suporte que representa a permutacao dos nós de h, já que o nó
1 de h pode ser qualquer no de g.

