# Problema da Moeda

O enunciado do problema da moeda é simples, dado um conjunto de moedas $\text{Coins} = \{c_1,c_2,\dots, c_n\}$, e um valor alvo $S$, a tarefa é encontrar uma forma de atingir $S$ apenas somando os valores das moedas com o menor número de moedas possíveis.

É possível ver que para encontrar a solução deste problema pode ser utilizada uma abordagem de algoritmos gulosos, apenas pegando os valores das maiores moedas, mas isso se deve ao tipo de problema que estamos lidando e que não necessariamente vai ser verdade em outros casos, onde apenas pegar o maior valor chegará na solução ótima.

Agora para resolver esse problema de forma ótima iremos utilizar de técnicas de programação dinâmica, que irá gerar uma solução ótima para qualquer conjunto de moedas e valor alvo.
A técnica que será utilizada será um algoritmo recursivo que irá calcular todas os possíveis resultados, mas que irá utilizar técnicas de mnemonização, assim se tornando realmente eficiente.

A parte difícil da programação dinâmica é reformular o problema de tal forma que seja definido em uma expressão recursiva que o defina com o objetivo de que a solução seja possível de ser calculada com base em soluções de subproblemas menores.

Para isso iremos definir a função recursiva,$\text{solve}(x)$, que irá nos dar o menor número de moedas utilizadas para atingir um certo valor de soma $x$, os valores gerados dependem no conjunto de moedas disponíveis.


## Exemplo
Para o conjunto de moedas $\text{coins} = \{1,3,4\}$, para os primeiro valores alvos os números de moedas são:
$$
\text{solve}(0) = 0
$$
$$
\text{solve}(1) = 1 
$$
$$
\text{solve}(2) = 2 
$$
$$
\text{solve}(3) = 3 
$$
$$
\text{solve}(4) = 1 
$$
$$
\text{solve}(5) = 2
$$
$$
\text{solve}(6) = 2
$$
$$
\text{solve}(7) = 2
$$
$$
\text{solve}(8) = 4 
$$
$$
\text{solve}(9) = 3 
$$
$$
\text{solve}(10) = 3
$$

## Formulação
A propriedade principal é que o número de moedas necessárias pode ser calculado de forma recursiva com base em valores menores. A ideia é focar na primeira moeda que utilizamos para calcular a soma.

No caso de exemplo podemos ver que as primeiras moedas que podemos escolher para atingir a soma de dez são: $1,3,4$. Assim podemos calcular o número mínimo de moedas para atingir a soma de dez com base no número mínimo entre, um mais o número mínimos necessário para atingir nove, um mais o número para atingir sete e um mais o número necessário para atingir 6. 
Formulando de uma forma recursiva, a função que defini o número mínimo de moedas para atingir uma certa soma para o dado conjunto de moedas é da seguinte forma.

$$
\text{solve}(x) = \text{min}(\text{solve}(x-1) + 1, \text{solve}(x-3) + 1, \text{solve}(x-4) + 1)
$$

O caso base da recursão é $\text{solve}(0) =0$, e agora podemos definir a forma em termos gerais, mas levando em consideração casos impossíveis, que são casos em que não há forma de atingir $x$ com um conjunto de moedas ou para valores negativos.

$$
\text{solve}(x) = \begin{cases}\infty, & \mbox{ se } x < 0 \\ 0  ,& \mbox{ se } x = 0\\ \text{min}_{c \in \text{Coins}} \text{solve}(x-c) + 1, & \mbox{ se } x > 0 \end{cases}
$$


## Primeira implementação
Implementando a função $\text{solve}(x)$ em *C++*, sem utilizar a mnemonização.
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 3, 4};

int solve(int x) {
	if (x < 0) {
		return -1;
	} else if (x == 0) {
		return 0;
	}
	int minn = INT_MAX;
	for (auto i : coins) {
		int test = solve(x - i);
		if (test == -1) {
			  continue;
		} else {
		  minn = min(minn, test + 1);
		}
	}
	if (minn == INT_MAX) {
		return -1;
	} else {
		return minn;
	}
}

int main() {
	cout << solve(10) << endl;
	
	return 0;
}
```

Este caso encontra o menor número de moedas necessárias para atingir a soma $x$, mas possuí uma péssima performance, já que da fato ele repete o cálculo de certos valores várias vezes, por exemplo no caso ótimo para dez, ele será escrito da seguinte forma 3 + 3 + 4, para atingir o valor 3 podemos utilizar 3 moedas de um ou apenas uma de três, já no caso de quatro, podemos usar 4 de um um de três mais uma de um ou apenas a de quatro, mas para calcular as possibilidades de quatro tivemos que calcular a de três novamente, então há um desperdício, já que o valor mínimo de três é calculado diversas vezes.

Após toda essa explicação entendemos o fato do por quê que iremos utilizar uma técnica de mnemonização.
Ela será simples, iremos construir um array de todos os valores de $0$ até $x$, onde cada posição nesse array irá indicar o número mínimo de moedas necessárias para atingir o valor de sua posição, ou seja, na posição um haverá o valor mínimo de moedas que serão necessárias para atingir o valor um.

O código com esta técnica ficará da seguinte forma.
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 3, 4};
vector<int> cases

int solve(int x) {
	if (cases[x] == -1) {
		if (x < 0) {
			return INT_MAX;
		} else if (x == 0) {
			cases[x] = 0;
			return 0;
		}
		
		int minn = INT_MAX;
		for (auto i : coins) {
			int test = solve(x - i);
			if (test == INT_MAX) {
				continue;
			} else {
				minn = min(minn, test + 1);
			}
		}
		cases[x] = minn;
		return minn;
	} else {
		return cases[x];
	}
}
int main() {
	int x = 10;
	cases.resize(x + 1);
	fill(cases.begin(), cases.end(), -1);
	cout << solve(x) << endl;
	
	return 0;
}
```

