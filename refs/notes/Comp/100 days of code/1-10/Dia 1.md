# Fila de prioridade
A fila de prioridade é uma estrutura de dados que mantém um conjunto de elementos e a cada elemento uma prioridade associada.
## Operações
 - Inserção
 - Remoção do elemento de maior prioridade


## Implementação eficiente na remoção
Apenas é uma lista ligada que mantemos ordenados de forma decrescente
* Inserção($\text{O}(n)$): varrer a lista até encontrar a posição correta do elemento.
* Remoção($\text{O}(1)$): apenas remover o primeiro elemento.


## Implementação eficiente na inserção
Apenas é uma lista ligada que não se mantem nenhum tipo de ordem:
* Inserção($\text{O}(1)$): Apenas insere logo no início da lista.
* Remoção($\text{O}(n)$): Busca sobre toda a lista o elemento que tem maior prioridade.

## Implementação eficiente
Utiliza um *heap* máximo.
* Inserção($\text{O}(\text{log}(n))$): Apenas insere logo no início da lista.
* Remoção($\text{O}(\text{log}(n))$): Busca sobre toda a lista o elemento que tem maior prioridade.
### *Heap* máximo
Um *heap* é basicamente é uma árvore binária onde a raiz de toda subárvore é o maior valor naquela subárvore, desta forma sempre que formos remover um valor iremos remover a raiz da árvore. Em particular iremos exigir que apenas o último nível da árvore que pode ser incompleto e, nesse nível, se incompleto, os nós devem estar todos "encostados à esquerda". 

### Inserção
A inserção é simples, o *heap* pode ser implementado com uma lista simples onde o nó raiz está na posição 1, e todos os nós filhos, se houverem, estarão nas posições $2n$ e $2n+1$, considerando que $n$ seja a posição do nó pai. Então para adicionar simplesmente adicionamos o elemento novo na posição $x + 1$, onde $x$ é o tamanho antigo do *heap*, e vamos fazendo a operação de balanceamento, ou seja, caso o nó que está na posição $\frac{x}{2}$, se estiver trocamos os elementos e atualizamos $x:=\frac{x}{2}$, desde que seja $x \neq 0$.

### Remoção
Para remoção fazemos algo semelhante, pegamos o maior elemento, e então colocamos o valor que está na última posição na primeira e fazemos o balanceamento, mandando este valor para baixo até que ele seja maior que todos seus filhos.


### Implementação
```cpp
template <typename T> struct Heap {
	size_t size, used;
	
	pair<int, T> *heap;
	Heap(size_t size) : size(size), used(0) { 
		heap = new pair<int, T>[size + 1]; 
	}
	~Heap() { delete heap; }
		void insert(T val, int prior) {
		used++;
		int pos = used;
		heap[pos] = make_pair(val, prior);
		while (pos / 2 
				&& heap[pos].second > heap[pos / 2].second) {
			swap(heap[pos], heap[pos / 2]);
			pos /= 2;
		}
	}
	T get_val() {
		T return_value = heap[1].first;
		heap[1] = heap[used];
		used--;
		int k = 1;
		while (2 * k <= used && 
		(heap[k].second < heap[k * 2].second ||
		heap[k].second < heap[k * 2 + 1].second)) {
			if (heap[2 * k] > heap[2 * k + 1]) {
				swap(heap[k], heap[2 * k]);
				k *= 2;
			} else {
				swap(heap[k], heap[2 * k + 1]);
				k *= 2;
				k++;
			}
		}
	return return_value;
	}
};
```




