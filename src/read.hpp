#ifndef READ_HPP
#define READ_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <set>
#include <utility>

std::string RemoverPontuacao(const std::string& palavra);
std::string toLowercase(const std::string& palavra);
std::pair<std::vector<std::string>, std::vector<int>> DividirParagrafos(const std::string& text);
std::vector<std::string> DividirFrases(const std::string& paragraph);

void ReadFile();

#endif