O vetor *cases* irá guardar os valores já calculados como descrito anteriormente na definição da técnica de mnemonização. Desta forma o desempenho do programa aumenta consideravelmente. Quando o valor do elementos na posição $x$ em *cases* for igual à *-1*, significa que esse valor mínimo ainda não foi calculado, se for *INT_MAX* significa que impossível atingir esse valor, já quando não é nenhum dos dois significa que o valor mínimo de moedas para gerar aquele valor *x* é o valor do elemento.

## Construção de solução
De fato em algumas questões não é apenas necessário o número mínimo de moedas necessárias, mas sim uma forma de construir essa solução. O código pode ser alterado para construir uma solução da seguinte forma.
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 3, 4};
vector<int> cases;
vector<int> gens;

int solve(int x) {
	if (cases[x] == -1) {
		if (x < 0) {
			return INT_MAX;
		} else if (x == 0) {
			cases[x] = 0;
			gens[x] = 0;
			return 0;
		}
		int minn = INT_MAX;
		for (auto i : coins) {
			int test = solve(x - i);
			if (test == INT_MAX) {
				continue;
			} else {
				if (minn > (test + 1)) {
					gens[x] = x - i;
					minn = test + 1;
				}
			}
		}
		cases[x] = minn;
		return minn;
	} else {
		return cases[x];
	}
}

int main() {
	int x = 10;
	cases.resize(x + 1);
	gens.resize(x + 1);
	fill(cases.begin(), cases.end(), -1);
	fill(gens.begin(), gens.end(), -1);
	cout << solve(x) << endl;
	vector<int> solution;
	int pos = x;
	while (gens[pos] != pos) {
		solution.push_back(pos - gens[pos]);
		pos = gens[pos];
	}
	for_each(solution.begin(), solution.end(), [=](int &i) { cout << i << ' '; });
	cout << endl;
	
	return 0;
}
```

Onde o vetor *gens* irá armazenar a posição do sub-caso que irá gerar o caso mínimo para atingir certo valor, podemos saber qual é a moeda utilizada simplesmente olhando a diferença entre $x$ e $gex[x]$.

## Versão alternativa
Agora considerando que devemos calcular o número de possíveis formas com que podemos formar uma soma com um dado conjunto de moedas, não necessariamente utilizando o menor número de moedas.

Neste caso podemos utilizar uma formulação semelhante para o problema, já que podemos escrever de forma recursiva apenas olhando o último cara que utilizamos para formar a soma determinada. O número de possíveis formas para atingir um certo valor dado um conjunto de moedas é igual a soma dos números de possibilidades dos casos onde o valor é igual o valor da soma menos o valor de uma determinada moeda.
$$
\text{solve}(x)  = \sum_{c_i}{\text{solve}(x-c_i)}
$$
Considerando o caso base onde $\text{solve}(0) = 1$ e que para valores de $x < 0$ o valor de $\text{solve}(x) = 0$, todos os outros casos são deriváveis com base na formula definida acima.
De forma mais geral, a função que conta o número das possíveis soluções é a seguinte.

$$
\text{solve}(x) = \begin{cases}\infty, & \mbox{ se } x < 0 \\ 1  ,& \mbox{ se } x = 0\\  \sum_{c_i}{\text{solve}(x-c_i)}, & \mbox{ se } x > 0 \end{cases}
$$

A implementação é simples, como demonstrada logo abaixo, sendo este um exemplo que já utiliza um vetor *sol* para a mnemonização dos casos anteriores, onde $\text{sol}[x]$ é o número de formas que podemos gerar o valor $x$.

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 3, 4};
vector<int> sol;

void solve(int x) {
	for (int i = 1; i <= x; i++) {
		for (auto j : coins) {
			if (j > i) {
				continue;
			}
			sol[i] += sol[i - j];
		}
	}
}

int main() {
	int x = 10;
	sol.resize(x + 1);
	fill(sol.begin(), sol.end(), 0);
	sol[0] = 1;
	solve(x);
	
	for_each(sol.begin(), sol.end(), [=](int &i) { cout << i << ' '; });
	cout << endl;
}
```

