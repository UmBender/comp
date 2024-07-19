Algumas anotações sobre a *standard template library* da linguagem C++, para facilitar a implementação de certos algoritmos.


## Vector
O *vector* é basicamente a uma implementação de array genérico, só que com tamanho variável. Ou seja é uma coleção de dados contíguos genéricos que podem crescer com o passar do programa. 
Desta forma é mais simples de lidar com array sem ter o problema de ficar manejando memória na mão.
Porém é importante saber que de fato que o que ocorre por de baixo dos panos é que o *vector*, mantém uma quantidade de espaço fixo, quando for adicionado um elemento à coleção todo os valores serão copiados de um espaço de memória para outro que seja suficientemente grande para guardar aquela coleção. O *vector* aumenta o tamanho da coleção mais que o necessário para que essa operação não seja repetida muitas vezes.
Quando há uma remoção o tamanho real alocado não muda, apenas diminui a variável que relata o número de valores armazenados.
Para importar o *template* genérico *vector* deve ser importada a biblioteca 
*vector* da seguinte forma.

```cpp
#include <vector>
```
Ele também está presente na biblioteca *bits/stdc++.h*
### Exemplo 1
```cpp
int main() {
	vector<int> colecao;
	int quantos;
	cin >> quantos;
	for(int i = 0; i < quantos; i++) {
		int temp;
		cin >> temp;
		colecao.push_back(temp);
	}
	return 0;
}
```

Desta forma vai sendo adicionado ao final do vetor os valores de entrada.
### Exemplo 2
```cpp
int main() {
	vector<int> arr(10);
}
```
Essa sintaxe viabiliza criar um vetor com um tamanho exato já alocado. O vetor inicializa os espaços alocados com o valor padrão do tipo. Para valores numérico é 0, para *string* é *""*.

### Exemplo 3

```cpp
int main() {
	vector<string> nomes(100, "Sem nome");
}
```
Com essa sintaxe podemos definir um tamanho inicial e o valor padrão para cada elemento, assim podemos criar um *vector* com valor padrão diferente do definido nas especificações
### Exemplo 4
```cpp
int main() {
	vector<vector<int>> matriz(10,vector<int>(10,3));
}
```
Podemos colocar outras coleções como o tipo do *vector*, até mesmo outro *vector*. Desta forma, por exemplo, podemos definir uma matriz 10 por 10, com todas os elementos sendo igual ao número 3.

### Exemplo 5
```cpp
int main() {
	vector<int> arr;
	arr.push_back(12);
}
```
A função *push_back* adiciona um elemento ao final do *vector*.

### Exemplo 6
```cpp
int main() {
	vector<int> arr(10,3);
	arr.pop_back();
}
```
A função *pop_back* remove um elemento do final do *vector*.

### Exemplo 7
```cpp
int main() {
	vector<int> arr(100, 1);
	cout << arr[10] << endl;
	cin >> arr[88];
}
```
Podemos usar os colchetes, igual a sintaxe de *C*, para acessar ou atribuir valores dos elementos do *vector*.

### Exemplo 8
```cpp
int main() {
	vector<int> arr(100, 1);
	cout << arr.at(10) << endl;
	cin >> arr.at(88);
}
```
Também podemos usar a função *at*, para acessar ou atribuir valores aos elementos de um *vector*.

### Exemplo 9
```cpp
int main() {
	vector<int> arr(100, 3);
	cout << arr.front() << endl;
	cin >> arr.back();
}
```
Podemos utilizar as funções *front* e *back* para acessar ou atribuir valores ao primeiro e último elemento do *vector*, respectivamente.
### Exemplo 10
```cpp
int main() {
	vector<int> arr(k);
	cout << arr.size() << endl;
}
```
Podemos utilizar a função *size* para acessar o valor do tamanho do *vector*.

### Exemplo 11
```cpp
int main() {
	vector<int> arr(k);
	arr.resize(100);
}
```
Podemos utilizar a função *resize* para alterar o tamanho do *vector*, se for para um valor menor que o atual, os últimos elementos serão perdidos.

### Exemplo 12
```cpp
int main() {
	vector<int> arr();
	if(arr.empty()){
		cout << "arr está vazio" << endl;
	}else{
		cout << "arr não está vazio"
	}
}
```
Podemos utilizar a função *empty*, para saber o *vector* está vazio ou não.
## Map
*Maps* são estruturas de dados que guardam dados formados por uma combinação de uma chve, *key value* e um valor mapeado, *mapped value*, seguindo uma ordem específica.
Em um *map*, as chaves são geralmente usadas para ordenar e como identificador único os elementos, enquanto os valores mapeados são o conteúdo armazenado associado para esta chave. Os tipos da chave e do valor podem ser diferentes, e são unidos como um *value_type*, o qual é o tipo *pair* combinando ambos.
```cpp
typedef pair<const Key, T> value_type;
```

