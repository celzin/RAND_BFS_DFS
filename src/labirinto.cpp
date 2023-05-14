#include "include/labirinto.hpp"

void Labirinto::aleatoria(int **m){
    if(m[0][0] == PAREDE){
        cout << "FIM DE JOGO" << endl;
        return;
    }

    int x = 0; //linha
    int y = 0; //coluna

    srand(time(nullptr));
    cout << "correndo matriz ..." << endl;
    while(m[x][y] != DESTINO){
        int i = (rand() % 3) - 1; // -1 0 1
        int j = (rand() % 3) - 1; // -1 0 1


        if(checkMovimento(m, x, y, i, j)){
            x = x + i;
            y = y + j;

            if(m[x][y] == INIMIGO){
                m[x][y] = 0;
                x = y = 0;
            }
            this->qtd++;
        }
    }
}

bool Labirinto::checkMovimento(int **m, int x, int y, int i, int j){
    if(x + i < 0 || x + i > N - 1) return false;
    if(y + j < 0 || y + j > N - 1) return false;

    if(i == 0){
        if(m[x][y + j] != PAREDE) return true;
    } else if(j == 0){
        if(m[x + i][y] != PAREDE) return true;
    }
    return false;
}

void Labirinto::BFS(int **m){
    int **copia = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++){
        copia[i] = (int *)malloc(sizeof(int) * N);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copia[i][j] = m[i][j];
        }
    }

    int x = 0, y = 0;
    this->qtd = 0;

    int cord_1, cord_2;
    cord_1 = cord_2 = 2;

    queue<pair<int, int>> fila;

    fila.push(make_pair(cord_1, cord_2));

    while(!fila.empty()){
        auto frente = fila.front();
        fila.pop();

        x = frente.first;
        y = frente.second;

        if(m[x][y] == DESTINO){
            printMatriz(copia, x, y);
            cout << "VICTORY" << endl;
            return;
        }

        copia[x][y] = VISITADO;

        if(x + 1 < N){
            if(m[x + 1][y] != PAREDE){
                if(copia[x + 1][y] != VISITADO && copia[x + 1][y] != DESCOBERTO){
                    fila.push(make_pair(x + 1, y));
                    copia[x + 1][y] = DESCOBERTO;
                }
            }
        }

        if(y + 1 < N){
            if(m[x][y + 1] != PAREDE){
                if(copia[x][y + 1] != VISITADO && copia[x][y + 1] != DESCOBERTO){
                    fila.push(make_pair(x, y + 1));
                    copia[x][y + 1] = DESCOBERTO;
                }
            }
        }

        if(x - 1 >= 0){
            if(m[x - 1][y] != PAREDE){
                if(copia[x - 1][y] != VISITADO && copia[x - 1][y] != DESCOBERTO){
                    fila.push(make_pair(x - 1, y));
                    copia[x - 1][y] = DESCOBERTO;
                }
            }
        }

        if(y - 1 >= 0){
            if(m[x][y - 1] != PAREDE){
                if(copia[x][y - 1] != VISITADO && copia[x][y - 1] != DESCOBERTO){
                    fila.push(make_pair(x, y - 1));
                    copia[x][y - 1] = DESCOBERTO;
                }
            }
        }

        printMatriz(copia, x, y);

        if(m[x][y] == INIMIGO){
            m[x][y] = CAMINHO;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    copia[i][j] = m[i][j];
                }
            }
            while(!fila.empty()){
                fila.pop();
            }
            fila.push(make_pair(cord_1, cord_2));
        }

    }
    cout << "JOGO FINALIZADO" << endl;
}

void Labirinto::DFS(int **m){

}

void Labirinto::printMatriz(int **m, int x, int y){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(x == i && y == j){
                cout << AZUL << "X" << RESET << " ";
            } else if(m[i][j] == PAREDE){
                cout << "#" << " ";
            } else if(m[i][j] == VISITADO){
                cout << VERMELHO << "+" << RESET << " ";
            } else if(m[i][j] == DESCOBERTO){
                cout << VERDE << "+" << RESET << " ";
            } else if(m[i][j] == DESTINO){
                cout << AZUL << "?" << RESET << " ";
            } else if(m[i][j] == INIMIGO){
                cout << AMARELO << "*" << RESET << " ";
            } else{
                cout << CINZA << "-" << RESET << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}