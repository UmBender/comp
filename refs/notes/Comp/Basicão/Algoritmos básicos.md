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
A busca binária é utilizada para descobrir se um certo elemento está ou não em um array ordenado e, se sim, a sua posição em uma complexidade menor que a busca linear, no caso $O(log_2(n))$.
```cpp
#include <algorithm>
int main() {
	int elementos[] = {1,2,4,5,6,8,11,15,19};
	int target = 11;
	int position = binary_search(
		elementos, elementos+9, target);
	cout << position << endl;
}
```

Uma explicação e aplicação mais completa está no arquivo próprio de [[Busca Binária]].


## STL
A [[STL]] do *C++*, é uma coleção de estruturas de dados e algoritmos extremamente úteis, não só no caso de computação competitiva mas como para desenvolvimento *C++* no geral.

