#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Arquivo{
public:
    Arquivo(){}
    void readFile(vector<string> &matriz);
    int tokenizarPrimeiraLinha(string text);
    void tokenizar(string text, int **labirinto, int counterLine);
};

#endif
