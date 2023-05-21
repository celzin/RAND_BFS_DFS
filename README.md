# 
<div style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div><br/>

# Apresentação do Problema
<div align="justify">

O Problema em análise consiste na implementação de três modelos de caminhamento em uma matriz labirinto. 
	
Os modelos de caminhamento são: **Randômico** (já realizado e precisa ser adaptado), em **Largura (BFS)** e em **Profundidade (DFS)**;
	
A matriz tem tamanho N x N e contém quatro tipos de elementos: 
	
- **Passagem livre ( 1 )**; 
- **Item de dano ('*')**; 
- **Paredes ('#')**;
- **Ponto de parada ('?')** que é **colocado aleatoriamente** na matriz;

</div>

<p align="center">
<img src="imgs/bdfs.png" width="350"/> 
</p>
<p align="center">
<em>Imagem 1: Imagem esquemática do labirinto.</em>
</p>

<div align="justify">
	
O objetivo é percorrer toda a matriz a partir do ponto de partida até o ponto de parada, evitando as paredes e os itens de dano;
	
Se o algoritmo **encontrar um item de dano ('*')**, ele **deve retornar ao ponto de partida** e **reiniciar o caminhamento**, **demarcando o item de passagem livre (1) na posição do dano**;
	
Isso adiciona um custo adicional ao processo e permite avaliar a composição da entrada, o modelo de execução e o comportamento do algoritmo;
		
A matriz deve ser grande, com tamanho em torno de 50 x 50 ou maior, para permitir testes mais abrangentes;
	
O objetivo final é avaliar a implementação e o desempenho dos modelos de caminhamento em relação aos desafios impostos pela matriz labirinto.

</div>

# O que é BFS
<div align="justify">
	
**Breadth-First Search (BFS)** ou **Busca em Largura**, é um algoritmo de busca em grafo que começa a explorar a partir do vértice raiz e visita todos os seus vizinhos primeiro, antes de se mover para o próximo nível de vizinhos. Em outras palavras, ele explora todos os vértices a uma distância "d" antes de explorar qualquer vértice a uma distância "d+1".
	
É um método para percorrer todos os vértices de um grafo, visitando todos os vértices a uma determinada distância antes de passar para o próximo nível de distância. Ele começa a partir de um vértice inicial (também chamado de raiz) e explora todos os vértices que estão a uma distância de um passo da raiz antes de passar para os vértices que estão a uma distância de dois passos da raiz, e assim por diante.
	
</div>

<p align="center">
<img src="imgs/bfs.png" width="350"/> 
</p>
<p align="center">
<em>Imagem 2: Busca em Largura.</em>
</p>

# O que é DFS?
<div align="justify">
	
**Depth-First Search (DFS)** ou **Busca em Profundidade**, é um algoritmo de busca em grafo que começa a explorar a partir do vértice raiz e visita um caminho o mais profundo possível antes de retroceder. Em outras palavras, ele explora um ramo inteiro do grafo antes de voltar e explorar outro ramo.

É um método para percorrer todos os vértices de um grafo, visitando um caminho o mais profundo possível antes de retroceder. Ele começa a partir de um vértice inicial (também chamado de raiz) e explora todo o caminho para baixo até chegar a um vértice sem filhos ou a um vértice que já foi visitado. Em seguida, ele retrocede e explora o próximo caminho não visitado até que todos os vértices do grafo tenham sido visitados.
	
Uma das principais diferenças entre o algoritmo **DFS** e o algoritmo **BFS** é que o **DFS** explora um ramo inteiro do grafo antes de retroceder e visitar outro ramo, enquanto o BFS explora todos os vértices a uma determinada distância do vértice inicial antes de passar para o próximo nível de distância.
	
</div>

<p align="center">
<img src="imgs/dfs.png" width="350"/> 
</p>
<p align="center">
<em>Imagem 3: Busca em Profundidade.</em>
</p>

# Solução do Problema

## Random

<div align="justify">

Em resumo, os três tipos de labirintos apresentam abordagens diferentes para a criação e resolução de labirintos que permitem movimentos nas direções direita, esquerda, cima e baixo.

Esses três tipos de labirintos oferecem experiências diferentes para o jogador. O labirinto Random proporciona uma sensação de descoberta e desafio, o labirinto BFS oferece uma busca otimizada pelo destino e o labirinto DFS cria um senso de exploração e pode levar a soluções não tão eficientes. Cada um desses labirintos tem suas próprias características e desafios, proporcionando diferentes experiências aos jogadores. Abaixo esses modelos serão melhor detalhados.

</div>

<div align="justify">

O código implementa é basicamente o mesmo implementado no trabalho [Labirinto-Recorrente](https://github.com/phpdias/labirinto-recorrente), um algoritmo para gerar e resolver um labirinto aleatório, com algumas adaptações. A função <code>aleatoria</code> gera um labirinto aleatório e a função <code>checkMovimento</code> verifica se um determinado movimento é válido. A lógica principal está em um loop que continua até o jogador alcançar o destino no labirinto. Durante o loop, são feitos movimentos aleatórios e as posições são atualizadas de acordo. Se o jogador encontra um inimigo, o inimigo é removido e o jogador retorna à posição inicial. A quantidade de movimentos é registrada e, ao final, é exibida uma mensagem indicando se o jogador alcançou o destino ou não.
	
</div>

## BFS

## DFS

# Conclusão

# Compilação e Execução 

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo nomeado preferencialmente de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o seguinte formato:
	
- Em sua primeira linha: os valores NxN que serão assumidos pelas matrizes geradas
- Logo em seguida, dispõe-se a matriz com os elementos espaçados, na seguinte ideia:

	- **Passagem livre ( 1 )**; 
	- **Item de dano ('*')**; 
	- **Paredes ('#')**;
	- **Ponto de parada ('?')**.
</p>

<p align="center">
<img src="imgs/exemplo_input.png" width="250"/> 
</p>
<p align="center">
<em>Imagem 4: Exemplo de entrada no formato desejado.</em>
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
