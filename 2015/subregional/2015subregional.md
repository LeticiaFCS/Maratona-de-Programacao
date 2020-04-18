---
layout: default
---

# 2015

## Subregional

### A - Mania de Par
A solução do problema é fazer um _Dijkstra_ modificado em que em vez de um vetor de distâncias nós temos uma matriz de distâncias **dist** em que **dist[v][0]** representa a distância da cidade de Patrícia para **v** passando por um número par de pedágios e **dist[v][1]** passando por um número ímpar de pedágios. Usamos como base **dist[1][0] = 0** e uma vez que estamos em um vértice **u** analisando uma aresta para **v** com valor **G** consideramos **dist[u][0] + G** como novo valor para **dist[v][1]** e consideramos o caso análogo para **dist[v][0]**.
 Se a resposta existir estará em **dist[C][0]**.

_LeticiaFCS_

**Link:** [URI 1931](https://www.urionlinejudge.com.br/judge/pt/problems/view/1931) 

**Código:** [A - Mania de Par](./a.cpp)

### B - Bolsa de Valores
Podemos resolver o problema com programação dinâmica, temos **pd[d][0]** que é o lucro máximo até o dia **d** se o investidor não comprar a ação **d** e **pd[d][1]** é o lucro máximo até o dia **d** se ele comprá-la.
 Os casos base são: **pd[0][0] = -infinito** e **pd[0][1] = 0**.
 As transições são: **pd[d][0] = maximo(pd[d-1][1] + v[d], pd[d-1][0])** e **pd[d][1] = maximo(pd[d-1][1], pd[d-1][0] - p[d] - c)**.

_LeticiaFCS_

**Link:** [URI 1932](https://www.urionlinejudge.com.br/judge/pt/problems/view/1932) 

**Código:** [B - Bolsa de Valores](./b.cpp)

### C - Tri-du
A resposta é sempre **maximo(a,b)**. Se **a** e **b** são iguais o melhor será fazer um trio usando outra carta de valor = **a**(ou **b**), caso contrário será melhor fazer uma dupla com o valor **maximo(a,b)**.

_LeticiaFCS_

**Link:** [URI 1933](https://www.urionlinejudge.com.br/judge/pt/problems/view/1933) 

**Código:** [C - Tri-du](./c.cpp)

### D - Quebra-cabeça
Podemos resolver o problema buscando, a cada iteração, uma linha/coluna ainda não resolvida que possua uma única variável **v** com valor desconhecido e armazenando a quantidade **q** de vezes que ela apareceu na linha/ coluna, o valor de **v** será **(soma da linha/coluna -  Σ variáveis conhecidas da linha/coluna) ÷ q**. Como a cada iteração resolvemos uma linha ou coluna executarémos no máximo **L × C** iterações.

_LeticiaFCS_

**Link:** [URI 1934](https://www.urionlinejudge.com.br/judge/pt/problems/view/1934) 

**Código:** [D - Quebra-cabeça](./d.cpp)

### E - Espiral
Na e-ésima volta da espiral andamos **4*[n - 2*(e-1)] - 4** posições. Se somarmos todas as posições que andamos até chegar ao fim da e-ésima espiral teremos um somatório até **e**: 

 **Σ{4*[n - 2*(k-1)] - 4}**
 **= Σ[4*n - 4 - 8*(e-1)]**
 **= (4*n - 4)*e - 8*PA(e-1)]**

Podemos fazer uma busca binária nesse somatório (até a espiral de índice **⌈n÷2⌉**) e assim descobrir em qual espiral **e** está o feijão. Depois descobrimos em qual posição dessa espiral ele está andando (a partir da posição **[e,e]**) em cada lado dela o mínimo entre o tamanho do lado menos um e o número de posições que faltam para **b**.

_LeticiaFCS_

**Link:** [URI 1935](https://www.urionlinejudge.com.br/judge/pt/problems/view/1935) 

**Código:** [E - Espiral](./e.cpp)

[voltar](https://leticiafcs.github.io/Maratona-de-Programacao/)
