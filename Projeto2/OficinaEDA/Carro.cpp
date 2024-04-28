#include "Carro.h"

bool GerarProbalidades(double probalidade) {
	bool probalidade_final = rand() < (probalidade * (RAND_MAX + 1.0));
	return probalidade_final;
} 

Carro* CriarCarro(LinhasFicheiro& marcas, LinhasFicheiro& modelos) {
	Carro* novo_carro = new Carro;
	novo_carro->marca = marcas.linhas[rand() % marcas.tamanho];
	novo_carro->modelo = modelos.linhas[rand() % modelos.tamanho];
	novo_carro->ID = 0;
	novo_carro->tempo_reparacao_max = 2 + (rand() % 3);
	novo_carro->dias_em_reparacao = 0;
	novo_carro->prioritario = GerarProbalidades(0.05);
	novo_carro->custoreparacao = 0;
	novo_carro->seguinte = NULL;
	return novo_carro;
}


void removercarro(Carro* primeirocarro, int ID) {
	Carro* primeirocarro2 = primeirocarro;
	Carro* aux = primeirocarro2;
	Carro* novoprimeirocarro = new Carro;

	if (aux == NULL) {
		return;
	}
	else if (aux != NULL && aux->ID != ID) {
		novoprimeirocarro = aux;
		aux = aux->seguinte;
	}
	else if (aux != NULL && aux->ID == ID) {
		novoprimeirocarro = aux->seguinte;
		aux = aux->seguinte;

		if (aux != NULL) {
			aux = aux->seguinte;

		}
	}
	Carro* final = novoprimeirocarro;
	while (aux != NULL) {
		if (aux->ID == ID) {
			aux = aux->seguinte;
		}
		novoprimeirocarro->seguinte = aux;
		novoprimeirocarro = novoprimeirocarro->seguinte;
		if (aux != NULL) {
			aux = aux->seguinte;
		}
	}
	primeirocarro = final;
}


Carro * adicionarcarro(Carro* listaaadicionar, Carro* car) {
	Carro* primeirocarro = listaaadicionar;
	Carro* aux = primeirocarro;
	Carro* final = aux;
	Carro* novo = car;
	if (aux == NULL) {
		aux = novo;
	}
	else {
		while (aux  -> seguinte != NULL) {
			aux = aux->seguinte;
		}
		aux ->seguinte = novo;
	}
	return final;

}
