Anotações sobre algoritmos básicos para computação competitiva.

## Algoritmos de ordenação
Uma classe algoritmos básicos que é extremamente útil são os algoritmos de ordenação. 

No geral iremos utilizar o *gnu sort*, que possuí um complexidade $O(n*log(n))$. É uma mistura de *selection, merge e heap sort*.

```cpp
vector<int> values = {3,5,1,4,2};
sort(values.begin(), values.end());
// Pode ser feito de traz para frente
sort(values.rbegin(), values.rend());

int n = 7;
int a[] = {4, 2, 5, 3, 5, 8, 3};
sort(a,a+n);

string s = "monkey";
sort(s.begin(), s.end());
```

Também há uma alternativa que é o *counting sort*, que utiliza os valores como chave, tendo uma complexidade computacional $O(n)$. Porém a complexidade em espaço será proporcional a tamanho das chaves, ou seja se as chaves forem muito grandes, por exemplo $0 \leq x \leq 10^9$, terá um espaço ocupado em memória de 1 giga byte, desta forma sendo a limitado essa abordagem para algumas aplicações.

### Operação de comparação em C++
Dado que há sobrecarga de operadores em C++, é possível definir as operações de $>, <, \leq, \geq, =, \neq$ para estruturas de dados diferentes, que não são as básicas, já presentes no C. Isso nos da a capacidade de ordenar certas coleções com algoritmos de ordenação já definidos.
Por exemplo:
```cpp
vector<pair<int,int>> v;
v.push_back({1,5});
v.push_back({2,3});
v.push_back({1,2});

sort(v.begin(), r.begin());
```

Até mesmo para tipos que possuem um número arbitrário de atributos, por exemplo:
```cpp
vector<tuple<int,int,int>> v;
v.push_back({2,1,4});
v.push_back({1,5,3});
v.push_back({2,1,3});
sort(v.begin(), v.end());
```

Podemos definir as operações de comparação de certos tipos utilizando sobrecarga de operadores. Por exemplo
```cpp
struct A {
	int x, y;
	bool operator<(const P &p) {
		if(x != p.x) return x <p.x;
		else return y < p.y;
	}
}
```

Assim é possível ordenar coleções de tipos novos.

Outra possibilidade é utilizar uma função para comparação, passando essa função como argumento na função de *sort*, assim podendo criar um novo critério para definir comparação.

```cpp
bool comp_by_size(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
```

Assim podendo ordenar um lista de *string's*, antes, pelo seu tamanho e depois pela ordem alfabética.

```cpp
sort(v.begin(), b.end(), comp);
```

## Busca binária

Dada uma coleção ordenada, ou uma função que sabemos que estritamente crescente, e temos um *target*, queremos saber se nessa coleção há, ou se essa função gera, esse *target*, e qual seria, supostamente, a posição deste valor ou qual é o parâmetro da função para gerar este valor.

A busca binária utiliza a forte hipótese de que a coleção é ordenada, então, dado um limite inferior, e um limite superior, calculamos/ testamos o valor entre esses dois limites, assim podendo encontrar o valor em si, ou descartando metade de todos os possíveis valores, pois assumindo que o valor não seja o que gera o *target*, sabemos que então ele gera um valor menor ou maior. Assim podendo buscar nos valor a direita ou esquerda do *target*.

```cpp
int function(int val){
	...
}

int busca_binaria(int target, int up, int down) {
	while(down <= up) {
		int middle = down + (up - down)/2;
		if(function(middle) == target) {
			return middle
		}
		if(function(middle) < target) {
			down = middle + 1;
		}else{
			up = middle - 1;
		}
		return -1;
	}
}
```

Por isso, assumindo que o função/o acesso em memória feitos na busca binária seja $O(1)$, então a busca terá a complexidade $O(log_2(n))$. De uma forma mais geral, a busca binária terá complexidade $O(log_2(n) * f(k))$, sendo $f(k)$ a complexidade do acesso do valor de *target*.

Desta forma também podemos utilizar para encontrar os mínimos/máximos valores que satisfazem certa propriedade. Por exemplos, sabemos que $f(x)$ é crescente, porém a diversos valores para $x$ que satisfazem a expressão, mas queremos encontrar o mínimo/máximo valor que satisfazem a expressão $f(x) = \text{target}$.
Para encontrarmos o menor valor que satisfaz isso, apenas fazemos uma busca binária que o *target* é o valor que.
$$
	f(x) = \text{target}
$$
$$
	f(x-1) < \text{target}
$$

Ficando a busca binária da seguinte forma:
```cpp
int function(int val){
	...
}

int busca_binaria(int target, int up, int down) {
	while(down <= up) {
		int middle = down + (up - down)/2;
		if(function(middle) == target && 
			function(middle - 1) < target) {
			return middle
		}
		if(function(middle) < target) {
			down = middle + 1;
		}else{
			up = middle - 1;
		}
		return -1;
	}
}
```

Já para o caso que queremos saber o máximo valor que satisfaz, ou seja:
$$
	f(x) = \text{target}
$$
$$
	f(x+1) > \text{target}
$$

O código ficará da seguinte forma:
```cpp
int function(int val){
	...
}

int busca_binaria(int target, int up, int down) {
	while(down <= up) {
		int middle = down + (up - down)/2;
		if(function(middle) == target && 
			function(middle + 1) > target) {
			return middle
		}
		if(function(middle) < target) {
			down = middle + 1;
		}else{
			up = middle - 1;
		}
		return -1;
	}
}
```

Mostrando o quão flexível é a busca binária.
