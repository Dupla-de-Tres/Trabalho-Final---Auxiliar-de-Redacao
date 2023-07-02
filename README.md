# Trabalho-Final---Auxiliar-de-Redacao
Trabalho Final de AEDS I - Auxiliar de Redação

<h2>Introdução </h2>

<p> No dia a dia, muitas pessoas têm dificuldades para escrever textos de qualidade, como trabalhos escolares, relatórios ou até mesmo mensagens simples. É importante que os textos sejam claros, bem organizados e fluam de maneira natural. No entanto, nem todo mundo tem facilidade com a escrita ou conhece todas as regras gramaticais e de estilo. Para ajudar nessa situação, está sendo desenvolvido um sistema que irá auxiliar no processo de escrita.  </p>

<h2>Objetivo </h2>

<p> O objetivo é criar uma ferramenta prática e eficiente, que ajude as pessoas a produzir textos melhores. Com esse sistema, será possível contar com recursos que auxiliam na elaboração de textos mais claros e bem estruturados. O objetivo final é capacitar as pessoas a aprimorarem suas habilidades de escrita e se comunicarem de forma mais eficaz.</p>



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

* ``` void RemoverPontuacao(); ```: O(n);
  
* ``` void toLowercase() ```: O(n);
  
* ``` void DividirParagrafos(); ```: Em seguida, a função std::getline é chamada para cada linha do texto. Ela percorre o texto uma vez, buscando as quebras de linha e dividindo-o em parágrafos. Portanto, a complexidade dessa parte é O(m). A função push_back é chamada para adicionar cada parágrafo ao vetor paragraphs. Como existem m parágrafos, a complexidade total dessa operação é O(m). Assim, a complexidade total da função DividirParagrafos é O(n + m), onde n é o tamanho da string de entrada e m é o número de linhas presentes no texto;
  
* ``` void DividirFrases(); ```: O(n + m);
