#include "include/labirinto.hpp"

void readFile(vector<string> &matriz){
    ifstream myfile("dataset/input.data");
    string line;

    if(myfile.is_open()){
        while(getline(myfile, line))
            matriz.push_back(line);
        myfile.close();
    } else cout << "Não foi possível abrir o arquivo" << endl;
}

int tokenizarPrimeiraLinha(string text){
    char del = ' ';

    stringstream sstream(text);
    string token;

    while(getline(sstream, token, del))
        return stoi(token);
    return 0;
}

void tokenizar(string text, int **labirinto, int counterLine){
    char del = ' ';
    int coluna = 0;

    stringstream sstream(text);
    string token;
    int valor = 0;

    while(getline(sstream, token, del)){

        if(token.compare("*") == 0){
            valor = INIMIGO;
        } else if(token.compare("#") == 0){
            valor = PAREDE;
        } else if(token.compare("?") == 0){
            valor = DESTINO;
        } else{
            valor = CAMINHO;
        }

        labirinto[counterLine][coluna] = valor;
        coluna++;
    }
}

int main(){
    vector<string> matriz;
    readFile(matriz);
    int aux = 0;
    int N = 0;
    int **labirinto;
    int counterLine = 0;

    for(string variavel : matriz){
        if(aux == 0){
            aux = 1;
            N = tokenizarPrimeiraLinha(variavel);

            labirinto = (int **)malloc(sizeof(int *) * N);
            for(int i = 0; i < N; i++){
                labirinto[i] = (int *)malloc(sizeof(int) * N);
            }
        } else{
            tokenizar(variavel, labirinto, counterLine);
            counterLine++;
        }
    }

    Labirinto lab(N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << labirinto[i][j] << " ";
        }
        cout << endl;
    }

    lab.BFS(labirinto);

    return 0;
}

