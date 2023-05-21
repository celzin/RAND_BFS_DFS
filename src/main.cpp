#include "include/labirinto.hpp"
#include "include/arquivo.hpp"
#include <string.h>

int main(){
    Arquivo arquivo;

    vector<string> matriz;
    arquivo.readFile(matriz);
    int aux = 0;
    int N = 0;
    int **labirinto;
    int **labirinto1;
    int **labirinto2;
    int counterLine = 0;

    for(string variavel : matriz){
        if(aux == 0){
            aux = 1;
            N = arquivo.tokenizarPrimeiraLinha(variavel);

            labirinto = (int **)malloc(sizeof(int *) * N);
            labirinto1 = (int **)malloc(sizeof(int *) * N);
            labirinto2 = (int **)malloc(sizeof(int *) * N);

            for(int i = 0; i < N; i++){
                labirinto[i] = (int *)malloc(sizeof(int) * N);
                labirinto1[i] = (int *)malloc(sizeof(int) * N);
                labirinto2[i] = (int *)malloc(sizeof(int) * N);
            }
        } else{
            arquivo.tokenizar(variavel, labirinto, counterLine);
            counterLine++;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            labirinto1[i][j] = labirinto[i][j];
            labirinto2[i][j] = labirinto[i][j];
        }
    }

    Labirinto lab(N);

    FILE *file_output = fopen("dataset/output.data", "w");
    fclose(file_output);

    lab.aleatoria(labirinto);
    lab.BFS(labirinto2);
    lab.DFS(labirinto1);

    return 0;
}

