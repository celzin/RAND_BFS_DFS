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

<div align="justify">

Em resumo, os três tipos de labirintos apresentam abordagens diferentes para a criação e resolução de labirintos que permitem movimentos nas direções **DIREITA**, **ESQUERDA**, **CIMA** e **BAIXO**.

Esses três tipos de labirintos oferecem experiências diferentes para o jogador. O labirinto **Randômico** proporciona uma sensação de descoberta e desafio, o labirinto **BFS** oferece uma busca otimizada pelo destino e o labirinto **DFS** cria um senso de exploração e pode levar a soluções não tão eficientes. Cada um desses labirintos tem suas próprias características e desafios, proporcionando diferentes experiências aos jogadores. Abaixo esses modelos serão melhor detalhados.

</div>

## Randômico

<div align="justify">

O código implementado é basicamente o mesmo implementado no trabalho [Labirinto-Recorrente](https://github.com/phpdias/labirinto-recorrente), um algoritmo para gerar e resolver um labirinto aleatório, com algumas adaptações. A função <code>aleatoria</code> gera um labirinto aleatório e a função <code>checkMovimento</code> verifica se um determinado movimento é válido. A lógica principal está em um loop que continua até o jogador alcançar o destino no labirinto. Durante o loop, são feitos movimentos aleatórios e as posições são atualizadas de acordo. Se o jogador encontra um inimigo, o inimigo é removido e o jogador retorna à posição inicial. A quantidade de movimentos é registrada e, ao final, é exibida uma mensagem indicando se o jogador alcançou o destino ou não.
	
</div>


### Exemplo Randômico

<p align="center">
<img src="imgs/random_black.gif" width=""/> 
</p>

<p align="center">
<em>Gif 1: Exemplo do labirinto randômico.</em>
</p>

## BFS
- Alterar aqui


### Exemplo **Breadth-First Search (BFS)** ou **Busca em Largura** 

<p align="center">
<img src="imgs/bfs_black.gif" width=""/> 
</p>

<p align="center">
<em>Gif 2: Exemplo do labirinto BFS.</em>
</p>

## DFS
- Alterar aqui

### Exemplo **Depth-First Search (DFS)** ou **Busca em Profundidade**

<p align="center">
<img src="imgs/dfs_black.gif" width=""/> 
</p>

<p align="center">
<em>Gif 3: Exemplo do labirinto DFS.</em>
</p>

# Conclusão

<div align="justify">

Partindo do contexto de um labirinto representado por uma matriz 50x50, buscamos analisar e comparar três modelos de busca: **Randômico**, **BFS** e **DFS**. Á frente exploramos as características de cada modelo em diferentes cenários, desde o melhor caso em que encontram soluções rapidamente, até o pior caso em que podem demorar ou até mesmo falhar em encontrar uma solução ótima. Além disso, abordaremos o caso médio, em que cada modelo se comporta de forma distintiva, a fim de compreender as características particulares para cada modelo.

</div>

### Melhor caso:
<div align="justify">

- **Randômico:** No melhor caso, o modelo Randômico pode encontrar o ponto de parada rapidamente se tiver sorte com suas escolhas aleatórias. No entanto, a probabilidade de encontrar uma solução ótima é baixa, pois não segue uma estratégia específica.
- **BFS:** É um algoritmo completo que procura a solução mais curta em termos de número de movimentos. No melhor caso, se o ponto de parada estiver próximo à posição inicial, o BFS encontrará uma solução ótima em um curto espaço de tempo.
- **DFS:** No melhor caso, se o ponto de parada estiver próximo à posição inicial e a busca seguir em uma direção favorável, o DFS pode encontrar uma solução rapidamente. No entanto, assim como o Randômico, não garante uma solução ótima.

</div>

### Pior caso:

<div align="justify">

- **Randômico:** No pior caso, o modelo Randômico pode ficar preso em um loop infinito ou levar um tempo muito longo para encontrar o ponto de parada, já que suas escolhas são aleatórias e não segue uma estratégia determinística.
- **BFS:** No pior caso, se o ponto de parada estiver localizado em uma área distante da posição inicial e houver muitas paredes no caminho, o BFS pode levar muito tempo para encontrar uma solução, pois explora todos os caminhos possíveis em largura.
- **DFS:** No pior caso, se o ponto de parada estiver localizado em uma área distante da posição inicial e a busca seguir em direções que levam a caminhos sem saída, o DFS pode se perder em profundidade e demorar para encontrar uma solução.

</div>

### Caso médio:

<div align="justify">

- **Randômico:** No caso médio, o modelo Randômico pode encontrar o ponto de parada em um tempo razoável, dependendo da distribuição dos elementos na matriz e da localização do ponto de parada. No entanto, a solução encontrada pode não ser ótima.
- **BFS:** No caso médio, o BFS tem uma boa chance de encontrar uma solução ótima ou próxima disso em um tempo razoável, explorando em largura e encontrando o caminho mais curto.
- **DFS:** No caso médio, o DFS pode encontrar o ponto de parada em um tempo razoável, mas a solução encontrada pode não ser a mais curta. O DFS é mais propenso a seguir caminhos mais profundos antes de retornar e explorar outras alternativas.

Em resumo, o modelo **Randômico** depende muito da sorte e não oferece garantias de encontrar uma solução ótima. O **BFS** é mais eficiente em encontrar soluções ótimas, enquanto o **DFS** pode ser mais rápido em alguns casos, mas não garante uma solução ótima. Dessa forma, compreender as particularidades e limitações de cada algoritmo é fundamental para tomar decisões informadas ao escolher a abordagem mais adequada para a busca em labirintos.

</div>

# Compilação e Execução 

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo nomeado de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o seguinte formato:
	
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
