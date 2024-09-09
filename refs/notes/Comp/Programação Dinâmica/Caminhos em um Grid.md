## Questão
[Caminhos em um grid](https://cses.fi/problemset/task/1638/)

## Definição

Dado um grid de pontos e armadilhas, de quantas voltas podemos chegar do ponto extremo superior esquerdo até o ponto extremo inferior direito.

## Solução
A abordagem é simples, como sabemos que os únicos movimentos que são permitidos são para baixo e para direita podemos definir uma $\text{dp}$ bi-dimensional de tamanho $n\times n$ , onde cada posição nessa é definida da seguinte maneira, a posição inicial, ou seja,  $\text{dp}[0][0] = 1$, se essa posição não for armadilha, nos outros casos $\text{dp}[i][j] = \text{max}(\text{dp}[i-1][j],0) + \text{max}(\text{dp}[i][j-1], 0)$, e para os casos onde $\text{dp}[i][j] = 0, \mbox{ se } j < 0 \lor i < 0$. 
Desta forma basta passar de coluna por coluna e linha por .linha para popular essa $\text{dp}$, e o resultado do número máximo de caminhos possíveis será $\text{dp}[n-1][n-1]$.

## Código
```cpp
#include<bits/stdc++.h>

#define mod ((int)1E9) + 7

void solution() {
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		for (int j = 0; j < word.size(); j++) {
			grid[i][j] = word[j] == '.' ? 0 : -1;
		}
	}
	grid[0][0] = grid[0][0] == 0 ? 1 : -1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == -1) {
				continue;
			}
			int counter = 0;
			if (i - 1 >= 0 && grid[i - 1][j] != -1) {
				counter += grid[i - 1][j];
				counter %= mod;
			}
			if (j - 1 >= 0 && grid[i][j - 1] != -1) {
				counter += grid[i][j - 1];
				counter %= mod;
			}
			grid[i][j] = max(grid[i][j], counter);
		}
	}
	cout << (grid[n - 1][n - 1] > 0 ? grid[n - 1][n - 1] : 0)
	 << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solution();
	
	return 0;
}
```