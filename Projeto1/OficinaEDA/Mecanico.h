#pragma once
#include "Ficheiros.h"
struct Mecanico {
	string nome = "";
	string marca = "";
	int preco_reparacao_por_dia = 0;
};

Mecanico CriarMecanico(LinhasFicheiro& marcas);
bool verificarnumero(string n);