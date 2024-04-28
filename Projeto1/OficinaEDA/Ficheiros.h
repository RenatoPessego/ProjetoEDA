#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>



using namespace std;

struct LinhasFicheiro {
	int tamanho;
	string* linhas;
	string line;
};
int TamanhoFicheiro(string Nome_Ficheiro);
LinhasFicheiro CarregarFicheirosLista(string Nome_Ficheiro);
string maiuscula(string str);
string removerespacos(string str);