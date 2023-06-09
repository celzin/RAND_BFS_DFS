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
	
- <code>('1')</code>: **Passagem livre**; 
- <code>('*')</code>: **Item de dano**; 
- <code>('#')</code>: **Paredes**;
- <code>('?')</code>: **Ponto de parada** --> colocado **aleatoriamente** na matriz;

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

# O que é BFS?
<div align="justify">
	
**Breadth-First Search (BFS)** ou **Busca em Largura**, é um algoritmo de busca em grafo que começa a explorar a partir do vértice raiz e visita todos os seus vizinhos primeiro, antes de se mover para o próximo nível de vizinhos. Em outras palavras, ele explora todos os vértices a uma distância "d" antes de explorar qualquer vértice a uma distância "d+1".
	
É um método para percorrer todos os vértices de um grafo, visitando todos os vértices a uma determinada distância antes de passar para o próximo nível de distância. Ele começa a partir de um vértice inicial (também chamado de raiz) e explora todos os vértices que estão a uma distância de um passo da raiz antes de passar para os vértices que estão a uma distância de dois passos da raiz, e assim por diante.
	
<p align="center">
<img src="imgs/bfs.png" width="350"/> 
</p>
<p align="center">
<em>Imagem 2: Busca em Largura.</em>
</p>
	
</div>


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

## Solução do Problema

<div align="justify">

Em resumo, os três tipos de labirintos apresentam abordagens diferentes para a criação e resolução de labirintos que permitem movimentos nas direções **DIREITA**, **ESQUERDA**, **CIMA** e **BAIXO**.

Esses três tipos de labirintos oferecem experiências diferentes para o jogador. O labirinto **Randômico** proporciona uma sensação de descoberta e desafio, o labirinto **BFS** oferece uma busca otimizada pelo destino e o labirinto **DFS** cria um senso de exploração e pode levar a soluções não tão eficientes. Cada um desses labirintos tem suas próprias características e desafios, proporcionando diferentes experiências aos jogadores. Abaixo esses modelos serão melhor detalhados.

</div>

## Randômico

<div align="justify">

