#ifndef LABIRINTO_HPP
#define LABIRINTO_HPP

#include "const.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Labirinto{
private:
    int N, qtd;
public:
    Labirinto(int N){
        this->N = N;
        this->qtd = 0;
        cout << N << endl;
    }

    bool checkMovimento(int **m, int x, int y, int i, int j);
    void aleatoria(int **m);

    void BFS(int **m);
    void DFS(int **m);
    void printMatriz(int **m, int x, int y);
    void reset(int **, int **);

    int getQtd(){
        return this->qtd;
    }
};

#endif