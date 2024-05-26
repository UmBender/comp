#Chuva

<br>
refs: "https://olimpiada.ic.unicamp.br/static/extras/obi2022/provas/ProvaOBI2022_f1ps.pdf"


<br>

## Solução

Primeiro faz a soma de prefixo, então dado um valor x, procura x + target
na soma de prefixo o primeiro que aparece no vetor da soma de prefixo e o último, ambos utilizando
bsuca binária, então soma diferença entre esses dois valores mais um, para encontrar os valores que
satisfazem essa restrição. Isso é feito para cada elemento do array, dando uma complexidade O(n*log(n)).