O código implementado é basicamente o mesmo implementado no trabalho [Labirinto-Recorrente](https://github.com/phpdias/labirinto-recorrente), um algoritmo para gerar e resolver um labirinto aleatório, com algumas adaptações. A função [<code>aleatoria</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/src/labirinto.cpp#L3) gera um labirinto aleatório e a função [<code>checkMovimento</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/src/labirinto.cpp#L54) verifica se um determinado movimento é válido. A lógica principal está em um loop que continua até o jogador alcançar o destino no labirinto. Durante o loop, são feitos movimentos aleatórios e as posições são atualizadas de acordo. Se o jogador encontra um inimigo, o inimigo é removido e o jogador retorna à posição inicial. A quantidade de movimentos é registrada e, ao final, é exibida uma mensagem indicando se o jogador alcançou o destino ou não.
	
</div>

<br>
<p align="center">
<img src="imgs/random_black.gif" width="650"/> 
</p>
<p align="center">
<em>Gif 1: Exemplo do labirinto randômico executando.</em>
</p>

## BFS

<div align="justify">
	
O código implementado parte da função [<code>BFS</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/src/labirinto.cpp#L66), a qual recebe uma matriz m como entrada, que representa o labirinto a ser resolvido. A função inicia abrindo um arquivo de log vazio para registrar informações detalhadas sobre o percurso realizado. Em seguida, a função cria uma **'matriz copia'** como uma cópia do labirinto original **'m'**. Essa cópia será usada para marcar os caminhos visitados e explorados durante a busca em largura. A função inicializa as variáveis **'x'** e **'y'** com **0**, representando as coordenadas atuais no labirinto.

Ademais, uma **fila** <code>(fila)</code> é criada para armazenar as coordenadas a serem exploradas. A função começa adicionando as coordenadas iniciais <code>(cord_1, cord_2)</code> à **fila** usando <code>fila.push(make_pair(cord_1, cord_2))</code>. Nesse contexto, o loop principal é executado enquanto a **fila** não estiver vazia. Dentro do loop, a função verifica se a coordenada atual <code>(x, y)</code> é o destino. Se for o caso, o labirinto é considerado resolvido. Caso contrário, a função marca a coordenada atual como visitada, atualiza a matriz copia para refletir esse estado e verifica as coordenadas vizinhas para adicionar à **fila**.

As coordenadas vizinhas são verificadas uma por uma. Se uma coordenada vizinha não for uma parede, e não tiver sido visitada ou descoberta anteriormente, ela é adicionada à **fila** e marcada como descoberta. O mesmo procedimento é repetido para as coordenadas vizinhas nas direções acima, abaixo e à esquerda. Após explorar todas as coordenadas vizinhas da atual, o labirinto é impresso chamando a função <code>printMatriz</code> e o processo se repete até que o destino seja encontrado ou até que todas as coordenadas possíveis sejam exploradas. Se uma coordenada contiver um inimigo, o labirinto e a **fila** são reinicializados para explorar novamente a partir das coordenadas iniciais.

Ao final do algoritmo, o tempo de execução é calculado usando a biblioteca [**chrono**](https://learn.microsoft.com/pt-br/cpp/standard-library/chrono?view=msvc-170) juntamente com o número de passos realizados registrado em um relatório chamando a função <code>relatorio</code>. De modo geral, o código implementa uma busca em largura para resolver um labirinto, utiliza uma matriz de cópia para rastrear o progresso da busca e uma **fila** para explorar as coordenadas do labirinto. Assim, durante a busca, o labirinto é impresso e o tempo de execução e o número de passos são registrados.
	
</div>

<br>
<p align="center">
<img src="imgs/bfs_black.gif" width="650"/> 
</p>
<p align="center">
<em>Gif 2: Exemplo do labirinto BFS executando.</em>
</p>

## DFS

<div align="justify">

O código apresentado contém a função [<code>DFS</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/src/labirinto.cpp#L229) e a função auxiliar [<code>searchCaminho</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/src/labirinto.cpp#L176) para resolver um labirinto. A função <code>DFS</code> recebe uma matriz **'m'** como entrada, representando o labirinto, e executa a busca em profundidade para encontrar o caminho até o destino. Da mesma forma apresentada no modelo BFS, a função começa criando um arquivo de log vazio e inicializando a **'matriz copia'** como uma cópia do labirinto original **'m'**. Em seguida, as variáveis **'x'** e **'y'** são inicializadas como 0, representando as coordenadas atuais no labirinto, e por fim uma variável recebe a contagem de passos. 

Ademais a função também cria uma **fila** <code>(fila)</code> e uma **pilha** <code>(pilha)</code> para armazenar as coordenadas a serem exploradas durante a busca. As **filas** são inicializadas com as coordenadas iniciais <code>(cord_1, cord_2)</code>. Já dentro do loop principal, a função verifica se a coordenada atual <code>(x, y)</code> é o destino. Se for o caso, o labirinto é considerado resolvido. Caso contrário, a função marca a coordenada atual como visitada, chama a função <code>searchCaminho</code> para explorar as coordenadas vizinhas disponíveis e atualiza a matriz copia para refletir esse estado.

Á frente, temos a função <code>searchCaminho</code> é responsável por verificar as coordenadas vizinhas nas quatro direções cardeais. Ela verifica se as coordenadas vizinhas não são paredes, não foram visitadas ou descobertas anteriormente e as adiciona à **fila** <code>fila</code> e à **pilha** <code>pilha</code>. Se não houver mais coordenadas disponíveis na **pilha**, a função retorna ao loop principal para explorar outras opções.

A função imprime o labirinto chamando a função <code>printMatriz</code> e, caso a coordenada atual contenha um inimigo, o labirinto e a **fila** são reinicializados para explorar novamente a partir das coordenadas iniciais. Se o destino não for encontrado, a mensagem de finalização de execução é exibida. Dessa forma, de modo geral o código implementa a busca em profundidade (DFS) para resolver um labirinto, utiliza uma matriz de cópia para rastrear o progresso da busca, uma **fila** para explorar as coordenadas e uma **pilha** para voltar às coordenadas anteriores. Durante a busca, o labirinto é impresso e o tempo de execução e o número de passos são registrados.
	
</div>

<br>
<p align="center">
<img src="imgs/dfs_black.gif" width="650"/> 
</p>
<p align="center">
<em>Gif 3: Exemplo do labirinto DFS executando.</em>
</p>

# Experimentação

<div align="justify">
	
Nesta seção, apresentamos os resultados de experimentos envolvendo três tipos de algoritmos de busca: **Randômico**, **BFS** e **DFS**. O objetivo dos experimentos é comparar o desempenho e a eficácia desses algoritmos em um mesmo tipo de entrada, utilizando uma máquina com especificações definidas.

Os experimentos foram conduzidos em uma máquina com as seguintes especificações:

- Processador: Ryzen 5 5500;
- Memória RAM: 8 GB DDR4;
- Sistema Operacional: Ubuntu Linux;
- Linguagem de Programação: C++.

Para cada algoritmo (**Randômico**, **BFS** e **DFS**), foram executadas 10 iterações utilizando a mesma entrada [<code>inputa.data</code>](https://github.com/celzin/RAND_BFS_DFS/blob/main/imgs/input.data). A entrada consiste em um labirinto representado por uma matriz 50x50, no qual estão presentes os 4 tipos elementos apresentados anteriormente('1', '*', '#', '?'). Essa entrada foi mantida constante em todos os experimentos para garantir a comparabilidade dos resultados. Durante cada iteração, o tempo de execução do algoritmo, o caminho percorrido e a solução encontrada (caso tenha sido encontrada) foram registrados. Os resultados obtidos nos experimentos foram analisados com auxílio da tabela abaixo.

</div>

<table align="center">
  <tr>
    <th align="center">Medições</th>
    <th align="center">Random (tempo em segundos)</th>
    <th align="center">BFS (tempo em segundos)</th>
    <th align="center">DFS (tempo em segundos)</th>
  </tr>
  <tr>
    <td align="center">1</td>
    <td align="center">66.92</td>
    <td align="center">17.45</td>
    <td align="center">0.94</td>
  </tr>
  <tr>
    <td align="center">2</td>
    <td align="center">79.45</td>
    <td align="center">16.79</td>
    <td align="center">1.30</td>
  </tr>
  <tr>
    <td align="center">3</td>
    <td align="center">80.70</td>
    <td align="center">17.74</td>
    <td align="center">0.86</td>
  </tr>
  <tr>
    <td align="center">4</td>
    <td align="center">75.85</td>
    <td align="center">16.59</td>
    <td align="center">0.85</td>
  </tr>
  <tr>
    <td align="center">5</td>
    <td align="center">63.59</td>
    <td align="center">16.33</td>
    <td align="center">0.83</td>
  </tr>
  <tr>
    <td align="center">6</td>
    <td align="center">62.41</td>
    <td align="center">16.18</td>
    <td align="center">0.86</td>
  </tr>
  <tr>
    <td align="center">7</td>
    <td align="center">65.44</td>
    <td align="center">16.57</td>
    <td align="center">0.87</td>
  </tr>
  <tr>
    <td align="center">8</td>
    <td align="center">88.21</td>
    <td align="center">16.92</td>
    <td align="center">0.86</td>
  </tr>
  <tr>
    <td align="center">9</td>
    <td align="center">78.54</td>
    <td align="center">16.49</td>
    <td align="center">0.86</td>
  </tr>
  <tr>
    <td align="center">10</td>
    <td align="center">80.60</td>
    <td align="center">16.76</td>
    <td align="center">0.85</td>
  </tr>
  <tr>
    <td align="center">Média</td>
    <td align="center">74.17</td>
    <td align="center">16.75</td>
    <td align="center">0.91</td>
  </tr>
  <tr>
    <td align="center">Desvio Padrão</td>
    <td align="center">8.88</td>
    <td align="center">0.45</td>
    <td align="center">0.14</td>
  </tr>
</table>

<div align="justify">
	
Em resumo, com base nos dados fornecidos, podemos dizer que o algoritmo DFS apresentou o menor tempo médio de execução (0,91), seguido pelo algoritmo BFS (16,75) e, por fim, o algoritmo Random (74,17). Além disso, o algoritmo DFS apresentou a menor variabilidade nos tempos de execução, indicada pelo menor desvio padrão (0,14), enquanto o algoritmo Random apresentou a maior variabilidade, com um desvio padrão mais alto (8,88). Isso sugere que o algoritmo DFS pode ser mais consistente e previsível em termos de tempo de execução em comparação com os outros dois algoritmos no cenário da entrada fornecida.

</div>
	
# Conclusão

<div align="justify">

Partindo do contexto de um labirinto representado por uma matriz 50x50, buscamos analisar e comparar três modelos de busca: **Randômico**, **BFS** e **DFS**. Á frente exploramos as características de cada modelo em diferentes cenários, desde o melhor caso em que encontram soluções rapidamente, até o pior caso em que podem demorar ou até mesmo falhar em encontrar uma solução ótima. Além disso, abordaremos o caso médio, em que cada modelo se comporta de forma distintiva, a fim de compreender as características particulares para cada modelo.

</div>

### Melhor caso:
<div align="justify">

- **Randômico:** pode encontrar o ponto de parada rapidamente se tiver sorte com suas escolhas aleatórias. No entanto, a probabilidade de encontrar uma solução ótima é baixa, pois não segue uma estratégia específica.
- **BFS:** procura a solução mais curta em termos de número de movimentos. No melhor caso, se o ponto de parada estiver próximo à posição inicial, o BFS encontrará uma solução ótima em um curto espaço de tempo.
- **DFS:** se o ponto de parada, a dispósição de paredes for propícia para que a busca siga em uma direção favorável, o DFS pode encontrar uma solução rapidamente.

</div>

### Pior caso:

<div align="justify">

- **Randômico:** pode ficar preso em um loop infinito ou levar um tempo muito longo para encontrar o ponto de parada, já que suas escolhas são aleatórias e não segue uma estratégia determinística.
- **BFS:** se o ponto de parada estiver localizado em uma área distante da posição inicial e houver muitas paredes no caminho, o BFS pode levar muito tempo para encontrar uma solução, pois explora todos os caminhos possíveis em largura.
- **DFS:** se o ponto de parada estiver localizado em uma área distante da posição inicial e a busca seguir em direções que levam a caminhos sem saída, o DFS pode se perder em profundidade e demorar para encontrar uma solução.

</div>

### Caso médio:

<div align="justify">

- **Randômico:** pode encontrar o ponto de parada em um tempo razoável, dependendo da distribuição dos elementos na matriz e da localização do ponto de parada. No entanto, a solução encontrada pode não ser ótima.
- **BFS:** possui uma boa chance de encontrar uma solução ótima ou próxima disso em um tempo razoável, explorando em largura e encontrando o caminho mais curto.
- **DFS:** pode encontrar o ponto de parada em um tempo razoável, mas a solução encontrada pode não ser a mais curta. O DFS é mais propenso a seguir caminhos mais profundos antes de retornar e explorar outras alternativas.

Em resumo, o modelo **Randômico** depende muito da sorte e não oferece garantias de encontrar uma solução razoável. O **BFS** é mais eficiente em encontrar soluções ótimas, enquanto o **DFS** pode ser mais rápido em alguns casos, podendo também garantir uma solução ótima. Dessa forma, compreender as particularidades e limitações de cada algoritmo é fundamental para tomar decisões informadas ao escolher a abordagem mais adequada para a busca em labirintos.

	
Para algumas informações extras, acesse a [Wiki](https://github.com/celzin/RAND_BFS_DFS/wiki) do projeto.
	
</div>

# Compilação e Execução 

<p align="justify">
Primeiramente, para o correto funcionamento do programa é necessário incluir um arquivo nomeado de <code>input.data</code> dentro da pasta <code>dataset</code>, devendo seguir o seguinte formato:
	
- Em sua primeira linha: os valores NxN que serão assumidos pelas matrizes geradas
- Logo em seguida, dispõe-se a matriz com os elementos espaçados, na seguinte ideia:

	- <code>('1')</code>: **Passagem livre**; 
	- <code>('*')</code>: **Item de dano**; 
	- <code>('#')</code>: **Paredes**;
	- <code>('?')</code>: **Ponto de parada**.
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
|  Eduardo               | <a href="https://t.me/"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>                                       			       |

</div>
