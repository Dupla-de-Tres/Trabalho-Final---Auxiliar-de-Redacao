#include "read.hpp"
#include <iterator>

//foram retirados todos os cout que antecediam as impressoes no arquivo
//para nao encher o terminal

std::string RemoverPontuacao(const std::string& palavra)
{
  std::string resultado;
  std::remove_copy_if(palavra.begin(), palavra.end(), std::back_inserter(resultado), [](char c) { return std::ispunct(c); });
  
  return resultado;
}

std::string toLowercase(const std::string& palavra)
{
  std::string resultado = palavra;
  std::transform(resultado.begin(), resultado.end(), resultado.begin(), [](unsigned char c) { return std::tolower(c); });
  
  return resultado;
}

std::pair<std::vector<std::string>, std::vector<int>> DividirParagrafos(const std::string& text)
{
  std::vector<std::string> paragraphs;
  std::vector<int> lineCounts;
  std::istringstream iss(text);
  std::string line;
  std::string paragraph;
  int lineCount = 0;
  bool newParagraph = true;

  while (std::getline(iss, line))
  {
    if (newParagraph && !line.empty())
    {
      paragraph += line;
      newParagraph = false;
      lineCount++;
    }
    else if (!line.empty())
    {
      paragraph += " " + line;
      lineCount++;
    }
    else if (!paragraph.empty())
    {
      paragraphs.push_back(paragraph);
      lineCounts.push_back(lineCount);
      paragraph.clear();
      lineCount = 0;
      newParagraph = true;
    }
  }

  if (!paragraph.empty())
  {
    paragraphs.push_back(paragraph);
    lineCounts.push_back(lineCount);
  }

  return std::make_pair(paragraphs, lineCounts);
}

std::vector<std::string> DividirFrases(const std::string& paragraph)
{
  std::vector<std::string> sentences;
  std::istringstream iss(paragraph);
  std::string sentence;
  std::string delimiters = ".!?"; // Ponto final, ponto de exclamação e ponto de interrogação como delimitadores

  while (std::getline(iss, sentence))
  {
    size_t pos = 0;
    while ((pos = sentence.find_first_of(delimiters, pos)) != std::string::npos)
    {
      if (pos != 0)
      {
        std::string currentSentence = sentence.substr(0, pos + 1);
        sentences.push_back(currentSentence);
      }
      sentence = sentence.substr(pos + 1);
      pos = 0;
    }

    if (!sentence.empty())
      sentences.push_back(sentence);
  }
    return sentences;
}

void ReadFile()
{
  std::vector<int> comstop, semstop;
  
  std::ifstream file("dataset/input/entrada.txt");
  std::ifstream stopwordsFile("dataset/input/stopwords.txt");
  std::ifstream expressionsFile("dataset/input/expressions.txt");
  std::ofstream ofile("dataset/output/paragrafos.txt");
  std::ofstream o1file("dataset/output/palavras.txt");
  std::ofstream o2file("dataset/output/expstop.txt");

  std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

  std::string stopwordsText((std::istreambuf_iterator<char>(stopwordsFile)), std::istreambuf_iterator<char>());
  
  std::string expressionsText((std::istreambuf_iterator<char>(expressionsFile)), std::istreambuf_iterator<char>());

  std::set<std::string> stopwords;
  std::istringstream stopwordsIss(stopwordsText);
  std::string stopword;
  while (stopwordsIss >> stopword)
    stopwords.insert(toLowercase(stopword));

  std::map<std::string, std::map<int, int>> wordMap;

  std:: pair <std::vector<std::string>, std::vector<int>> paragraphs = DividirParagrafos(text);

  int paragraphStartLine = 1;
  for (size_t i = 0; i < paragraphs.first.size(); ++i)
  {
    std::string& paragraph = paragraphs.first[i];

    std::vector<std::string> sentences = DividirFrases(paragraph);
    int paragraphEndLine = paragraphStartLine + paragraphs.second[i]-1 ;

    ofile << "Parágrafo " << i + 1 << ": Linha inicial: " << paragraphStartLine << ", Linha final: " << paragraphEndLine << std::endl;
    ofile << "Número de sentenças: " << sentences.size() << std::endl;

    int sentenceStartLine = paragraphStartLine;
    for (size_t j = 0; j < sentences.size(); ++j)
    {
      std::string& sentence = sentences[j];

      std::istringstream iss(sentence);
      std::string palavra;
      int wordCountWithStopwords = 0;
      int wordCountWithoutStopwords = 0;

      while (iss >> palavra)
      {
        std::string cleanedWord = RemoverPontuacao(palavra);
        std::string lowercaseWord = toLowercase(cleanedWord);

        wordCountWithStopwords++;

        if (stopwords.find(lowercaseWord) == stopwords.end())
        {
          wordCountWithoutStopwords++;

         std::map<int, int>& lineInfo = wordMap[lowercaseWord];
                lineInfo[sentenceStartLine+j]++;
        }
      }

      comstop.push_back(wordCountWithStopwords);
      semstop.push_back(wordCountWithoutStopwords);
      
      ofile << "Sentença " << j + 1 << ": Número de palavras (com stopwords): " << wordCountWithStopwords << std::endl;
      ofile << "Sentença " << j + 1 << ": Número de palavras (sem stopwords): " << wordCountWithoutStopwords << std::endl;

      sentenceStartLine++;
    }

    paragraphStartLine = paragraphEndLine + 2;
  }

// Imprime as palavras em ordem alfabética com suas ocorrências e linhas
   for (const auto& entry : wordMap)
   {
     o1file << "Palavra: " << entry.first << std::endl;

     for (const auto& lineEntry : entry.second)
     {
            o1file << "  Linha: " << lineEntry.first << ", Ocorrências: ";
            o1file<<lineEntry.second<<std::endl;

      }

            o1file << std::endl;
     }

  std::vector<std::string> expressions;
  std::istringstream expressionsIss(expressionsText);
  std::string expression;
  while (std::getline(expressionsIss, expression))
  {
    if (!expression.empty())
      expressions.push_back(expression);
  }

  for (const std::string& expression : expressions)
  {
    std::istringstream iss(text);
    std::string line;
    int lineNumber = 1;
    while (std::getline(iss, line))
    {
      if (line.find(expression) != std::string::npos)
      {
        o2file << "Expressão: " << expression << ", Linha: " << lineNumber << std::endl;
      }
      lineNumber++;
    }
  }

  int csvalue = 0, ssvalue = 0;
  //variaveis int ix e jx alteradas p/ long unsigned int
  for (long unsigned int ix = 0; ix < comstop.size(); ix++)
    csvalue += comstop[ix];
  for (long unsigned int jx = 0; jx < semstop.size(); jx++)
    ssvalue += semstop[jx];

  std::cout << "\nTotal de palavras com stopwords: " << csvalue << std::endl;
  std::cout << "Total de palavras sem stopwords: " << ssvalue << std::endl;
  o2file << "\nTotal de palavras com stopwords: " << csvalue << std::endl;
  o2file << "Total de palavras sem stopwords: " << ssvalue << std::endl;
}
