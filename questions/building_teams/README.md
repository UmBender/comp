# Building Teams

<br>
refs: "https://cses.fi/problemset/task/1668/"


<br>

## Solução

Basicamente é uma bfs qua vai pintando os filhos com a cor oposta dos pais.
Quando encontra um filho já pintado com cor igual então dá que é impossível.
Já quando um filho já tá pintado mas com cor oposta só não adiciona na queue, e continua
o processo de pintura.
