# Introdução
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
