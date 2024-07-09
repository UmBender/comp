## Notação O(n)

## Problemas P
Problemas P são problemas polinomiais. São considerados problemas tratáveis e consideravelmente rápidos. No geral é mais fácil listar os principais exemplos de problemas não polinomiais do que os polinomiais. Mas alguns exemplos são:
* $O(n)$
* $O(1)$
* $O(log(n))$
* $O(nlog(n))$
* $O(\sqrt n)$
* $O(n^2)$
* $O(n^3)$

## Problemas NP-hard
São problemas que não foram encontradas soluções polinomiais, ou seja, não foram encontradas soluções eficientes para estes problemas. Um exemplo é o problema do caixeiro viajante. Os dois principais exemplos são:
* $O(n!)$
* $O(2^n)$


## Estimativa de complexidade
Para não gastar tempo implementando soluções que não irão passar, é relevante estimar qual seria a complexidade máxima que pode ser utilizada para determinado problema dado são tamanho de `input` de entrada.

| Tamanho do input | Complexidade máxima     |
| ---------------- | ----------------------- |
| $n\leq 10$       | $O(n!)$                 |
| $n\leq 20$       | $O(2^n)$                |
| $n \leq 500$     | $O(n^3)$                |
| $n \leq 5000$    | $O(n^2)$                |
| $n \leq 10^6$    | $O(n log(n))$ ou $O(n)$ |
| $n \leq 10^9$    | $O(\sqrt n)$            |
| $n \geq 10^9$    | $O(log(n))$ ou $O(1)$   |


