#include "include/labirinto.hpp"

void Labirinto::aleatoria(int **m){
    char *str = (char *)malloc(100);
    sprintf(str, "dataset/log_aleatoria.data");

    FILE *file_saida = fopen(str, "w");
    fclose(file_saida);

    if(m[0][0] == PAREDE){
        cout << "FIM DE JOGO" << endl;
        return;
    }

    steady_clock::time_point t1 = steady_clock::now();
    tempo = 0;
    qtd = 0;

    int x = 0; //linha
    int y = 0; //coluna

    srand(time(nullptr));
    //cout << "correndo matriz ..." << endl;
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
            printMatriz(str, m, x, y);
        }
    }
    string name = "Aleatório";
    steady_clock::time_point t2 = steady_clock::now();
    tempo = duration_cast<duration<double>>(t2 - t1).count();
    relatorio(name.c_str(), tempo, qtd);
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
    char *str = (char *)malloc(100);
    sprintf(str, "dataset/log_BFS.data");

    FILE *file_saida = fopen(str, "w");
    fclose(file_saida);

    steady_clock::time_point t1 = steady_clock::now();
    tempo = 0;

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
    cord_1 = cord_2 = 0;

    queue<pair<int, int>> fila;

    fila.push(make_pair(cord_1, cord_2));

    while(!fila.empty()){
        qtd++;
        auto frente = fila.front();
        fila.pop();

        x = frente.first;
        y = frente.second;

        if(m[x][y] == DESTINO){
            printMatriz(str, copia, x, y);
            cout << "VICTORY" << endl;
            string str = "BFS";
            steady_clock::time_point t2 = steady_clock::now();
            tempo = duration_cast<duration<double>>(t2 - t1).count();
            relatorio(str.c_str(), tempo, qtd);
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

        //system("clear");
        printMatriz(str, copia, x, y);
        //system("read -p \"\nPressione enter para continuar...\" continue");

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

void Labirinto::searchCaminho(int **m, int **copia, int x, int y){

    if(x + 1 < N){ //PARA BAIXO
        if(m[x + 1][y] != PAREDE){
            if(copia[x + 1][y] != VISITADO && copia[x + 1][y] != DESCOBERTO){
                fila.push(make_pair(x + 1, y));
                pilha.push(make_pair(x, y));
                copia[x + 1][y] = DESCOBERTO;
                return;
            }
        }
    }

    if(y + 1 < N){ //PARA DIREITA
        if(m[x][y + 1] != PAREDE){
            if(copia[x][y + 1] != VISITADO && copia[x][y + 1] != DESCOBERTO){
                fila.push(make_pair(x, y + 1));
                pilha.push(make_pair(x, y));
                copia[x][y + 1] = DESCOBERTO;
                return;
            }
        }
    }

    if(x - 1 >= 0){ //PARA CIMA
        if(m[x - 1][y] != PAREDE){
            if(copia[x - 1][y] != VISITADO && copia[x - 1][y] != DESCOBERTO){
                fila.push(make_pair(x - 1, y));
                pilha.push(make_pair(x, y));
                copia[x - 1][y] = DESCOBERTO;
                return;
            }
        }
    }

    if(y - 1 >= 0){ //PARA ESQUERDA
        if(m[x][y - 1] != PAREDE){
            if(copia[x][y - 1] != VISITADO && copia[x][y - 1] != DESCOBERTO){
                fila.push(make_pair(x, y - 1));
                pilha.push(make_pair(x, y));
                copia[x][y - 1] = DESCOBERTO;
                return;
            }
        }
    }

    if(!pilha.empty()){
        auto frente = pilha.top();
        pilha.pop();
        fila.push(frente);
    }
}

void Labirinto::DFS(int **m){
    char *str = (char *)malloc(100);
    sprintf(str, "dataset/log_DFS.data");

    FILE *file_saida = fopen(str, "w");
    fclose(file_saida);

    steady_clock::time_point t1 = steady_clock::now();
    tempo = 0;

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
    cord_1 = cord_2 = 0;

    while(!fila.empty()) fila.pop();
    while(!pilha.empty()) pilha.pop();

    fila.push(make_pair(cord_1, cord_2));

    while(!fila.empty()){
        qtd++;
        auto frente = fila.front();
        fila.pop();

        x = frente.first;
        y = frente.second;

        if(m[x][y] == DESTINO){
            printMatriz(str, copia, x, y);
            cout << "VICTORY" << endl;
            string str = "DFS";
            steady_clock::time_point t2 = steady_clock::now();
            tempo = duration_cast<duration<double>>(t2 - t1).count();
            relatorio(str.c_str(), tempo, qtd);
            return;
        }

        copia[x][y] = VISITADO;

        searchCaminho(m, copia, x, y);

        //system("clear");
        printMatriz(str, copia, x, y);
        //system("read -p \"\nPressione enter para continuar...\" continue");

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

void Labirinto::logs(char *str, int **copia, int x, int y, int linha, int coluna){
    FILE *file = fopen(str, "a");

    if(file == NULL){
        printf(VERMELHO "Não foi possível abrir o arquivo\n" RESET);
    } else{
        fprintf(file, "==========================\n");
        //fprintf(file, "Matriz atual: %d\n", m->numMatriz);
        fprintf(file, "M[%d][%d]\n", linha, coluna);
        fprintf(file, "Posição: [x = %d]; [y = %d]\n\n", x, y);

        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                if(x == i && y == j){
                    fprintf(file, " >X< ");
                } else if(copia[i][j] == PAREDE){
                    fprintf(file, "[ # ]");
                } else if(copia[i][j] == VISITADO){
                    fprintf(file, "[ - ]");
                } else if(copia[i][j] == DESCOBERTO){
                    fprintf(file, "[ + ]");
                } else if(copia[i][j] == DESTINO){
                    fprintf(file, "[ ? ]");
                } else if(copia[i][j] == INIMIGO){
                    fprintf(file, "[ * ]");
                } else{
                    fprintf(file, "[ 1 ]");
                }

            }
            fprintf(file, "\n");
        }
        fprintf(file, "\n");
    }
    fclose(file);
    //free(str);
}

void Labirinto::relatorio(const char *labirintos, double tempo, int qtd_passos){
    char *str = (char *)malloc(100);
    sprintf(str, "dataset/output.data");

    FILE *file = fopen(str, "a");

    if(file == NULL){
        printf(VERMELHO "Não foi possível abrir o arquivo\n" RESET);
    } else{
        fprintf(file, "==========================\n");
        fprintf(file, "\nTipo de Labirinto: %s\n", labirintos);
        fprintf(file, "Tempo de execução: %lf segundos\n", tempo);
        fprintf(file, "Quantidade de passos: %d\n", qtd_passos);
    }
    fclose(file);
    //free(str);
}

void Labirinto::printMatriz(char *str, int **m, int x, int y){
    /*for(int i = 0; i < N; i++){
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
    cout << endl;*/

    logs(str, m, x, y, N, N);
}