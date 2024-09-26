# Algoritmo de Huffman
O algoritmo de Huffman é um algoritmo de compressão *lossless*, ou seja é uma compressão que não possui qualquer perda de dados ou da qualidade dos mesmos.


## Funcionamento
1. Conte a frequência de cada pedaço de informação acontece.
2. Construir uma árvore binária começando com os nós com as menores contagens. O novo nó pai tem seu valor como sendo a soma dos seus nós filhos.
3. O nó da esquerda dos pais recebem $0$, e $1$ para os nós filhos da direita.
4. Na árvore binária finalizada, siga as arestas adicionando $0$ ou $1$ para cada galho, para encontrar o novo código de Huffman para cada pedaço de dado.
5. Crie o código de Huffman convertendo os dados, parte por parte, em um código binário usando a árvore binária.

## Implementação parcial feita em Rust

## Benchmark
