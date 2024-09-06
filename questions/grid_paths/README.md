# Grid Paths

<br>
refs: "https://cses.fi/problemset/task/1638"


<br>

## Solução
A abordagem é simples, como sabemos que os únicos movimentos que são permitidos são para baixo e 
para direita podemos definir uma $\text{dp}$ bi-dimensional de tamanho $n\times n$ , 
onde cada posição nessa é definida da seguinte maneira, a posição inicial, ou seja,  
$\text{dp}[0][0] = 1$, se essa posição não for armadilha, 
nos outros casos $\text{dp}[i][j] = \text{max}(\text{dp}[i-1][j],0) + \text{max}(\text{dp}[i][j-1], 0)$,
e para os casos onde $\text{dp}[i][j] = 0, \mbox{ se } j < 0 \lor i < 0$. 

Desta forma basta passar de coluna por coluna e linha por linha para popular essa $\text{dp}$,
e o resultado do número máximo de caminhos possíveis será $\text{dp}[n-1][n-1]$.

