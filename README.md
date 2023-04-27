# BFS e DFS

# O que é BFS
<div align="justify">
	
**Breadth-First Search (BFS)** ou **Busca em Largura**, é um algoritmo de busca em grafo que começa a explorar a partir do vértice raiz e visita todos os seus vizinhos primeiro, antes de se mover para o próximo nível de vizinhos. Em outras palavras, ele explora todos os vértices a uma distância "d" antes de explorar qualquer vértice a uma distância "d+1".
	
É um método para percorrer todos os vértices de um grafo, visitando todos os vértices a uma determinada distância antes de passar para o próximo nível de distância. Ele começa a partir de um vértice inicial (também chamado de raiz) e explora todos os vértices que estão a uma distância de um passo da raiz antes de passar para os vértices que estão a uma distância de dois passos da raiz, e assim por diante.
	
</div>

# O que é DFS?
<div align="justify">
	
**Depth-First Search (DFS)** ou **Busca em Profundidade**, é um algoritmo de busca em grafo que começa a explorar a partir do vértice raiz e visita um caminho o mais profundo possível antes de retroceder. Em outras palavras, ele explora um ramo inteiro do grafo antes de voltar e explorar outro ramo.

É um método para percorrer todos os vértices de um grafo, visitando um caminho o mais profundo possível antes de retroceder. Ele começa a partir de um vértice inicial (também chamado de raiz) e explora todo o caminho para baixo até chegar a um vértice sem filhos ou a um vértice que já foi visitado. Em seguida, ele retrocede e explora o próximo caminho não visitado até que todos os vértices do grafo tenham sido visitados.
	
Uma das principais diferenças entre o algoritmo **DFS** e o algoritmo **BFS** é que o **DFS** explora um ramo inteiro do grafo antes de retroceder e visitar outro ramo, enquanto o BFS explora todos os vértices a uma determinada distância do vértice inicial antes de passar para o próximo nível de distância.
	
</div>

# Análise do Problema

# Solução do Problema

# Conclusão

# Compilação e Execução 

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo nomeado preferencialmente de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o seguinte formato:
	
- Em sua primeira linha: os valores NxN que serão assumidos pelas matrizes geradas
- Logo em seguida as matrizes espaçadas conforme o exemplo abaixo
</p>

<p align="center">
<img src="" width="250"/> 
</p>
<p align="center">
<em>Imagem X: Descrição.</em>
</p>

<p align="justify">
Por fim, esse programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
</p>

| Comando                |  Função                                                                                               |                     
| -----------------------| ------------------------------------------------------------------------------------------------------|
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                            |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build               |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                     |

## Contatos

| Participante           |  Contato                                                                                               |                     
| -----------------------| ------------------------------------------------------------------------------------------------------|
|  Celso                 | <a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       |
|  Pedro                 | <a href="https://t.me/phpdias"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       |

</div>
