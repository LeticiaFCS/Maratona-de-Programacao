---
layout: default
---

# 2014

## Subregional

### A - Volta
Precisamos achar a primeira volta **V** tal que o tempo total que o piloto mais rápido passou na pista antes de completá-la é menor ou igual ao tempo que o piloto mais lento passou na pista antes de completar a volta **V-1**, ou seja, devemos achar **V** tal que **V×X <= (V-1)×Y**. 
 Logo, **V = ⌈ Y  ÷ (Y-X) ⌉**.

_LeticiaFCS_

**Link:** [URI 1708](https://www.urionlinejudge.com.br/judge/pt/problems/view/1708) 

**Código:** [A - Volta](./a.cpp)

### B - Baralho Embaralhado
Para resolver o problema basta perceber que quando uma carta volta a sua posição original todas as outras cartas voltam também. Podemos escolher uma carta e executar a simulação do embaralhamento mantendo um contador do número de passos da seguinte forma: se sua posição **pos**(indexada de 0) está na primeira metade do baralho, ela vai para a posição **2×pos+1**, se não ela vai para a posição **2×(pos - p/2)**.

_LeticiaFCS_

**Link:** [URI 1709](https://www.urionlinejudge.com.br/judge/pt/problems/view/1709) 

**Código:** [B - Baralho Embaralhado](./b.cpp)

### C - Confederação
Precisamos descobrir em que região cada planeta está, para isso percebemos que a equação dos planos foi dada como **Ax + By + Cz = D**, se aplicarmos as coordenadas de um ponto na fórmula **L = Ax + By + Cz - D** nós sabemos de qual lado de um plano ele está dependendo se seu valor for positivo ou negativo. Podemos criar uma máscara binária para cada planeta que será verdadeira na posição de um plano se **L** for positivo e falsa caso contrário, essa máscara identificará em qual região ele está. Depois só precisamos contar quantas vezes cada máscara apareceu e imprimir a frequência da máscara mais frequente.

_LeticiaFCS_

**Link:** [URI 1710]https://www.urionlinejudge.com.br/judge/pt/problems/view/1710) 

**Código:** [C - Confederação](./c.cpp)

### D - Dona Minhoca
Há duas possibilidades para a Dona Minhoca conseguir voltar ao mesmo buraco sem bater no seu rabo, ou ela já está em um **ciclo com tamanho <= tamanho da minhoca** ou ela precisa ir até um ciclo que respeite essa condição para "dar a volta" e retornar ao seu buraco. Podemos fazer uma dfs marcando quais vértices estão em um ciclo e também guardar o tamanho de cada um deles. Depois para cada minhoca nós fazemos um Dijkstra em que sempre que chegamos em um vértice **v** que faz parte de um ciclo com tamanho maior ou igual ao tamanho da Dona Minhoca (desde que não seja o ciclo que ela estava inicialmente) nós guardamos o mínimo entre a resposta anterior e 2 vezes a distância até **V** mais o tamanho do ciclo de **V**. 

_LeticiaFCS_

**Link:** [URI 1711]https://www.urionlinejudge.com.br/judge/pt/problems/view/1711) 

**Código:** [D - Dona Minhoca](./d.cpp)

[voltar](https://leticiafcs.github.io/Maratona-de-Programacao/)


