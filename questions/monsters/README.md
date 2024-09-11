# Monsters

<br>
refs: "https://cses.fi/problemset/task/1194/"


<br>

## Solução

A solução é bem simples, basta construir um grafo e armazenar todos os monstros em uma queue,
como também os 'A's em outra, desta forma basta fazer uma bfs alternada, onde primeiro
consome todos os monstros que podem fazer um movimento e depois faz o movimento que custam
um para o 'A', vendo se ganho, se não já foi acessado, fazendo isso de forma alternada,
e armazenado todos os caminhos do 'A' que foram feito.
