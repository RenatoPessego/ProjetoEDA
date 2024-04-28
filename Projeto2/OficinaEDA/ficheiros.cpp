#include "Ficheiros.h"


int TamanhoFicheiro(string Nome_Ficheiro) {
    int numero_linhas = 0;
    string line;
    ifstream file(Nome_Ficheiro);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            numero_linhas++;
        }
        file.close();
    }
    return numero_linhas;
}
LinhasFicheiro CarregarFicheirosLista(string Nome_Ficheiro) {

    LinhasFicheiro novo = LinhasFicheiro();

    string* linhas = new string[TamanhoFicheiro(Nome_Ficheiro)];

    string line;

    ifstream file(Nome_Ficheiro);
    if (file.is_open())
    {
        for (int i = 0; i < TamanhoFicheiro(Nome_Ficheiro); i++)
        {
            getline(file, line);
            *(linhas + i) = line;
        }
        file.close();
    }

    novo.tamanho = TamanhoFicheiro(Nome_Ficheiro);
    novo.linhas = linhas;

    return novo;
}

string maiuscula(string str) {
    int tamanho = str.length();
    char* novo = new char[tamanho];
    for (int i = 0; i <= tamanho; i++) {
        novo[i] = toupper(str[i]);
    }
    return novo;
}

string removerespacos(string str) {
    int tamanho = str.length();
    int k = 0;
    char* novo = new char[tamanho];

    for (int i = 0; i <= str.length(); i++) {
        if (str[i] != ' ') {
            novo[k] = str[i];
            k++;
            tamanho--;
        }
    }
    return novo;
}