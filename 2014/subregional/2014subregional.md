---
layout: default
---

# 2014

## Subregional

### A - Volta
Precisamos achar a primeira volta **V** tal que o tempo total que o piloto mais rápido passou na pista antes de completá-la é menor ou igual ao tempo que o piloto mais lento passou na pista antes de completar a volta **V-1**, ou seja, devemos achar o menor **V** tal que **V×X <= (V-1)×Y**. 
 Logo, **V = ⌈ Y  ÷ (Y-X) ⌉**.

_LeticiaFCS_

**Link:** [URI 1708](https://www.urionlinejudge.com.br/judge/pt/problems/view/1708) 

**Código:** [A - Volta](./a.cpp)

### B - Baralho Embaralhado
Para resolver o problema basta perceber que quando uma carta volta a sua posição original todas as outras cartas voltam também. Podemos escolher uma carta e executar a simulação do embaralhamento mantendo um contador do número de passos da seguinte forma: se sua posição **pos** (indexada de 0) está na primeira metade do baralho, ela vai para a posição **2×pos+1**, se não ela vai para a posição **2×(pos - p/2)**.

_LeticiaFCS_

**Link:** [URI 1709](https://www.urionlinejudge.com.br/judge/pt/problems/view/1709) 

**Código:** [B - Baralho Embaralhado](./b.cpp)

### C - Confederação
Precisamos descobrir em que região cada planeta está, para isso percebemos que a equação dos planos foi dada como **Ax + By + Cz = D**, se aplicarmos as coordenadas de um ponto na fórmula **L = Ax + By + Cz - D** nós sabemos de qual lado de um plano ele está dependendo se seu valor for positivo ou negativo. Podemos criar uma máscara binária para cada planeta que será verdadeira na posição de um plano se **L** for positivo e falsa caso contrário, essa máscara identificará em qual região ele está. Depois só precisamos contar quantas vezes cada máscara apareceu e imprimir a frequência da máscara mais frequente.

_LeticiaFCS_

**Link:** [URI 1710](https://www.urionlinejudge.com.br/judge/pt/problems/view/1710) 

**Código:** [C - Confederação](./c.cpp)

### D - Dona Minhoca
Há duas possibilidades para a Dona Minhoca conseguir voltar ao mesmo buraco sem bater no seu rabo, ou ela já está em um **ciclo com tamanho <= tamanho da minhoca** ou ela precisa ir até um ciclo que respeite essa condição para "dar a volta" e retornar ao seu buraco. Podemos fazer uma dfs marcando quais vértices estão em um ciclo e também guardar o tamanho de cada um deles. Depois para cada minhoca nós fazemos um Dijkstra em que sempre que chegamos em um vértice **v** que faz parte de um ciclo com tamanho maior ou igual ao tamanho da Dona Minhoca (desde que não seja o ciclo que ela estava inicialmente) nós guardamos o mínimo entre a resposta anterior e **2** vezes a distância até **V** mais o tamanho do ciclo de **V**. Caso a minhoca já estivesse em um ciclo válido inicialmente nós pegamos o mínimo entre a resposta do Dijkstra e o tamanho do ciclo inicial.

_LeticiaFCS_

**Link:** [URI 1711](https://www.urionlinejudge.com.br/judge/pt/problems/view/1711) 

**Código:** [D - Dona Minhoca](./d.cpp)

### E - Ecologia
Nós começamos gerando o [poliminó](https://pt.wikipedia.org/wiki/Polimin%C3%B3) com **tamanho = m**. Podemos fazer isso usando como base o poliminó com **tam = 1** que é somente o bloco **{0,0}** e para cada poliminó de tamanho **T** ir acrescentando blocos nas bordas para criar os poliminós com tamanho **T+1**. Temos que tomar o cuidado de não gerar poliminós repetidos, para isso podemos manter sempre o bloco **{x,y}** lexicograficamente menor de um poliminó como o par **{0,0}**, caso isso não seja verdade em dado momento nós diminuímos o par **{x,y}** de todos o blocos do poliminó e só armazenamos os poliminós ainda não armazenados. Depois para cada posição da matriz tentamos colocar cada poliminó de tamanho **m** e caso isso seja possível somamos os valores da matriz que ficaram embaixo de um bloco do poliminó guardando a maior soma encontrada.

_LeticiaFCS_

**Link:** [URI 1712](https://www.urionlinejudge.com.br/judge/pt/problems/view/1712) 

**Código:** [E - Ecologia](./e.cpp)

### F - Teletransporte
Usando o fato de que quando consideramos uma potência **K** de uma matriz de adjacências a célula **{i,j}** dessa matriz representa o número de caminhos de tamanho **K** de **i** para **j** nós só precisamos gerar essa matriz de adjacências e exponenciá-la tomando o cuidado de sempre guardar o módulo, podemos fazer isso com o método da exponenciação rápida. A resposta estará na célula **{S,T}**.

_LeticiaFCS_

**Link:** [URI 1713](https://www.urionlinejudge.com.br/judge/pt/problems/view/1713) 

**Código:** [F - Teletransporte](./f.cpp)

### G - Letras
Como o problema só usa 26 letras podemos criar uma máscara de bits para cada configuração de letras maiúsculas/minúsculas e, para cada uma delas fazer uma BFS partindo da célula **{1,1}** respeitando a máscara e computando a distância de cada célula à célula inicial. Devemos a cada busca guardar a menor distância entre as células **{1,1}** e **{N,N}**.

_LeticiaFCS_

**Link:** [URI 1714](https://www.urionlinejudge.com.br/judge/pt/problems/view/1714) 

**Código:** [G - Letras](./g.cpp)

### H - Handebol
Para cada jogador devemos percorrer sua linha incrementando um contador de em quantas partidas esse jogador fez pelo menos um gol. Se o contador chegou ao número total de partidas incrementamos a resposta.

_LeticiaFCS_

**Link:** [URI 1715](https://www.urionlinejudge.com.br/judge/pt/problems/view/1715) 

**Código:** [H - Handebol](./h.cpp)

[voltar](https://leticiafcs.github.io/Maratona-de-Programacao/)


