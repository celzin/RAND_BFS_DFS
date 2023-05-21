#include "include/arquivo.hpp"
#include "include/const.hpp"

void Arquivo::readFile(vector<string> &matriz){
    ifstream myfile("dataset/input.data");
    string line;

    if(myfile.is_open()){
        while(getline(myfile, line))
            matriz.push_back(line);
        myfile.close();
    } else cout << "Não foi possível abrir o arquivo" << endl;
}

int Arquivo::tokenizarPrimeiraLinha(string text){
    char del = ' ';

    stringstream sstream(text);
    string token;

    while(getline(sstream, token, del))
        return stoi(token);
    return 0;
}

void Arquivo::tokenizar(string text, int **labirinto, int counterLine){
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