Internamente, os elementos em um mapa são sempre ordenados por sua chave seguindo um critério *strict weak ordering* indicado pelo critério interno de comparação do objeto, então se for definir seu tipo próprio é necessário definir as operações de comparação entre objetos para utilizar este tipo como chave.

Algo importante de se notar é que o *Map* é, em média, mais devagar em acesso a elementos individuais, porém ele nos da a capacidade de iterar sobre subconjuntos de seus elementos com uma performance maior.
Isso se deve ao fato de que o *Map* é implementado com uma árvore rubro-negra, *red-black tree*, já o *unorderd_map* é feito utilizando um *hash-map*, ou seja, utilizando uma função *hash* para definir a posição que o determinado *bucket*, o início de uma lista ligada, vai estar.
É interessante notar que todas as operações em um *map* tem complexidade $O(log(n))$, como acesso, adição, remoção. Apenas iterar sobre todos os elementos e a complexidade em relação ao espaço são diferentes, $O(n*log(n))$ e $O(n)$ respectivamente.

| Operação    | Complexidade |
| ----------- | ------------ |
| Adição      | $O(log(n))$  |
| Remoção     | $O(log(n))$  |
| Acesso      | $O(log(n))$  |
| Modificação | $O(log(n))$  |
Pela própria natureza do *map*, por ser uma árvore rubro-negra, ele sempre está ordenada, então ser for iterar sobre os elementos do *map* as chaves estarão em ordem crescente.

## Exemplo 1
```cpp
int main() {
	map<chave,valor> mapa;
	return 0;
}
```
Para criar um *map* é necessário passar o tipo da chave e do valor que serão armazenados, sendo que a chave de implementar a operação de comparação e de ordem.
## Exemplo 2
```cpp
int main() {
	map<string,int> saldo;
	saldo["Gustavo"] = 12;
	cout << saldo["Gustavo"] << endl;
	return 0;
}
```
Para acessar, modificar e adicionar um elemento em um *map* pode ser utilizada a sintaxe de acesso e modificação de *array* do *C*, utilizando colchetes *[]*;
## Exemplo 3 
```cpp
int main() {
	map<string, int> saldo;
	saldo["Gustavo"] = 12;
	saldo.at("Gustavo") = 13;
	cout << saldo.at("Gustavo") << endl;
	return 0;
}
```
Para acessar e modificar um elemento em um *map* pode ser utilizada a função *at*, porém se o elemento não já existir no mapa ele irá gerar um erro.
## Exemplo 4
```cpp
int main() {
	map<string, int> saldo;
	saldo.insert(make_pair("Gustavo", 12));
	cout << saldo.at("Gustavo") << endl;
	saldo.erase("Gustavo");
	return 0;
}
```
Para inserir e remover elementos em um *map* podemos utilizar os métodos *insert* e *erase*, respectivamente. Para utilizar o *insert* deve ser passado um *pair* com os mesmo tipos da chave e valor do *map*. Já para a remoção é apenas a chave. Ambas as operações não sofrem problemas se uma elemento com a chave haver ou não no *map*, com o *insert* ele sobrescreve e o *erase* não faz nada.
## Exemplo 5
```cpp
int main() {
	map<string, int> saldo;
	cout << saldo.empty() << endl;
	cout << saldo.size() << endl;
	return 0;
}
```
Para acessar o tamanho e se o *map* está vazio ou não pode ser utilizado os método *size* e *empty* respectivamente.
## Exemplo 6
```cpp
int main() {
	map<string, int> saldo;
	saldo["Gustavo"] = 13;
	saldo["Carlos"] = 12;
	saldo.clear();
}
```
Para remover todos os elementos de um *map* pode ser utilizado a função *clear*.
## Exemplo 7
```cpp
int main() {
	return 0;
}
```
## Exemplo 1
```cpp
int main() {

	return 0;
}
```
## Exemplo 1
```cpp
int main() {

	return 0;
}
```
## Exemplo 1
```cpp
int main() {

	return 0;
}
```
# Unordered Map
TODO
## Set
TODO

## Iterators
TODO

## Bitset
TODO

## Dequeue
TODO

## Stack
TODO

## Queue
TODO

## Priority Queue
TODO


## Templates
TODO