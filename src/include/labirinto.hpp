#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP

#include "const.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

#include <ctime>
#include <ratio>
#include <chrono>
#include <thread>

using namespace std;

using namespace std::chrono;

class Labirinto{
private:
    int N, qtd;
    queue<pair<int, int>> fila;
    stack<pair<int, int>> pilha;
    double tempo;
public:
    Labirinto(int N){
        this->N = N;
        this->qtd = 0;
    }

    bool checkMovimento(int **m, int x, int y, int i, int j);
    void aleatoria(int **m);

    void BFS(int **m);
    void DFS(int **m);
    void printMatriz(char *str, int **m, int x, int y);

    void searchCaminho(int **m, int **copia, int x, int y);
    void logs(char *str, int **copia, int x, int y, int linha, int coluna);
    void relatorio(const char *labirintos, double tempo, int qtd_passos);

    int getQtd(){
        return this->qtd;
    }
};

#endif