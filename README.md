# Trabalho-Final---Auxiliar-de-Redacao
Trabalho Final de AEDS I - Auxiliar de Redação

<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<h2>Introdução </h2>

<p> No dia a dia, muitas pessoas têm dificuldades para escrever textos de qualidade, como trabalhos escolares, relatórios ou até mesmo mensagens simples. É importante que os textos sejam claros, bem organizados e fluam de maneira natural. No entanto, nem todo mundo tem facilidade com a escrita ou conhece todas as regras gramaticais e de estilo. Para ajudar nessa situação, está sendo desenvolvido um sistema que irá auxiliar no processo de escrita.  </p>

<h2>Objetivo </h2>

<p> O objetivo é criar uma ferramenta prática e eficiente, que ajude as pessoas a produzir textos melhores. Com esse sistema, será possível contar com recursos que auxiliam na elaboração de textos mais claros e bem estruturados. O objetivo final é capacitar as pessoas a aprimorarem suas habilidades de escrita e se comunicarem de forma mais eficaz.</p>

<p><p>O sistema em questão é um programa escrito em C++ que tem como objetivo processar e analisar um texto. Ele recebe como entrada três arquivos: um arquivo de texto contendo o conteúdo a ser processado, um arquivo de stopwords que contém palavras a serem ignoradas durante o processamento e um arquivo de expressões que contém expressões específicas a serem buscadas no texto.</p>

<h2>Metodologia</h2>

<p>O programa utiliza várias bibliotecas padrão do C++, que são conjuntos de funções e classes já implementadas, para realizar diversas tarefas necessárias no processamento de texto. Essas bibliotecas incluem funcionalidades para manipulação de strings, leitura e gravação de arquivos, manipulação de contêineres de dados (como mapas, vetores e conjuntos) e transformações de caracteres. A utilização dessas bibliotecas permite que a implementação das funcionalidades necessárias no programa se torne mais fácil e intuitiva para o usuário.</p>

<p>Além disso, a estrutura do código se baseia em várias funções auxiliares que desempenham papéis específicos no processamento do texto. Por exemplo, a função "RemoverPontuacao" é responsável por remover os caracteres de pontuação de uma palavra, enquanto a função "toLowercase" converte uma palavra para letras minúsculas. As funções "DividirParagrafos" e "DividirFrases" dividem o texto em parágrafos e sentenças, respectivamente, utilizando a classe "std::istringstream" para fazer essa divisão com base em caracteres específicos.</p>

<p>A função principal do programa é a função "main", que coordena todas as etapas de processamento. Primeiro, ele lê os arquivos de entrada, armazenando o conteúdo em variáveis do tipo string. Em seguida, o programa cria um conjunto de stopwords a partir do arquivo correspondente, convertendo todas as palavras para letras minúsculas. Também é criado um mapa chamado "wordMap", que será usado para armazenar informações sobre as palavras encontradas no texto.</p>

<p>Após a preparação inicial, o texto é dividido em parágrafos, e cada parágrafo é dividido em sentenças. Para cada sentença, as palavras são processadas individualmente. Primeiro, é feita a remoção de pontuação e a conversão para letras minúsculas. Em seguida, é verificado se a palavra é uma stopword, ou seja, uma palavra que deve ser ignorada. As palavras que não são stopwords são adicionadas ao "wordMap", juntamente com informações sobre a linha e a sentença em que ocorrem.</p>

<p>Logo depois do processamento das palavras, o programa exibe as informações armazenadas no "wordMap". Ele mostra as palavras em ordem alfabética, juntamente com suas frequências e as linhas e sentenças em que ocorrem. Em seguida, o programa verifica se há ocorrência de expressões específicas no texto, comparando cada expressão com cada linha. Caso uma expressão seja encontrada em uma linha, essa linha é exibida. </p>

<p>No final do código é realizado a medição do tempo de execução do mesmo, através da função "std::clock"</p>


<h2>Funções </h2>

* ``` void RemoverPontuacao(); ```: Recebe uma string word como entrada e remove toda a pontuação dessa string. A função retorna uma nova string resultante sem a pontuação; 
* ``` void toLowercase() ```: Função que converte todas as strings que estão em letra maiúscula para letra minúscula;
* ``` void DividirParagrafos(); ```: Divide um texto em parágrafos e retorna um vetor de strings contendo os parágrafos individuais.;
* ``` void DividirFrases(); ```: Esta função recebe uma string chamada palavra como entrada e remove toda a pontuação dessa string. A função retorna uma nova string chamada resultado, que contém a palavra sem a pontuação.

<h2>Arquivos</h2>

* ``` main.cpp ```: Arquivo principal do código. Ele recebe o arquivo "" para executar suas funções.
* 


<h2>Etapas e Funcionalidade</h2>

* Lê o conteúdo do arquivo de entrada, stopwords e expressões;
* Cria um conjunto de stopwords para posterior verificação;
* Divide o texto em parágrafos;
* Para cada parágrafo, divide-o em sentenças;
* Para cada sentença, conta o número de palavras com e sem stopwords;
* Armazena as informações das palavras no mapa wordMap, que associa cada palavra a um mapa contendo informações sobre a linha e as ocorrências dessa palavra;
* Imprime as palavras em ordem alfabética, juntamente com suas ocorrências e linhas correspondentes;
* Verifica a ocorrência de cada expressão no texto e imprime a linha correspondente, se encontrada;
* Calcula o total de palavras com e sem stopwords;
* Calcula o tempo total de execução do programa.


<h2>Análise de Complexidade das Funções </h2>

* ``` void RemoverPontuacao(); ```: A complexidade da função é de O(n), onde n é o tamanho da palavra de entrada. Ela é composta apenas de métodos;
  
* ``` void toLowercase() ```: A complexidade da função é de O(n), pelo mesmo motivo da função "RemoverPontuacao". n é o tamanho da palavra de entrada;
  
* ``` void DividirParagrafos(); ```: Supondo que o parágrafo tenha 'n' caracteres e 'm' frases, logo, a complexidade da função é O(n + m), onde 'n' é o tamanho do parágrafo e 'm' é o número de frases resultantes;
  
* ``` void DividirFrases(); ```: Supondo que o texto tenha 'n' caracteres e 'm' linhas, logo, a complexidade da função é O(n + m), onde 'n' é o tamanho do texto e 'm' é o número de linhas.
  
<h2>Exemplo de Resultado</h2>



<h2>Compilação e Execução do Programa</h2>

<p>Através do makefile, é posição utilizar comandos que realizam o processo de compilação e execução do programa. A seguir, temos alguns comandos que podem ser utilizados:</p><br>

* ``` make ```: Realiza a compilação do código por meio do gcc, no qual o resultado vai para a pasta build.</li><br>
* ``` make run ```: Executa o programa armazenado na pasta build após este ser compilado.</li><br>
* ``` make clean ```: Exclui a última compilação feita anteriormente na pasta build.</li><br><br>

<p>Também é possível executar o programa através do site de hospedagem de código, Replit, onde foi realizado a programação do código do "Auxiliar de Redação": <link>https://replit.com/@OsBrabosSoltos/TrabalhoFinal#main.cpp</link></p>



<h2>Autores</h2>

<p>Daniel Couto Fonseca</p>
<p>João Marcos Silva Hess</p>
<p>Victor Ramos de Albuquerque Cabral</p>

