#pragma once
#include "ficheiros.h"

//Estrutura dos carros 
struct Carro {
	string marca = "";
	string modelo = "";
	int dias_em_reparacao = 0;
	int tempo_reparacao_max = 0;
	int ID = 0;
	bool prioritario = 0;
	int custoreparacao = 0;
	Carro* seguinte = NULL;
};



//Funcoes 
bool GerarProbalidades(double probalidade);
Carro *CriarCarro(LinhasFicheiro& marcas, LinhasFicheiro& modelos);
void removercarro(Carro* primeirocarro, int ID);
Carro * adicionarcarro(Carro* listaaadicionar, Carro* car);

